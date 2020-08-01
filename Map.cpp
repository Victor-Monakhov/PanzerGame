#include "Map.h"

Map::Map(COORD redBaseCoords, COORD blueBaseCoords, COORD playerCoords, COORD allyBottomCoords,
	COORD enemyTopCoords, COORD enemyBottomCoords, int startPlayerTurn, int startEnemyTurn) :
	_redBaseCoords{ redBaseCoords.X, redBaseCoords.Y },
	_blueBaseCoords{ blueBaseCoords.X, blueBaseCoords.Y},
	_playerCoords{ playerCoords.X, playerCoords.Y},
	_allyBottomCoords{ allyBottomCoords.X, allyBottomCoords.Y},
	_enemyTopCoords{ enemyTopCoords.X, enemyTopCoords.Y},
	_enemyBottomCoords{ enemyBottomCoords.X, enemyBottomCoords.Y },
	_startPlayerTurn{ startPlayerTurn },
	_startEnemyTurn{startEnemyTurn},
	_unitWidth{ 49 },
	_baseWidth{50},
	_baseLength{160},
	_unitPerim{ _unitWidth*4 },
	_basePerim{2*(_baseWidth+_baseLength)},
	_mainBackHeight{ 2550 },
	_mainBackWidth{ 2950 },
	_mainFrontHeight{ 550 },
	_mainFrontWidth{ 950 },
	_barrier{ 1000 },
	_startFieldCoord{0,0 }
{
	_backMap = new int*[_mainBackHeight];
	for (int i = 0; i < _mainBackHeight; i++) {
		_backMap[i] = new int[_mainBackWidth];
		for (int j = 0; j < _mainBackWidth; j++) {
			_backMap[i][j] = 0;
		}
	}
}
//getters
int Map::getUnitWidth()const {
	return _unitWidth;
}
int Map::getBaseWidth()const {
	return _baseWidth;
}
int Map::getBaseLength()const {
	return _baseLength;
}
int Map::getUnitPerim()const {
	return _unitPerim;
}
int Map::getBasePerim()const {
	return _basePerim;
}
int Map::getMainBackHeight()const {
	return _mainBackHeight;
}
int Map::getMainBackWidth()const {
	return _mainBackWidth;
}
int Map::getMainFrontHeight()const {
	return _mainFrontHeight;
}
int Map::getMainFrontWidth()const {
	return _mainFrontWidth;
}
int Map::getBarrier()const {
	return _barrier;
}
COORD Map::getStartFieldCoord()const {
	return _startFieldCoord;
}
COORD Map::getRedBaseCoord()const {
	return _redBaseCoords;
}
COORD Map::getBlueBaseCoord()const {
	return _blueBaseCoords;
}
COORD Map::getPlayerCoord()const {
	return _playerCoords;
}
COORD Map::getEnemyTopCoord()const {
	return _enemyTopCoords;
}
COORD Map::getEnemyBottomCoord()const {
	return _enemyBottomCoords;
}
COORD Map::getAllyBottomCoord()const {
	return _allyBottomCoords;
}
int Map::getStartPlayerTurn()const {
	return _startPlayerTurn;
}
int Map::getStartEnemyTurn()const {
	return _startEnemyTurn;
}
int** Map::getBackMap() {
	return _backMap;
}
//setters
void Map::setRedBaseCoord(COORD redBaseCoords) {
	_redBaseCoords = redBaseCoords;
}
void Map::setBlueBaseCoord(COORD blueBaseCoords) {
	_blueBaseCoords = blueBaseCoords;
}
void Map::setPlayerCoord(COORD playerCoords) {
	_playerCoords = playerCoords;
}
void Map::setEnemyTopCoord(COORD enemyTopCoords) {
	_enemyTopCoords = enemyTopCoords;
}
void Map::setEnemyBottomCoord(COORD enemyBottomCoords) {
	_enemyBottomCoords = enemyBottomCoords;
}
void Map::setAllyBottomCoord(COORD allyBottomCoords) {
	_allyBottomCoords = allyBottomCoords;
}
void Map::init() {
	//upper and lower bounds
	for (int i = _barrier + 6, k = _barrier + _mainFrontHeight + 14; i > 22, k < _mainBackHeight - 2; i--, k++) {
		for (int j = 0; j < _mainBackWidth; j++) {
			_backMap[i][j] = back_id::wall_id;
			_backMap[k][j] = back_id::wall_id;
		}
	}
	//territory of red and blue bases
	for (int i = _barrier + 160; i < _barrier + 418; i++) {
		for (int j = 0, k = _mainBackWidth - _barrier - 147; j < _barrier + 147, k < _mainBackWidth; j++, k++) {
			_backMap[i][j] = back_id::wall_id;
			_backMap[i][k] = back_id::wall_id;
		}
	}
	//red and blue bases
	for (int i = _barrier + 190; i < _barrier + 390; i++) {
		for (int j = 0, k = _mainBackWidth - _barrier - 110; j < _barrier + 110, k < _mainBackWidth; j++, k++) {
			_backMap[i][j] = back_id::redBase_id;
			_backMap[i][k] = back_id::blueBase_id;
		}
	}
	//doorstep of red and blue bases
	for (int i = _barrier + 190; i < _barrier + 390; i++) {
		for (int j = _barrier + 110, k = _mainBackWidth - _barrier - 147; j < _barrier + 147,
			k < _mainBackWidth - _barrier - 110; j++, k++) {
			_backMap[i][j] = back_id::roadEnd_id;
			_backMap[i][k] = back_id::roadEnd_id;
		}
	}
	//left and right bounds
	for (int i = 0; i < _mainBackHeight; i++) {
		for (int j = 0, k = _mainBackWidth - _barrier - 50; j < _barrier + 50, k < _mainBackWidth; j++, k++) {
			_backMap[i][j] = back_id::wall_id;
			_backMap[i][k] = back_id::wall_id;
		}
	}
	//corner ledges
	for (int i = _barrier + 65, k = _mainBackHeight - _barrier - 35; i > 30, k < _mainBackHeight; i--, k++) {
		for (int j = 0, c = _mainBackWidth - _barrier - 147; j < _barrier + 147, c < _mainBackWidth; j++, c++) {
			_backMap[i][j] = back_id::wall_id;
			_backMap[i][c] = back_id::wall_id;
			_backMap[k][j] = back_id::wall_id;
			_backMap[k][c] = back_id::wall_id;
		}
	}
	//central garden beds 
	for (int i = _barrier + 113, k = _barrier + 338; i < _barrier + 235, k < _barrier + 460; i++, k++) {
		for (int j = _barrier + 252, c = _barrier + 527; j < _barrier + 422, c < _barrier + 697; j++, c++) {
			_backMap[i][j] = back_id::wall_id;
			_backMap[i][c] = back_id::wall_id;
			_backMap[k][j] = back_id::wall_id;
			_backMap[k][c] = back_id::wall_id;
		}
	}
}
void Map::backRespawnInit() {
	for (int i = _barrier + 60, k = _barrier + 420; i < _barrier + 160, k < _mainBackHeight - _barrier - 30; i++, k++) {
		for (int j = _barrier + 50, c = _mainBackWidth - _barrier - 147;
			j < _barrier + 147, c < _mainBackWidth - _barrier - 50; j++, c++) {
			_backMap[i][j] = back_id::allyRoadEnd_id;
			_backMap[i][c] = back_id::enemyRoadEnd_id;
			_backMap[k][j] = back_id::allyRoadEnd_id;
			_backMap[k][c] = back_id::enemyRoadEnd_id;
		}
	}
}
void Map::setBackMap(int indexRow, int indexColumn, int value) {
	_backMap[indexRow][indexColumn] = value;
}

Map::~Map() {
	if (_backMap != nullptr) {
		for (int i = 0; i < _mainBackHeight; i++)
			delete _backMap[i];
		delete _backMap;
	}
}
