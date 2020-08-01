#pragma once
#include "GameFace.h"

class Game {
private:
	Map* _map;
	StartUnit _start;
	CurrentUnit _cur;
	GameFace _gameFace;
	int _random;
	void preparation();
	void unitBackFill();
	void logicBotLife(Unit* unit);
	void death(Unit* start, Unit* current);
	void rebirth(Unit* start, Unit* current);
	bool pause(int key, bool& flag);
	void isWin(int controlAssistant, bool& gameOver, bool& oneYimeWin);
	void isDefeat(int controlAssistant, bool& gameOver);
public:
	Game(Map* map, Bot* enemyTop, Bot* enemyBottom, Bot* ally, Player* player, Base* redBase, Base* blueBase);
	void run();
	
	~Game();
};

