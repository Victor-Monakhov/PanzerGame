#pragma once
#include "PoligonFace.h"
class ProfileFace : public PoligonFace {
protected:
	virtual void drawStartMenu() override; 
	void drawChooseMenu();
	void drawMyGameMenu();
public:
	ProfileFace();
	virtual void drawMainPage(const COORD& coord) override;
	void drawMessage1();
	void drawMessage2();
	void drawStatistic(vector<Player> panzers);
	void drawHardChoosePage(const COORD& coord);
	void drawMyGamePage(const COORD& coord);
	virtual void drawAllPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) override;
	virtual void drawPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) override;
	void drawSearchPanzer(const COORD& coord, const string& writing);
	~ProfileFace();
};

