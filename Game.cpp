#include "Game.h"

//private

void Game::preparation() {
	_map->init();
	_cur._enemyTop.setMap(_map);
	_cur._enemyBottom.setMap(_map);
	_cur._ally.setMap(_map);
	_cur._player.setMap(_map);
	_cur._redBase.setMap(_map);
	_cur._blueBase.setMap(_map);

	_cur._enemyTop.setCoord(_map->getEnemyTopCoord().X, _map->getEnemyTopCoord().Y);
	_cur._enemyBottom.setCoord(_map->getEnemyBottomCoord().X, _map->getEnemyBottomCoord().Y);
	_cur._ally.setCoord(_map->getAllyBottomCoord().X, _map->getAllyBottomCoord().Y);
	_cur._player.setCoord(_map->getPlayerCoord().X, _map->getPlayerCoord().Y);
	_cur._redBase.setCoord(_map->getRedBaseCoord().X, _map->getRedBaseCoord().Y);
	_cur._blueBase.setCoord(_map->getBlueBaseCoord().X, _map->getBlueBaseCoord().Y);

	_start._enemyTop->setCoord(_map->getEnemyTopCoord().X, _map->getEnemyTopCoord().Y);
	_start._enemyBottom->setCoord(_map->getEnemyBottomCoord().X, _map->getEnemyBottomCoord().Y);
	_start._ally->setCoord(_map->getAllyBottomCoord().X, _map->getAllyBottomCoord().Y);
	_start._player->setCoord(_map->getPlayerCoord().X, _map->getPlayerCoord().Y);
	_start._redBase->setCoord(_map->getRedBaseCoord().X, _map->getRedBaseCoord().Y);
	_start._blueBase->setCoord(_map->getBlueBaseCoord().X, _map->getBlueBaseCoord().Y);

	_cur._enemyTop.setTurnUnit(_map->getStartEnemyTurn());
	_cur._enemyBottom.setTurnUnit(_map->getStartEnemyTurn());
	_cur._ally.setTurnUnit(_map->getStartPlayerTurn());
	_cur._player.setTurnUnit(_map->getStartPlayerTurn());
	_cur._redBase.setTurnUnit(_map->getStartPlayerTurn());
	_cur._blueBase.setTurnUnit(_map->getStartEnemyTurn());

	_start._enemyTop->setTurnUnit(_map->getStartEnemyTurn());
	_start._enemyBottom->setTurnUnit(_map->getStartEnemyTurn());
	_start._ally->setTurnUnit(_map->getStartPlayerTurn());
	_start._player->setTurnUnit(_map->getStartPlayerTurn());
	_start._redBase->setTurnUnit(_map->getStartPlayerTurn());
	_start._blueBase->setTurnUnit(_map->getStartEnemyTurn());

	_cur._enemyTop.setId(back_id::enemyTop_id);
	_cur._enemyBottom.setId(back_id::enemyBottom_id);
	_cur._ally.setId(back_id::ally_id);
	_cur._player.setId(back_id::player_id);
	_cur._redBase.setId(back_id::redBase_id);
	_cur._blueBase.setId(back_id::blueBase_id);

	_cur._player.setBestTime(0);
}
void Game::unitBackFill() {
	_cur._player.backClear();
	_cur._ally.backClear();
	_cur._enemyTop.backClear();
	_cur._enemyBottom.backClear();
	_map->backRespawnInit();
	_cur._player.backFill();
	_cur._ally.backFill();
	_cur._enemyTop.backFill();
	_cur._enemyBottom.backFill();
	_cur._player.setPastCoord(_cur._player.getCoord().X, _cur._player.getCoord().Y);
	_cur._ally.setPastCoord(_cur._ally.getCoord().X, _cur._ally.getCoord().Y);
	_cur._enemyTop.setPastCoord(_cur._enemyTop.getCoord().X, _cur._enemyTop.getCoord().Y);
	_cur._enemyBottom.setPastCoord(_cur._enemyBottom.getCoord().X, _cur._enemyBottom.getCoord().Y);
}
void Game::logicBotLife(Unit* current) {
	if (current->getHealth() > 0) {
		switch (current->getId()) {
		case back_id::ally_id: {
			if (_cur._enemyBottom.getHealth() > 0 && (_random == 2 || _random == 3 || _random ==4))
				_cur._ally.hunt(_cur._enemyBottom);
			else if (_cur._enemyTop.getHealth() > 0 && (_random == 1 || _random == 5)) _cur._ally.hunt(_cur._enemyTop);
			else _cur._ally.hunt(_cur._blueBase);
			break;
		}
		case back_id::enemyTop_id: {
			if (_cur._player.getHealth() > 0 && ( _random == 3 || _random == 4))
				_cur._enemyTop.hunt(_cur._player);
			else if (_cur._ally.getHealth() > 0 && ( _random == 1 || _random == 5)) _cur._enemyTop.hunt(_cur._ally);
			else _cur._enemyTop.hunt(_cur._redBase);
			break;
		}
		case back_id::enemyBottom_id: {
			if (_cur._ally.getHealth() > 0 && (_random == 2 || _random == 4))
				_cur._enemyBottom.hunt(_cur._ally);
			else if (_cur._player.getHealth() > 0 && (_random == 1 || _random == 5)) _cur._enemyBottom.hunt(_cur._player);
			else _cur._enemyBottom.hunt(_cur._redBase);
			break;
		}
		}
	}
}
void Game::death(Unit* start, Unit* current) {
	if (current->getHealth() <= 0 && current->getRespawnTime() == start->getRespawnTime()) {
		current->setDeadCoord(current->getCoord().X, current->getCoord().Y);
		current->setTurnUnit(start->getTurnUnit());
		current->setCoord(start->getCoord().X, start->getCoord().Y);
	}
	if (current->getHealth() <= 0)
	current->setRespawnTime(current->getRespawnTime() - 1);
}
void Game::rebirth(Unit* start, Unit* current) {
	if (current->getRespawnTime() <= 0) {
		current->setRespawnTime(start->getRespawnTime());
		current->setArmor(start->getArmor());
		current->setHealth(start->getHealth());
	}
}

bool Game::pause(int key, bool& flag) {
	if (key == KEY_SPACE) {
		if (flag) flag = false;
		else flag = true;
	}
	return flag;
}
void Game::isWin(int controlAssistant, bool& gameOver, bool& oneTimeWin) {
	if (_cur._blueBase.getHealth() <= 0) {
		if (oneTimeWin) {
			_start._player->setWins(_start._player->getWins() + 1);
			_start._player->setBattles(_start._player->getBattles() + 1);
			_start._player->setCommandPoints(_start._player->getCommandPoints() + 1);
			_start._player->setMoney(_start._player->getMoney() + rand() % 51 + 50);
			if(_start._player ->getBestTime() > _cur._player.getBestTime() || _start._player->getBestTime() == 0)
				_start._player->setBestTime(_cur._player.getBestTime());
			if (_start._player->getWins() % 3 == 0) _start._player->setLevel(_start._player->getLevel() + 1);
			oneTimeWin = false;
		}
		if (controlAssistant == KEY_ENTER)gameOver = true;
	}
}
void Game::isDefeat(int controlAssistant, bool& gameOver) {
	if (_cur._redBase.getHealth() <= 0) {
		gameOver = true;
		_start._player->setDefeat(_start._player->getDefeat() + 1);
		_start._player->setBattles(_start._player->getBattles() + 1);
	}
}
//public
Game::Game(Map* map, Bot* enemyTop, Bot* enemyBottom, Bot* ally, Player* player, Base* redBase, Base* blueBase) :
	_map{ map },
	_gameFace{ GameFace(map, &_start, &_cur) },
	_random { rand() % 5 + 1 }
{
		_start._enemyTop = enemyTop;
		_start._enemyBottom = enemyBottom;
		_start._ally = ally;
		_start._player = player;
		_start._redBase = redBase;
		_start._blueBase = blueBase;
		_cur._enemyTop = *enemyTop;
		_cur._enemyBottom = *enemyBottom;
		_cur._ally = *ally;
		_cur._player = *player;
		_cur._redBase = *redBase;
		_cur._blueBase = *blueBase;
}

void Game::run() {
	int controlAssistant = 0;
	int counter = 0;
	bool tempPause = false;
	bool tempEscape = false;
	bool gameOver = false;
	bool oneTimeWin = true;
	COORD tempCoord = { 0,0 };
	preparation();
	_cur._redBase.backBaseFill();
	_cur._blueBase.backBaseFill();
	while (!gameOver) {
		if (_cur._redBase.getHealth() > 0 &&
			_cur._blueBase.getHealth() > 0 &&
			!tempPause && !tempEscape) {
			counter++;
			if (counter > 100000) counter = 0;
			if (counter % 12 == 0) {
				_cur._player.setBestTime(counter / 12);
			}
			if (counter % 480 == 0) {
				_random = rand() % 5 + 1;
			}
			unitBackFill();
			logicBotLife(&_cur._enemyTop);
			logicBotLife(&_cur._enemyBottom);
			logicBotLife(&_cur._ally);
			_cur._player.shot(&_cur._enemyBottom, &_cur._enemyTop, &_cur._blueBase);
			_cur._ally.shot(&_cur._enemyBottom, &_cur._enemyTop, &_cur._blueBase);
			_cur._enemyTop.shot(&_cur._player, &_cur._ally, &_cur._redBase);
			_cur._enemyBottom.shot(&_cur._ally, &_cur._player, &_cur._redBase);
			_cur._redBase.shot(&_cur._enemyBottom, &_cur._enemyTop);
			_cur._blueBase.shot(&_cur._ally, &_cur._player);

			death(_start._enemyTop, &_cur._enemyTop);
			death(_start._enemyBottom, &_cur._enemyBottom);
			death(_start._ally, &_cur._ally);
			death(_start._player, &_cur._player);
			rebirth(_start._enemyTop, &_cur._enemyTop);
			rebirth(_start._enemyBottom, &_cur._enemyBottom);
			rebirth(_start._ally, &_cur._ally);
			rebirth(_start._player, &_cur._player);
		}
		controlAssistant = _cur._player.controls(!pause(controlAssistant, tempPause) || tempEscape);
		_gameFace.paintGame(controlAssistant, tempCoord, tempEscape);
		isWin(controlAssistant, gameOver, oneTimeWin);
		isDefeat(controlAssistant, gameOver);
		Sleep(80);
	}
}

Game::~Game()
{}
