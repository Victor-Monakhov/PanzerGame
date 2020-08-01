#pragma once
#include "Bullet.h"


class Unit {
private:
	int _id;
	string _name;
	int _model;
	int _health;
	int _armor;
	int _speed;
	int _shotPower;
	int _shotDistance;
	int _superAbility;
	int _respawnTime;
	int _turnUnit;
	Map* _map;
	Bullet _bullet;
	Position _pos;
	void perimCoordInit();
public:
	Unit(int model = 1, int health = 20, int armor = 20, int speed = 10,
		int shotPower = 1, int shotDistance = 200, int respawnTime = 100);
	Unit(const Unit& obj);
	//getters
	int getId()const;
	string getName()const;
	int getModel()const;
	int getHealth()const;
	int getArmor()const;
	int getSpeed()const;
	int getShotPower()const;
	int getShotDistance()const;
	int getSuperAbility()const;
	int getRespawnTime()const;
	Bullet* getBullet();
	int getTurnUnit()const;
	Map* getMap()const;
	COORD getCoord()const;
	COORD getPastCoord()const;
	COORD getDeadCoord()const;
	COORD* getPerimCoord()const;
	Position* getPos();
	//setters
	void setId(int id);
	void setName(string name);
	void setModel(int model);
	void setHealth(int health);
	void setArmor(int armor);
	void setSpeed(int speed);
	void setShotPower(int shotPower);
	void setShotDistance(int shotDistance);
	void setSuperAbility(int superAbility);
	void setRespawnTime(int respawnTime);
	void setTurnUnit(int turnUnit);
	void setMap(Map* map);
	void setCoord(int X, int Y);
	void setPastCoord(int X, int Y);
	void setDeadCoord(int X, int Y);
	void setPerimCoord(COORD* perimCoords);
	void setBullet(Bullet bullet);
	//func
	void backFill();
	void backClear();
	void look(int& indexRow, int& indexColumn, int& position, int step, int i);
	void setPosition(int iterator, bool flag);
	virtual bool searchTarget(Unit& target);
	virtual ~Unit();
};

