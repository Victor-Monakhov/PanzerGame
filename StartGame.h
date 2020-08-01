#pragma once
#include "StartFace.h"

class StartGame {
private:
	StartFace  _startFace;
	Utilities _utility;
	vector<Profile> _profile;
	bool _work;
	int _size;
	void addProfile();
	void initProfileCode();
	void firstCharNameToUp(int element);
	vector<Profile> searchProfile(int& result);
	vector<Profile> changeName(int result);
	void newProfile();
	void profileChoice();
	void deleteProfile();
	void profileChange();
	void profileSort();
	void saveProfiles();
	void initProfiles();
public:
	StartGame();
	StartGame(const StartGame& obj);
	void start(); // main func
	~StartGame();
};

