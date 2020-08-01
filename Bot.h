#pragma once
#include "Unit.h"

class Bot final: public Unit {
private:
	bool _turn;
	bool _directionPriority;
	bool checkTarget1(Unit& target);
	bool checkTarget2(Unit& target);
	bool checkCollision(Unit& target, bool flag);
	bool checkFrontWay(Unit& target, int step);
	bool checkFrontWayExtra(Unit& target, int step); 
	Unit* checkHit(Unit* target1 = nullptr, Unit* target2 = nullptr, Unit* target3 = nullptr);
public:
	Bot(int model = 1, int health = 20, int armor = 20, int speed = 10,
		int shotPower = 1, int shotDistance = 200, int respawnTime = 100);
	Bot(const Bot& obj);
	void hunt(Unit& target);
	void shot(Unit* target1 = nullptr, Unit* target2 = nullptr, Unit* target3 = nullptr);
	virtual ~Bot();
};

