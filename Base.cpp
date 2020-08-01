#include "Base.h"

Base::Base(int model, int health, int armor, int speed,
	int shotPower, int shotDistance, int respawnTime) :
	Unit(model, health, armor, speed, shotPower, shotDistance, respawnTime)
{}
Base::Base(const Base& obj) :
	Unit(obj)
{}
//getters
void Base::perimBaseInit() {
	if (getPos()->_perimCoords == nullptr) {
		getPos()->_perimCoords = new COORD[getMap()->getBasePerim()];
		for (int i = 0; i < getMap()->getBasePerim(); i++) {
			getPos()->_perimCoords[i] = { 0,0 };
		}
	}
	getPos()->_perimCoords[0].X = getPos()->_coord.X;
	getPos()->_perimCoords[0].Y = getPos()->_coord.Y;
	for (int i = 1; i < getMap()->getBaseWidth(); i++) {
		getPos()->_perimCoords[i].X = getPos()->_perimCoords[i - 1].X + 1;
		getPos()->_perimCoords[i].Y = getPos()->_coord.Y;
	}
	for (int i = getMap()->getBaseWidth(); i < getMap()->getBaseWidth() + getMap()->getBaseLength(); i++) {
		getPos()->_perimCoords[i].X = getPos()->_perimCoords[i - 1].X;
		getPos()->_perimCoords[i].Y = getPos()->_perimCoords[i - 1].Y + 1;
	}
	for (int i = getMap()->getBaseWidth() + getMap()->getBaseLength();
		i < 2 * getMap()->getBaseWidth() + getMap()->getBaseLength(); i++) {
		getPos()->_perimCoords[i].X = getPos()->_perimCoords[i - 1].X - 1;
		getPos()->_perimCoords[i].Y = getPos()->_perimCoords[i - 1].Y;
	}
	for (int i = 2 * getMap()->getBaseWidth() + getMap()->getBaseLength();
		i < 2 * getMap()->getBaseWidth() + 2 * getMap()->getBaseLength(); i++) {
		getPos()->_perimCoords[i].X = getPos()->_perimCoords[i - 1].X;
		getPos()->_perimCoords[i].Y = getPos()->_perimCoords[i - 1].Y - 1;
	}
	_bullet[0].setMap(getMap());
	_bullet[1].setMap(getMap());
	_bullet[2].setMap(getMap());
	_bullet[3].setMap(getMap());
}

Bullet* Base::getBullet1() {
	return &_bullet[0];
}
Bullet* Base::getBullet2() {
	return &_bullet[1];
}
Bullet* Base::getBullet3(){
	return &_bullet[2];
}
Bullet* Base::getBullet4() {
	return &_bullet[3];
}
//func
bool Base::searchTarget(Unit& target) {
	if (target.getHealth() > 0) {
		for (int i = 0; i < getShotDistance(); i += 25) {
			for (int j = 0; j < getMap()->getBasePerim(); j += 5) {
				int indexRow = 0, indexColumn = 0, position = 0;
				look(indexRow, indexColumn, position, i, j);
				if (position == target.getId()) return true;
			}
		}
	}
	return false;
}
void Base::backBaseFill() {
	for (int i = getMap()->getBarrier() + getPos()->_coord.X;
		i <  getMap()->getBarrier() + getPos()->_coord.X + getMap()->getBaseWidth(); i++) {
		for (int j = getMap()->getBarrier() + getPos()->_coord.Y;
			j <  getMap()->getBarrier() + getPos()->_coord.Y + getMap()->getBaseLength(); j++) {
			getMap()->setBackMap(j, i, getId());
		}
	}
	perimBaseInit();
}
Unit* Base::checkHit(Bullet* bullet, Unit* target1, Unit* target2) {
	if (bullet->hit() == target1->getId()) return target1;
	if (bullet->hit() == target2->getId()) return target2;
	return nullptr;
}
void Base::shot(Unit* target1, Unit* target2) {
	if ((target1->getHealth() > 0 && searchTarget(*target1)) ||
		(target2->getHealth() > 0 && searchTarget(*target2))) {
		_bullet[0].move({ getPos()->_coord.X, getPos()->_coord.Y - 70 }, getTurnUnit(), getShotDistance(), getId());
		_bullet[1].move({ getPos()->_coord.X, getPos()->_coord.Y - 20 }, getTurnUnit(), getShotDistance(), getId());
		_bullet[2].move({ getPos()->_coord.X, getPos()->_coord.Y + 20 }, getTurnUnit(), getShotDistance(), getId());
		_bullet[3].move({ getPos()->_coord.X, getPos()->_coord.Y + 70 }, getTurnUnit(), getShotDistance(), getId());
		Unit* target[4];
		for (int i{}; i < 4; i++)
		target[i] = checkHit(&_bullet[i], target1, target2);
		for (int i{}; i < 4; i++) {
			if (target[i] != nullptr) {
				target[i]->setArmor(_bullet[i].simpleShot(getShotPower(), target[i]->getArmor()));
				if (target[i]->getArmor() <= 0) {
					target[i]->setArmor(0);
					target[i]->setHealth(_bullet[i].simpleShot(getShotPower(), target[i]->getHealth()));
					if (target[i]->getHealth() <= 0) target[i]->setHealth(0);
				}
			}
		}
	}
	else {
		for (int i{}; i<4; i++)
			_bullet[i].setSpeed(0);
	}
}
Base::~Base()
{}
