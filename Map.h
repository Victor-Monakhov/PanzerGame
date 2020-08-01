#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <memory>
#include <vector>

#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_ENTER 13
#define KEY_DELETE 83
#define KEY_SPACE 32
#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27

using namespace std;

enum back_id {
	freeRoad_id,
	wall_id,
	player_id,
	ally_id,
	enemyTop_id,
	enemyBottom_id,
	roadEnd_id,
	allyRoadEnd_id,
	enemyRoadEnd_id,
	redBase_id,
	blueBase_id,
	bullet_id
};

enum turn_id {
	right,
	bottom,
	left,
	top
};

class Map {
protected:
	const int _unitWidth;
	const int _baseWidth;
	const int _baseLength;
	const int _unitPerim;
	const int _basePerim;
	const int _mainBackHeight;
	const int _mainBackWidth;
	const int _mainFrontHeight;
	const int _mainFrontWidth;
	const int _barrier;
	const COORD _startFieldCoord;
	int** _backMap;
	COORD _redBaseCoords;
	COORD _blueBaseCoords;
	COORD _playerCoords;
	COORD _enemyTopCoords;
	COORD _enemyBottomCoords;
	COORD _allyBottomCoords;
	int _startPlayerTurn;
	int _startEnemyTurn;
public:
	Map(COORD redBaseCoords = { 70, 220 }, COORD blueBaseCoorm  = { 830, 200 }, COORD playerCoords = { 60, 90 },
		COORD allyBottomCoords = { 60, 440 }, COORD enemyTopCoords = { 830, 90 }, COORD enemyBottomCoords = { 830, 440 },
		int startPlayerTurn = 0, int startEnemyTurn = 2);
	//getters
	int getUnitWidth()const;
	int getBaseWidth()const;
	int getBaseLength()const;
	int getUnitPerim()const;
	int getBasePerim()const;
	int getMainBackHeight()const;
	int getMainBackWidth()const;
	int getMainFrontHeight()const;
	int getMainFrontWidth()const;
	int getBarrier()const;
	COORD getStartFieldCoord()const;
	COORD getRedBaseCoord()const;
	COORD getBlueBaseCoord()const;
	COORD getPlayerCoord()const;
	COORD getEnemyTopCoord()const;
	COORD getEnemyBottomCoord()const;
	COORD getAllyBottomCoord()const;
	int getStartPlayerTurn()const;
	int getStartEnemyTurn()const;
	int** getBackMap();
	//setters
	void setRedBaseCoord(COORD redBaseCoords);
	void setBlueBaseCoord(COORD blueBaseCoords);
	void setPlayerCoord(COORD playerCoords);
	void setEnemyTopCoord(COORD enemyTopCoords);
	void setEnemyBottomCoord(COORD enemyBottomCoords);
	void setAllyBottomCoord(COORD allyBottomCoords);
	//init func
	void init();
	void backRespawnInit();
	void setBackMap(int indexRow, int indexColumn, int value);
	~Map();
};

