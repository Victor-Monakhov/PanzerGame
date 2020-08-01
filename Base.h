#pragma once
#include "Unit.h"
class Base : public Unit{
private:
	Bullet _bullet[4];
	void perimBaseInit();
	virtual bool searchTarget(Unit& target) override;
	Unit* checkHit(Bullet* bullet, Unit* target1, Unit* target2);
public:
	Base(int model = 1, int health = 200, int armor = 0, int speed = 0,
		int shotPower = 1, int shotDistance = 200, int respawnTime = 100);
	Base(const Base& obj);
	Bullet* getBullet1();
	Bullet* getBullet2();
	Bullet* getBullet3();
	Bullet* getBullet4();
	void backBaseFill();
	void shot(Unit* target1 = nullptr, Unit* target2 = nullptr);
	~Base();
};

