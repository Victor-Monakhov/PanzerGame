#pragma once
#include "Game.h"
class PanzersFace : public GameFace {
protected:
	int _dynamicStart, _dynamicFinish, _pastCoord;
	COORD _tempCoord;
	virtual void drawStartMenu();
	void drawPanzerCreaterMenu();
	void drawPanzerCharacteristicsMenu(Player& player);
	virtual void drawPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop);
public:
	PanzersFace(int dynamicStart = 0, int dynamicFinish = 0, int pastCoord = 10);
	virtual void drawMainPage(const COORD& coord);
	void drawNewPanzerName(const COORD& coord, string& writing, bool busy);
	void drawNewPanzerModel(const COORD& coord, Player& panzer, bool pushLeft, bool pushRight);
	void drawNewPanzerCharacteristics(const COORD& coord, Player& panzer, bool pushLeft, bool pushRight);
	void drawSearchPanzer(const COORD& coord, const string& writing);
	virtual void drawAllPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop);
	~PanzersFace();
};

