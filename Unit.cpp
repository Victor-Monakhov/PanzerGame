#include "Unit.h"


void Unit::perimCoordInit() {
	if (_pos._perimCoords == nullptr) {
		_pos._perimCoords = new COORD[_map->getUnitPerim()];
		for (int i = 0; i < _map->getUnitPerim(); i++) {
			_pos._perimCoords[i] = { 0,0 };
		}
	}
	_pos._perimCoords[0].X = _pos._coord.X;
	_pos._perimCoords[0].Y = _pos._coord.Y;
	for (int i = 1; i < _map->getUnitWidth(); i++) {
		_pos._perimCoords[i].X = _pos._perimCoords[i - 1].X + 1;
		_pos._perimCoords[i].Y = _pos._coord.Y;
	}
	for (int i = _map->getUnitWidth(); i < 2*_map->getUnitWidth(); i++) {
		_pos._perimCoords[i].X = _pos._perimCoords[i - 1].X;
		_pos._perimCoords[i].Y = _pos._perimCoords[i - 1].Y + 1;
	}
	for (int i = 2*_map->getUnitWidth(); i < 3*_map->getUnitWidth(); i++) {
		_pos._perimCoords[i].X = _pos._perimCoords[i - 1].X - 1;
		_pos._perimCoords[i].Y = _pos._perimCoords[i - 1].Y;
	}
	for (int i = 3*_map->getUnitWidth(); i < 4*_map->getUnitWidth(); i++) {
		_pos._perimCoords[i].X = _pos._perimCoords[i - 1].X;
		_pos._perimCoords[i].Y = _pos._perimCoords[i - 1].Y - 1;
	}
}
Unit::Unit(int model, int health, int armor, int speed, int shotPower,
	int shotDistance, int respawnTime) :
	_id(0),
	_name{ "NoName"},
	_model{ model},
	_health{ health},
	_armor{ armor },
	_speed{ speed },
	_shotPower{ shotPower },
	_shotDistance{ shotDistance },
	_superAbility{ 0 },
	_respawnTime{ respawnTime },
	_turnUnit{ 3 },
	_map{ nullptr }
{}
Unit::Unit(const Unit& obj):
	_id(obj._id),
	_name{ obj._name },
	_model{ obj._model },
	_health{ obj._health },
	_armor{ obj._armor },
	_speed{ obj._speed },
	_shotPower{ obj._shotPower },
	_shotDistance{ obj._shotDistance },
	_superAbility{ obj._superAbility },
	_respawnTime{ obj._respawnTime },
	_turnUnit{ obj._turnUnit },
	_map{ obj._map }
{}
//getters
int Unit::getId()const {
	return _id;
}
string Unit::getName()const {
	return _name;
}
int Unit::getModel()const {
	return _model;
}
int Unit::getHealth()const {
	return _health;
}
int Unit::getArmor()const {
	return _armor;
}
int Unit::getSpeed()const {
	return _speed;
}
int Unit::getShotPower()const {
	return _shotPower;
}
int Unit::getShotDistance()const {
	return _shotDistance;
}
int Unit::getSuperAbility()const {
	return _superAbility;
}
int Unit::getRespawnTime()const {
	return _respawnTime;
}
Bullet* Unit::getBullet() {
	return &_bullet;
}
int Unit::getTurnUnit()const {
	return _turnUnit;
}
Map* Unit::getMap()const {
	return _map;
}
COORD Unit::getCoord()const {
	return _pos._coord;
}
COORD Unit::getPastCoord()const {
	return _pos._pastCoord;
}
COORD Unit::getDeadCoord()const {
	return _pos._deadCoord;
}
COORD* Unit::getPerimCoord()const {
	return _pos._perimCoords;
}
Position* Unit::getPos() {
	return &_pos;
}
//setters
void Unit::setId(int id) {
	_id = id;
}
void Unit::setName(string name) {
	_name = name;
}
void Unit::setModel(int model) {
	_model = model;
}
void Unit::setHealth(int health) {
	_health = health;
}
void Unit::setArmor(int armor) {
	_armor = armor;
}
void Unit::setSpeed(int speed) {
	_speed = speed;
}
void Unit::setShotPower(int shotPower) {
	_shotPower = shotPower;
}
void Unit::setShotDistance(int shotDistance) {
	_shotDistance = shotDistance;
}
void Unit::setSuperAbility(int superAbility) {
	_superAbility = superAbility;
}
void Unit::setRespawnTime(int respawnTime) {
	_respawnTime = respawnTime;
}
void Unit::setTurnUnit(int turnUnit) {
	_turnUnit = turnUnit;
}
void Unit::setMap(Map* map) {
	_map = map;
	_bullet.setMap(map);
}
void Unit::setCoord(int X, int Y) {
	_pos._coord.X = X;
	_pos._coord.Y = Y;
}
void Unit::setPastCoord(int X, int Y) {
	_pos._pastCoord.X = X;
	_pos._pastCoord.Y = Y;
}
void Unit::setDeadCoord(int X, int Y) {
	_pos._deadCoord.X = X;
	_pos._deadCoord.Y = Y;
}
void Unit::setPerimCoord(COORD* perimCoords) {
	for(int i = 0; i < _map->getUnitPerim(); i++)
	_pos._perimCoords[i] = perimCoords[i];
}
void Unit::setBullet(Bullet bullet) {
	_bullet = bullet;
}
//func
void Unit::backFill() {
	for (int i = _map->getBarrier() + _pos._coord.X; i < _map->getBarrier() + _pos._coord.X + _map->getUnitWidth(); i++) {
		for (int j = _map->getBarrier() + _pos._coord.Y; j < _map->getBarrier() + _pos._coord.Y + _map->getUnitWidth(); j++) {
			_map->setBackMap(j, i, _id);
		}
	}
	perimCoordInit();
}
void Unit::backClear() {
	for (int i = _map->getBarrier() + _pos._pastCoord.X; i < _map->getBarrier() + _pos._pastCoord.X + _map->getUnitWidth(); i++) {
		for (int j = _map->getBarrier() + _pos._pastCoord.Y; j < _map->getBarrier() + _pos._pastCoord.Y + _map->getUnitWidth(); j++) {
			_map->setBackMap(j,i,back_id::freeRoad_id);
		}
	}
}
void Unit::look(int& indexRow, int& indexColumn, int& position, int step, int i) {
	switch (getTurnUnit()) {
	case turn_id::right: {
		indexRow = _map->getBarrier() + _pos._perimCoords[i].Y;
		indexColumn = _map->getBarrier() + _pos._perimCoords[i].X + step + 1;
		position = _map->getBackMap()[indexRow][indexColumn];
		break;
	}
	case turn_id::bottom: {
		indexRow = _map->getBarrier() + _pos._perimCoords[i].Y + step + 1;
		indexColumn = _map->getBarrier() + _pos._perimCoords[i].X;
		position = _map->getBackMap()[indexRow][indexColumn];
		break;
	}
	case turn_id::left: {
		indexRow = _map->getBarrier() + _pos._perimCoords[i].Y;
		indexColumn = _map->getBarrier() + _pos._perimCoords[i].X - step - 1;
		position = _map->getBackMap()[indexRow][indexColumn];
		break;
	}
	case turn_id::top: {
		indexRow = _map->getBarrier() + _pos._perimCoords[i].Y - step - 1;
		indexColumn = _map->getBarrier() + _pos._perimCoords[i].X;
		position = _map->getBackMap()[indexRow][indexColumn];
		break;
	}
	}
}
void Unit::setPosition(int iterator, bool flag) {
	switch (getTurnUnit()) {
	case turn_id::right: {
		(flag) ? _pos._coord.X += iterator : _pos._coord.X -= iterator;
		break;
	}
	case turn_id::bottom: {
		(flag) ? _pos._coord.Y += iterator : _pos._coord.Y -= iterator;
		break;
	}
	case turn_id::left: {
		(flag) ? _pos._coord.X -= iterator : _pos._coord.X += iterator;
		break;
	}
	case turn_id::top: {
		(flag) ? _pos._coord.Y -= iterator: _pos._coord.Y += iterator;
		break;
	}
	}
}
bool Unit::searchTarget(Unit& target) {
	if (target.getHealth() > 0) {
		for (int i = 0; i < _shotDistance; i += 25) {
			for (int j = 0; j < getMap()->getUnitPerim(); j+=5) {
				int indexRow = 0, indexColumn = 0, position = 0;
				look(indexRow, indexColumn, position, i, j);
				if (position == target.getId()) return true;
			}
		}
	}
	return false;
}
Unit::~Unit()
{
	if (_pos._perimCoords != nullptr)
		delete _pos._perimCoords;
}
