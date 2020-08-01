#pragma once
#include "Profile.h"
class StartFace final: public ProfileFace {
private:
	virtual void drawStartMenu() override;
	void drawProfiles(vector<Profile>& profile, COORD& coord, int size, bool loop);
public:
	StartFace();
	virtual void drawMainPage(const COORD& coord) override;
	void drawNewProfile(const COORD& coord, const string& writing, bool busy);
	void drawProfileChoice(vector<Profile>& profile, COORD& coord, int size, bool loop);
	void drawSearchProfile(const COORD& coord, const string& writing);
	~StartFace();
};

