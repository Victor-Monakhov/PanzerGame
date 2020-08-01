#include "Player.h"

Player::Player() :
	Unit(),
	_level{},
	_bestTime{},
	_money {},
	_commandPoints{ 4 },
	_battles{},
	_wins{},
	_defeat{},
	_code{},
	_trigger{false}
{}
Player::Player(const Player& obj) :
	Unit(obj),
	_level{obj._level},
	_bestTime{ obj._bestTime },
	_money {obj._money},
	_commandPoints{ obj._commandPoints },
	_battles{obj._battles},
	_wins{obj._wins},
	_defeat{obj._defeat},
	_code{obj._code},
	_trigger{ obj._trigger }
{}

//getters
int Player::getLevel()const {
	return _level;
}
int Player::getBestTime()const {
	return _bestTime;
}
int Player::getMoney()const {
	return _money;
}
int Player::getCommandPoints()const {
	return _commandPoints;
}
int Player::getBattles()const {
	return _battles;
}
int Player::getWins()const {
	return _wins;
}
int Player::getDefeat()const {
	return _defeat;
}
int Player::getCode()const {
	return _code;
}
//setters
void Player::setLevel(int level) {
	_level = level;
}
void Player::setBestTime(int time) {
	_bestTime = time;
}
void Player::setMoney(int money) {
	_money = money;
}
void Player::setCommandPoints(int commandPoints) {
	_commandPoints = commandPoints;
}
void Player::setBattles(int battles) {
	_battles = battles;
}
void Player::setWins(int wins) {
	_wins = wins;
}
void Player::setDefeat(int defeat) {
	_defeat = defeat;
}
void Player::setCode(int code) {
	_code = code;
}
bool Player::checkCollision() {
	bool collision = false;
	for (int i = getSpeed(); i > 0; i -= 2) {
		collision = false;
		setPosition(i, true);
		if (!checkFrontWay(i)) {
			setPosition(i, false);
			collision = true;
		}
		if (collision == false)break;
	}
	return collision;
}
bool Player::checkFrontWay(int step) {
	for (int i = 0; i < getMap()->getUnitPerim(); i++) {
		int indexRow = 0, indexColumn = 0, position = 0;
		look(indexRow, indexColumn, position, step, i);
		if (position == back_id::wall_id ||
			position == back_id::enemyTop_id ||
			position == back_id::roadEnd_id ||
			position == back_id::enemyBottom_id ||
			position == back_id::ally_id ||
			position == back_id::enemyRoadEnd_id) return false;
	}
	return true;
}
//func
Unit* Player::checkHit(Unit* target1, Unit* target2, Unit* target3) {
	if (getBullet()->hit() == target1->getId()) return target1;
	if (getBullet()->hit() == target2->getId()) return target2;
	if (getBullet()->hit() == target3->getId()) return target3;
	return nullptr;
}
void Player::shot(Unit* target1, Unit* target2, Unit* target3) {
	if (_trigger == true) {
		getBullet()->move(getCoord(), getTurnUnit(), getShotDistance(), getId());
		if (target1 != nullptr && target2 != nullptr && target3 != nullptr) {
			Unit* target = checkHit(target1, target2, target3);
			if (target != nullptr) {
				target->setArmor(getBullet()->simpleShot(getShotPower(), target->getArmor()));
				if (target->getArmor() <= 0) {
					target->setArmor(0);
					target->setHealth(getBullet()->simpleShot(getShotPower(), target->getHealth()));
					if (target->getHealth() <= 0) target->setHealth(0);
				}
			}
		}
		if (getBullet()->getSpeed() == 0) _trigger = false;
	}
	else {
		getBullet()->setSpeed(0);
		getBullet()->setCoord(getCoord().X, getCoord().Y);
	}
}
int Player::controls(bool flag) {
	int key = 0;
	bool check224 = false;
	if (_kbhit())
	{
		do {
			if (key == 224 || key == 'à') check224 = false;
			key = _getch();
			switch (key) {
			case 246:
			case 'w':
			case (KEY_UP):
				if (flag && getHealth() > 0) {
					setTurnUnit(turn_id::top);
					checkCollision();
				}
				return KEY_UP;
			case 179:
			case 's':
			case (KEY_DOWN):
				if (flag && getHealth() > 0) {
					setTurnUnit(turn_id::bottom);
					checkCollision();
				}
				return KEY_DOWN;
			case 244:
			case 'a':
			case (KEY_LEFT): {
				if (flag && getHealth() > 0) {
					setTurnUnit(turn_id::left);
					checkCollision();
				}
				return KEY_LEFT;
			}
			case 226:
			case 'd':
			case (KEY_RIGHT): {
				if (flag && getHealth() > 0) {
					setTurnUnit(turn_id::right);
					checkCollision();
				}
				return KEY_RIGHT;
			}
			case 243:
			case 'e': {
				if (flag && getHealth() > 0) _trigger = true;
				break;
			}
			case KEY_SPACE: {
				return KEY_SPACE;
				break;
			}
			case KEY_ESCAPE: {
				return KEY_ESCAPE;
				break;
			}
			case KEY_ENTER: {
				return KEY_ENTER;
				break;
			}
			}
			if (key == 224 || key == 'à') check224 = true;
		} while (check224);
	}
	return 0;
}
ostream& operator<<(ostream& os, Player& panzer) {
	os << panzer.getCode() << " " << panzer.getName() << " " << panzer.getModel() << " " <<
		panzer.getHealth() << " " << panzer.getArmor() << " " << panzer.getSpeed() << " " <<
		panzer.getShotPower() << " " << panzer.getShotDistance() << " " << panzer.getCommandPoints() << " " <<
		panzer.getSuperAbility() << " " << panzer.getLevel() << " " << panzer.getBestTime() << " " <<
		panzer.getRespawnTime() << " " << panzer.getBattles() << " " << panzer.getWins() << " " <<
		panzer.getDefeat() << " " << panzer.getMoney();
	return os;
}

istream& operator>>(istream& is, Player& panzer) {
	int code, model, health, armor, speed, shotPower, shotDistance, commandPoints, superAbility,
		level, bestTime, respawnTime, battles, wins, defeat, money;
	string name;
	is >> code;
	is >> name;
	is >> model >> health >> armor >> speed >> shotPower >> shotDistance >> commandPoints >>
		superAbility >> level >> bestTime >> respawnTime >> battles >> wins >> defeat >> money;
	panzer.setCode(code);
	panzer.setName(name);
	panzer.setModel(model); 
	panzer.setHealth(health);
	panzer.setArmor(armor);
	panzer.setSpeed(speed);
	panzer.setShotPower(shotPower);
	panzer.setShotDistance(shotDistance);
	panzer.setCommandPoints(commandPoints);
	panzer.setSuperAbility(superAbility);
	panzer.setLevel(level);
	panzer.setBestTime(bestTime);
	panzer.setRespawnTime(respawnTime);
	panzer.setBattles(battles);
	panzer.setWins(wins);
	panzer.setDefeat(defeat);
	panzer.setMoney(money);
	return is;
}

Player::~Player()
{}
