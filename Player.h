#pragma once
#include "Unit.h"

class Player final : public Unit {
private:
	int _level;
	int _bestTime;
	int _money;
	int _commandPoints;
	int _battles;
	int _wins;
	int _defeat;
	int _code;
	bool _trigger;
	//func
	bool checkCollision();
	bool checkFrontWay(int step);
	Unit* checkHit(Unit* target1, Unit* target2, Unit* target3);
public:
	Player();
	Player(const Player& obj);
	
	//getters
	int getLevel()const;
	int getBestTime()const;
	int getMoney()const;
	int getCommandPoints()const;
	int getBattles()const;
	int getWins()const;
	int getDefeat()const;
	int getCode()const;
	//setters
	void setLevel(int level);
	void setBestTime(int time);
	void setMoney(int money);
	void setCommandPoints(int commandPoints);
	void setBattles(int battles);
	void setWins(int wins);
	void setDefeat(int defeat);
	void setCode(int code);
	//func
	int controls(bool flag);
	void shot(Unit* target1, Unit* target2, Unit* target3);
	friend ostream& operator<<(ostream& os, Player& panzer);
	friend istream& operator>>(istream& is, Player& panzer);
	virtual ~Player();
};

