#pragma once

#include "Picture.h"
#include "Draw.h"
#include "Bot.h"
#include "Player.h"
#include "Base.h"

struct StartUnit {
private:
	friend class GameFace;
	friend class Game;
	Bot* _enemyTop = nullptr;
	Bot* _enemyBottom = nullptr;
	Bot* _ally = nullptr;
	Player* _player = nullptr;
	Base* _redBase = nullptr;
	Base* _blueBase = nullptr;
};

struct CurrentUnit {
private:
	friend class GameFace;
	friend class Game;
	Bot _enemyTop;
	Bot _enemyBottom;
	Bot _ally;
	Player _player;
	Base _redBase;
	Base _blueBase;
};


class GameFace {
protected:
	Picture _pic;
	Draw _draw;
	Map* _map;
	StartUnit* _start;
	CurrentUnit* _cur;
	int _cnt;
	void border(COORD coord);
	const WCHAR* showModel(Unit* unit);
	const WCHAR* showBullet(Unit* unit);
	const WCHAR* showFire(Unit* unit);
	const WCHAR* showBoom(Unit* unit);
	const WCHAR* showDeath(Unit* unit);
	int healthArmorBalancer(short maxHealthArmor, short curHealthArmor);
	int baseHealthBalancer(short maxHealthArmor, short curHealthArmor);
	int healthArmorBalancerExtra(short maxHealthArmor, short curHealthArmor);
	void showPlayerMenu(Unit* unitStart, Unit* unit);
	void showShooting();
	void showShotMoment(Unit* unit);
	void showHit(Unit* unit);
	void showCrash(Unit* start, Unit* unit);
	void showHealth(Unit* unitStart, Unit* unit);
	void winGame();
	void showBaseHealth();
	void isEscape(int key, bool& flag, COORD& coord);
public:
	GameFace(Map* map = nullptr, StartUnit* start = nullptr, CurrentUnit* cur = nullptr);
	void drawEscape(COORD coord);
	void paintGame(int controlAssistant, COORD& coord, bool& escape);
	~GameFace();
};

