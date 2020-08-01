#pragma once
#include "Map.h"

struct Position {
private:
	friend class Unit;
	friend class Base;
	friend class Bullet;
	COORD _coord = { 0,0 };
	COORD _pastCoord = { 0, 0 };
	COORD _deadCoord = { 0, 0 };
	COORD* _perimCoords = nullptr;
public:
	Position& operator=(const Position& obj);
};

class Bullet {
private:
	Map* _map;
	Position _pos;
	int _id;
	int _damage;
	int _turn;
	int _speed;
public:
	Bullet(Map* map = nullptr);
	COORD getCoord()const;
	int getDamage()const;
	int getTurn()const;
	int getSpeed()const;
	void setDamage(int damage);
	void setTurn(int turn);
	void setSpeed(int speed);
	void setMap(Map* map);
	void setCoord(int X, int Y);
	void move(COORD shooter, int turn, int distance, int id);
	bool miss();
	int hit();
	int simpleShot(int shotPower, int health);
	Bullet& operator=(const Bullet& obj);
	~Bullet();
};

