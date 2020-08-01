#include "Bot.h"
//private
bool Bot::checkTarget1(Unit& target) {
	bool temp;
	switch (getTurnUnit()) {
	case turn_id::right: {
		(_directionPriority) ? setTurnUnit(turn_id::top): setTurnUnit(turn_id::bottom);
		temp = checkCollision(target, false);
		setTurnUnit(turn_id::right);
		return ((getCoord().X < target.getCoord().X || temp));
	}
	case turn_id::bottom: {
		(_directionPriority) ? setTurnUnit(turn_id::right) : setTurnUnit(turn_id::left);
		temp = checkCollision(target, false);
		setTurnUnit(turn_id::bottom);
		return ((getCoord().Y < target.getCoord().Y) || temp);
	}
	case turn_id::left: {
		(_directionPriority) ? setTurnUnit(turn_id::bottom) : setTurnUnit(turn_id::top);
		temp = checkCollision(target, false);
		setTurnUnit(turn_id::left);
		return ((getCoord().X > target.getCoord().X) || temp);
	}
	case turn_id::top: {
		(_directionPriority) ? setTurnUnit(turn_id::left) : setTurnUnit(turn_id::right);
		temp = checkCollision(target, false);
		setTurnUnit(turn_id::top);
		return ((getCoord().Y > target.getCoord().Y) || temp);
	}
	}
}
bool Bot::checkTarget2(Unit& target) {
	int range = (target.getId() != back_id::redBase_id &&
		target.getId() != back_id::blueBase_id) ? 25 : 140;
	switch (getTurnUnit()) {
	case turn_id::right: {
		return (getCoord().X < target.getCoord().X - 140 || getCoord().Y > target.getCoord().Y + range ||
			getCoord().Y < target.getCoord().Y - 25);
	}
	case turn_id::bottom: {
		return (getCoord().Y < target.getCoord().Y - 140 || getCoord().X > target.getCoord().X + 25 ||
			getCoord().X < target.getCoord().X - 25);
	}
	case turn_id::left: {
		return (getCoord().X > target.getCoord().X + 190 || getCoord().Y > target.getCoord().Y + range ||
			getCoord().Y < target.getCoord().Y - 25);
	}
	case turn_id::top: {
		return (getCoord().Y > target.getCoord().Y + 190 || getCoord().X > target.getCoord().X + 25 ||
			getCoord().X < target.getCoord().X - 25);
	}
	}
}
bool Bot::checkCollision(Unit& target, bool flag) {
	bool collision = false;
	if (flag) {
		for (int i = getSpeed(); i > 0; i -= 2) {
			collision = false;

			setPosition(i, true);
			if (!checkFrontWay(target, i)) {
				setPosition(i, false);
				collision = true;
			}
			if (collision == false)break;
		}
	}
	else {
		if (!checkFrontWayExtra(target, getSpeed())) {
			collision = true;
		}
	}
	return collision;
}
bool Bot::checkFrontWay(Unit& target, int step) {
	int tempRoadEnd = (getId() == back_id::ally_id) ? back_id::enemyRoadEnd_id : back_id::allyRoadEnd_id;
	for (int i = 0; i < getMap()->getUnitPerim(); i++) {
		int tempId1 = 0, tempId2 = 0, indexRow = 0, indexColumn = 0, position = 0;
		look(indexRow, indexColumn, position, step, i);
		if (getId() == back_id::ally_id) {
			tempId1 = back_id::enemyTop_id;
			tempId2 = back_id::enemyBottom_id;
		}
		else if (getId() == back_id::enemyTop_id) {
			tempId1 = back_id::ally_id;
			tempId2 = back_id::enemyBottom_id;
		}
		else {
			tempId1 = back_id::ally_id;
			tempId2 = back_id::enemyTop_id;
		}
		if (position == back_id::wall_id ||
			position == back_id::player_id ||
			(position == tempId1) ||
			(position == tempId2) ||
			position == back_id::roadEnd_id ||
			position == tempRoadEnd) return false;
	}
	return true;
}
bool Bot::checkFrontWayExtra(Unit& target,int step) {
	int tempRoadEnd = (getId() == back_id::ally_id) ? back_id::enemyRoadEnd_id : back_id::allyRoadEnd_id;
	for (int i = 0; i < getMap()->getUnitPerim(); i++) {
		int tempId1 = 0, tempId2 = 0, indexRow = 0, indexColumn = 0, position = 0;
		look(indexRow, indexColumn, position, step, i);
		if (getId() == back_id::ally_id) {
			tempId1 = back_id::enemyTop_id;
			tempId2 = back_id::enemyBottom_id;
		}
		else if (getId() == back_id::enemyTop_id) {
			tempId1 = back_id::ally_id;
			tempId2 = back_id::enemyBottom_id;
		}
		else {
			tempId1 = back_id::ally_id;
			tempId2 = back_id::enemyTop_id;
		}
		if (position == back_id::wall_id ||
			position == back_id::player_id ||
			(position == tempId1 && position != target.getId()) ||
			(position == tempId2 && position != target.getId()) ||
			position == back_id::roadEnd_id ||
			position == tempRoadEnd) return false;
	}
	return true;
}
Unit* Bot::checkHit(Unit* target1, Unit* target2, Unit* target3) {
	if (getBullet()->hit() == target1->getId()) return target1;
	if (getBullet()->hit() == target2->getId()) return target2;
	if (getBullet()->hit() == target3->getId()) return target3;
	return nullptr;
}
//public
Bot::Bot(int model, int health, int armor, int speed, int shotPower,
	int shotDistance, int respawnTime) :
	Unit(model, health, armor, speed, shotPower, shotDistance, respawnTime),
	_turn{ true },
	_directionPriority{ true }
{}
Bot::Bot(const Bot& obj):
	Unit(obj),
	_turn{ obj._turn },
	_directionPriority{ obj._directionPriority }
{}
void Bot::hunt(Unit& target) {
	if (_directionPriority) {
		if (_turn == false && getTurnUnit() == turn_id::top) setTurnUnit(turn_id::right);
		else if (_turn == false) { setTurnUnit(getTurnUnit() + 1); }
	}
	else {
		if (_turn == false && getTurnUnit() == turn_id::right) setTurnUnit(turn_id::top);
		else if (_turn == false) { setTurnUnit(getTurnUnit() - 1); }
	}
	_directionPriority = (getId() == back_id::enemyBottom_id) ? true : false;
	_turn = true;
	if (checkTarget1(target)) {
		if (checkTarget2(target)) {
			if (checkCollision(target, true)) {
				if (checkCollision(target, false)) {
					(_directionPriority) ? setTurnUnit(getTurnUnit() - 1) : setTurnUnit(getTurnUnit() + 1);
					if (getTurnUnit() < turn_id::right) setTurnUnit(turn_id::top);
					if (getTurnUnit() > turn_id::top) setTurnUnit(turn_id::right);
					_turn = false;
					if (checkCollision(target, true)) {
						_turn = true;
					}
				}
			}
		}
	}
	else {
		(_directionPriority) ? setTurnUnit(getTurnUnit() - 1) : setTurnUnit(getTurnUnit() + 1);
	}
	if (getTurnUnit() < turn_id::right) setTurnUnit(turn_id::top);
	if (getTurnUnit() > turn_id::top) setTurnUnit(turn_id::right);
}
void Bot::shot(Unit* target1, Unit* target2, Unit* target3) {
	if (getHealth() > 0 && ((target1->getHealth() > 0 && searchTarget(*target1))||
		(target2->getHealth() > 0 && searchTarget(*target2)) ||
		(target3->getHealth() > 0 && searchTarget(*target3)))) {
		getBullet()->move(getCoord(), getTurnUnit(), getShotDistance(), getId());
		Unit* target = checkHit(target1, target2, target3);
		if(target != nullptr){
			target->setArmor(getBullet()->simpleShot(getShotPower(), target->getArmor()));
			if (target->getArmor() <= 0) {
				target->setArmor(0);
				target->setHealth(getBullet()->simpleShot(getShotPower(), target->getHealth()));
				if (target->getHealth() <= 0) target->setHealth(0);
			}
		}
	}
	else {
		getBullet()->setSpeed(0);
		getBullet()->setCoord(getCoord().X, getCoord().Y);
	}
}

Bot::~Bot()
{}
