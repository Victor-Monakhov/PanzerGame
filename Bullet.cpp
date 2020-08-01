#include "Bullet.h"



Position& Position::operator=(const Position& obj) {
	_coord = { 0, 0 };
	_pastCoord = { 0, 0 };
	_deadCoord = { 0, 0 };
	_perimCoords = nullptr;
	return *this;
}


Bullet::Bullet(Map* map) :
	_id{0},
	_map{map},
	_damage{1},
	_turn{0},
	_speed{0}
{}
COORD Bullet::getCoord()const {
	return _pos._coord;
}
void Bullet::setMap(Map* map) {
	_map = map;
}
int Bullet::getDamage()const {
	return _damage;
}
int Bullet::getTurn()const {
	return _turn;
}
int Bullet::getSpeed()const {
	return _speed;
}
void Bullet::setDamage(int damage) {
	_damage = damage;
}
void Bullet::setTurn(int turn) {
	_turn = turn;
}
void Bullet::setSpeed(int speed) {
	_speed = speed;
}
void Bullet::setCoord(int X, int Y) {
	_pos._coord.X = X;
	_pos._coord.Y = Y;
}
bool Bullet::miss() {
	return (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
		[_map->getBarrier() + (int)_pos._coord.X] == back_id::wall_id);
}
int Bullet::hit() {
	if(_id == back_id::player_id || _id == back_id::ally_id || _id == back_id::redBase_id) {
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::enemyTop_id) return back_id::enemyTop_id;
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::enemyBottom_id) return back_id::enemyBottom_id;
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::blueBase_id) return back_id::blueBase_id;
	}
	if (_id == back_id::enemyTop_id || _id == back_id::enemyBottom_id || _id == back_id::blueBase_id) {
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::player_id) return back_id::player_id;
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::ally_id) return back_id::ally_id;
		if (_map->getBackMap()[_map->getBarrier() + (int)_pos._coord.Y]
			[_map->getBarrier() + (int)_pos._coord.X] == back_id::redBase_id) return back_id::redBase_id;
	}
	return 0;
}
void Bullet::move(COORD shooter, int turn, int distance, int id) {
	_id = id;
	if (_speed == 0) ++_speed;
	int width = (id == back_id::redBase_id ||
		id == back_id::blueBase_id) ? _map->getBaseWidth() : _map->getUnitWidth();
	int length = (id == back_id::redBase_id ||
		id == back_id::blueBase_id) ? _map->getBaseLength() : _map->getUnitWidth();
	if (_speed == 1) _turn = turn;
	switch (_turn) {
	case turn_id::right: {
		if (_speed == 1) _pos._coord = { (short)(shooter.X + width), (short)(shooter.Y + length / 2 - 1) };
		_pos._coord = { (short)(_pos._coord.X + distance / 10), (short)(_pos._coord.Y) };
		break;
	}
	case turn_id::bottom: {
		if (_speed == 1) _pos._coord = { (short)(shooter.X + length / 2 - 1), (short)(shooter.Y + width) };
		_pos._coord = { (short)(_pos._coord.X), (short)(_pos._coord.Y + distance / 10) };
		break;
	}
	case turn_id::left: {
		if (_speed == 1) _pos._coord = { (short)(shooter.X), (short)(shooter.Y + length / 2 - 1) };
		_pos._coord = { (short)(_pos._coord.X - distance / 10), (short)(_pos._coord.Y) };
		break;
	}
	case turn_id::top: {
		if (_speed == 1) _pos._coord = { (short)(shooter.X + length / 2 - 1), (short)(shooter.Y )};
		_pos._coord = { (short)(_pos._coord.X), (short)(_pos._coord.Y - distance / 10) };
		break;
	}
	}
	++_speed;
	if (miss() || hit() != 0) _speed = 0;
	if (_speed > 10) _speed = 0;
}
int Bullet::simpleShot(int shotPower, int health) {
	return  health - (rand() % (shotPower + _damage) + 1);
}
Bullet& Bullet::operator=(const Bullet& obj) {
	_map = obj._map;
	_pos = obj._pos;
	_id = obj._id;
	_damage = obj._damage;
	_turn = obj._turn;
	_speed = obj._speed;
	return *this;
}
Bullet::~Bullet()
{}
