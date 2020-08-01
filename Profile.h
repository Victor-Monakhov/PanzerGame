#pragma once
#include "Poligon.h"
#include "ProfileFace.h"

class Profile : public Poligon{
private:
	ProfileFace _profileFace;
	BotContainer _bc;
	string _name;
	int _code;
public:
	Profile(string name = "\0", int code = -1);
	Profile(const Profile& obj);
	string getName()const;
	int getCode()const;
	void setName(string name);
	void setCode(int code);
	//func
	void myProfile();			//main func
	void myGame();
	void myPanzers();
	void enterToFight();
	void gameBegin(Bot* enemyTop, Bot* enemyBottom, Bot* ally, Base* blueBase);
	virtual vector<Player> Profile::searchPanzer(int& result) override;
	
	bool operator>(const Profile& obj);
	bool operator<(const Profile& obj);
	Profile& operator=(const Profile& obj);
	Profile& operator=(Profile&& obj);
	friend ostream& operator<<(ostream& os, Profile& profile);
	friend istream& operator>>(istream& is, Profile& profile);
	void savePanzers();
	void initPanzers();
	void savePanzersAfterProfileDelete();
	~Profile();
};

