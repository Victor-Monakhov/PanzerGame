#include "GameFace.h"

//private
void GameFace::border(COORD coord) {
	_draw.rectangle({ coord.X - 10, coord.Y - 10 }, { coord.X + 410, coord.Y }, RGB(0, 255, 0))
		.rectangle({ coord.X - 10, coord.Y }, { coord.X, coord.Y + 80 }, RGB(0, 255, 0))
		.rectangle({ coord.X + 400, coord.Y }, { coord.X + 410, coord.Y + 80 }, RGB(0, 255, 0))
		.rectangle({ coord.X - 10, coord.Y + 80 }, { coord.X + 410, coord.Y + 90 }, RGB(0, 255, 0));
}
const WCHAR* GameFace::showModel(Unit* unit) {
	switch (unit->getModel()) {
	case 1: return _pic.greenPanzer[unit->getTurnUnit()];
	case 2: return _pic.brownPanzer[unit->getTurnUnit()];
	case 3:	return _pic.whitePanzer[unit->getTurnUnit()];
	case 4: return _pic.yellowPanzer[unit->getTurnUnit()];
	case 5: return _pic.greyPanzer[unit->getTurnUnit()];
	}
}
const WCHAR* GameFace::showBullet(Unit* unit) {
	switch (unit->getBullet()->getTurn()) {
	case turn_id::right: return _pic.shot0;
	case turn_id::left: return _pic.shot0;
	case turn_id::bottom: return _pic.shot1;
	case turn_id::top: return _pic.shot1;
	}
}
const WCHAR* GameFace::showFire(Unit* unit) {
	switch (unit->getBullet()->getTurn()) {
	case turn_id::right: return _pic.fire0;
	case turn_id::left: return _pic.fire2;
	case turn_id::bottom: return _pic.fire1;
	case turn_id::top: return _pic.fire3;
	}
}
const WCHAR* GameFace::showBoom(Unit* unit) {
	if (unit->getId() == back_id::ally_id || unit->getId() == back_id::player_id) {
		return _pic.boom2;
	}
	else {
		return _pic.boom3;
	}
}
const WCHAR* GameFace::showDeath(Unit* unit) {
	if (unit->getId() == back_id::ally_id || unit->getId() == back_id::player_id) {
		return _pic.deathRed;
	}
	else {
		return _pic.deathBlue;
	}
}
int GameFace::healthArmorBalancer(short maxHealthArmor, short curHealthArmor) {
	int tempHealthArmor = curHealthArmor;
	switch (maxHealthArmor) {
	case 20: {
		tempHealthArmor = curHealthArmor * 2.5;
		break;
	}
	case 40: {
		tempHealthArmor = curHealthArmor * 1.25;
		break;
	}
	case 60: {
		tempHealthArmor = curHealthArmor * 0.8;
		break;
	}
	case 80: {
		tempHealthArmor = curHealthArmor * 0.625;
		break;
	}
	case 100: {
		tempHealthArmor = curHealthArmor / 2;
		break;
	}
	}
	return tempHealthArmor;
}
int GameFace::baseHealthBalancer(short maxHealthArmor, short curHealthArmor) {
	int tempHealthArmor = curHealthArmor;
	switch (maxHealthArmor) {
	case 150: {
		tempHealthArmor = curHealthArmor * 1.33;
		break;
	}
	case 200: {
		tempHealthArmor = curHealthArmor;
		break;
	}
	case 250: {
		tempHealthArmor = curHealthArmor * 0.8;
		break;
	}
	case 300: {
		tempHealthArmor = curHealthArmor * 0.66;
		break;
	}
	case 350: {
		tempHealthArmor = curHealthArmor * 0.57;
		break;
	}
	case 400: {
		tempHealthArmor = curHealthArmor * 0.5;
		break;
	}
	case 450: {
		tempHealthArmor = curHealthArmor * 0.44;
		break;
	}
	case 500: {
		tempHealthArmor = curHealthArmor * 0.4;
		break;
	}
	}
	return tempHealthArmor;
}
int GameFace::healthArmorBalancerExtra(short maxHealthArmor, short curHealthArmor) {
	short tempHealthArmor = curHealthArmor;
	switch (maxHealthArmor) {
	case 20: {
		tempHealthArmor = curHealthArmor * 10;
		break;
	}
	case 40: {
		tempHealthArmor = curHealthArmor * 5;
		break;
	}
	case 60: {
		tempHealthArmor = curHealthArmor * 3.33;
		break;
	}
	case 80: {
		tempHealthArmor = curHealthArmor * 2.5;
		break;
	}
	case 100: {
		tempHealthArmor = curHealthArmor * 2;
		break;
	}
	}
	return tempHealthArmor;
}
void GameFace::showShooting() {
	if (_cur->_ally.getBullet()->getSpeed() != 0)
		_draw.image(_cur->_ally.getBullet()->getCoord(), showBullet(&_cur->_ally));
	if (_cur->_player.getBullet()->getSpeed() != 0)
		_draw.image(_cur->_player.getBullet()->getCoord(), showBullet(&_cur->_player));
	if (_cur->_enemyTop.getBullet()->getSpeed() != 0)
		_draw.image(_cur->_enemyTop.getBullet()->getCoord(), showBullet(&_cur->_enemyTop));
	if (_cur->_enemyBottom.getBullet()->getSpeed() != 0)
		_draw.image(_cur->_enemyBottom.getBullet()->getCoord(), showBullet(&_cur->_enemyBottom));
	///
	if (_cur->_redBase.getBullet1()->getSpeed() != 0)
		_draw.image(_cur->_redBase.getBullet1()->getCoord(), showBullet(&_cur->_redBase));
	if (_cur->_redBase.getBullet2()->getSpeed() != 0)
		_draw.image(_cur->_redBase.getBullet2()->getCoord(), showBullet(&_cur->_redBase));
	if (_cur->_redBase.getBullet3()->getSpeed() != 0)
		_draw.image(_cur->_redBase.getBullet3()->getCoord(), showBullet(&_cur->_redBase));
	if (_cur->_redBase.getBullet4()->getSpeed() != 0)
		_draw.image(_cur->_redBase.getBullet4()->getCoord(), showBullet(&_cur->_redBase));
	///
	if (_cur->_blueBase.getBullet1()->getSpeed() != 0)
		_draw.image(_cur->_blueBase.getBullet1()->getCoord(), showBullet(&_cur->_blueBase));
	if (_cur->_blueBase.getBullet2()->getSpeed() != 0)
		_draw.image(_cur->_blueBase.getBullet2()->getCoord(), showBullet(&_cur->_blueBase));
	if (_cur->_blueBase.getBullet3()->getSpeed() != 0)
		_draw.image(_cur->_blueBase.getBullet3()->getCoord(), showBullet(&_cur->_blueBase));
	if (_cur->_blueBase.getBullet4()->getSpeed() != 0)
		_draw.image(_cur->_blueBase.getBullet4()->getCoord(), showBullet(&_cur->_blueBase));
}
void GameFace::showShotMoment(Unit* unit) {
	if (unit->getBullet()->getSpeed() == 2) _cnt = 1;
	else if (unit->getBullet()->getSpeed() == 3) _cnt = 2;
	COORD coord = unit->getBullet()->getCoord();
	if (unit->getBullet()->getSpeed()/2==1) {
		switch (unit->getTurnUnit()) {
		case turn_id::right: {
			_draw.image({ (short)(coord.X - _cnt*unit->getShotDistance()/10),
				(short)(coord.Y - 11 )}, showFire(unit));
			break;
		}
		case turn_id::left: {
				_draw.image({ (short)(coord.X - 30 + _cnt*unit->getShotDistance() / 10),
					(short)(coord.Y - 12) }, showFire(unit));
			break;
		}
		case turn_id::bottom: {
				_draw.image({ (short)(coord.X - 12),
					(short)(coord.Y - _cnt*unit->getShotDistance() / 10) },showFire(unit));
			break;
		}
		case turn_id::top: {
				_draw.image({ (short)(coord.X - 11),
					(short)(coord.Y - 30 + _cnt*unit->getShotDistance() / 10) }, showFire(unit));
			break;
		}
		}
	}
}
void GameFace::showHit(Unit* unit) {
	if (unit->getBullet()->miss() ||
		unit->getBullet()->hit() != 0){
		COORD coord = unit->getBullet()->getCoord();
		switch (unit->getTurnUnit()) {
		case turn_id::right: {
			_draw.image({ (short)(coord.X),(short)(coord.Y - 11) }, _pic.boom);
			break;
		}
		case turn_id::left: {
			_draw.image({ (short)(coord.X - 30),(short)(coord.Y - 12) }, _pic.boom);
			break;
		}
		case turn_id::bottom: {
			_draw.image({ (short)(coord.X - 12),(short)(coord.Y)}, _pic.boom);
			break;
		}
		case turn_id::top: {
			_draw.image({ (short)(coord.X - 11),(short)(coord.Y - 30) }, _pic.boom);
			break;
		}
		}
	}
}
void GameFace::showCrash(Unit* start, Unit* unit) {
	if (unit->getHealth() <= 0 && unit -> getRespawnTime() > start->getRespawnTime()/2) {
		_draw.image(unit->getDeadCoord(), showDeath(unit));
		if (unit->getRespawnTime() % 3 == 0)
			_draw.image({ unit->getDeadCoord().X + 12, unit->getDeadCoord().Y + 12 }, showBoom(unit));
	}
}
void GameFace::showHealth(Unit* unitStart, Unit* unit) {
	if (unit->getHealth() > 0) {
		COLORREF color = (unit->getId() == back_id::player_id ||
			unit->getId() == back_id::ally_id) ? RGB(255, 0, 0) : RGB(10, 60, 200);
		short tempHealth = healthArmorBalancer(unitStart->getHealth(), unit->getHealth());
		short tempArmor = healthArmorBalancer(unitStart->getArmor(), unit->getArmor());
		switch (unit->getTurnUnit()) {
		case turn_id::right: {
			_draw.rectangle({ unit->getCoord().X - 20, unit->getCoord().Y + 50 - tempArmor },
			{ unit->getCoord().X - 15, unit->getCoord().Y + 50 }, RGB(255, 255, 0))
				.rectangle({ unit->getCoord().X - 15, unit->getCoord().Y + 50 - tempHealth },
				{ unit->getCoord().X - 10, unit->getCoord().Y + 50 }, color)
				.rectangle({ unit->getCoord().X - 15, unit->getCoord().Y },
				{ unit->getCoord().X - 10, unit->getCoord().Y + 50 - tempHealth }, RGB(60, 50, 50))
				.rectangle({ unit->getCoord().X - 20, unit->getCoord().Y },
				{ unit->getCoord().X - 15, unit->getCoord().Y + 50 - tempArmor }, RGB(60, 50, 50));
			break;
		}
		case turn_id::bottom: {
			_draw.rectangle({ unit->getCoord().X + 50 - tempArmor, unit->getCoord().Y - 20 },
			{ unit->getCoord().X + 50, unit->getCoord().Y - 15 }, RGB(255, 255, 0))
				.rectangle({ unit->getCoord().X + 50 - tempHealth, unit->getCoord().Y - 15 },
				{ unit->getCoord().X + 50, unit->getCoord().Y - 10 }, color)
				.rectangle({ unit->getCoord().X, unit->getCoord().Y - 15 },
				{ unit->getCoord().X + 50 - tempHealth, unit->getCoord().Y - 10 }, RGB(60, 50, 50))
				.rectangle({ unit->getCoord().X, unit->getCoord().Y - 20 },
				{ unit->getCoord().X + 50 - tempArmor, unit->getCoord().Y - 15 }, RGB(60, 50, 50));
			break;
		}
		case turn_id::left: {
			_draw.rectangle({ unit->getCoord().X + 70, unit->getCoord().Y + 50 - tempArmor },
			{ unit->getCoord().X + 65, unit->getCoord().Y + 50 }, RGB(255, 255, 0))
				.rectangle({ unit->getCoord().X + 65, unit->getCoord().Y + 50 - tempHealth },
				{ unit->getCoord().X + 60, unit->getCoord().Y + 50 }, color)
				.rectangle({ unit->getCoord().X + 65, unit->getCoord().Y },
				{ unit->getCoord().X + 60, unit->getCoord().Y + 50 - tempHealth }, RGB(60, 50, 50))
				.rectangle({ unit->getCoord().X + 70, unit->getCoord().Y },
				{ unit->getCoord().X + 65, unit->getCoord().Y + 50 - tempArmor }, RGB(60, 50, 50));
			break;
		}
		case turn_id::top: {
			_draw.rectangle({ unit->getCoord().X + 50 - tempArmor, unit->getCoord().Y + 70 },
			{ unit->getCoord().X + 50, unit->getCoord().Y + 65 }, RGB(255, 255, 0))
				.rectangle({ unit->getCoord().X + 50 - tempHealth, unit->getCoord().Y + 65 },
				{ unit->getCoord().X + 50, unit->getCoord().Y + 60 }, color)
				.rectangle({ unit->getCoord().X, unit->getCoord().Y + 65 },
				{ unit->getCoord().X + 50 - tempHealth, unit->getCoord().Y + 60 }, RGB(60, 50, 50))
				.rectangle({ unit->getCoord().X, unit->getCoord().Y + 70 },
				{ unit->getCoord().X + 50 - tempArmor, unit->getCoord().Y + 65 }, RGB(60, 50, 50));
			break;
		}
		}
	}
}
void GameFace::showBaseHealth() {
	short tempHealth1 = baseHealthBalancer(_start->_redBase->getHealth(), _cur->_redBase.getHealth());
	short tempHealth2 = baseHealthBalancer(_start->_blueBase->getHealth(), _cur->_blueBase.getHealth());
	_draw.rectangle({ 10, 175 }, { 20, 375 - tempHealth1 }, RGB(60, 50, 50))
		.rectangle({ 930, 175 }, { 940, 375 - tempHealth2 }, RGB(60, 50, 50));
}
//public
GameFace::GameFace(Map* map, StartUnit* start, CurrentUnit* cur) :
	_map{ map },
	_draw{ Draw(1350, 950) },
	_start{ start },
	_cur{ cur },
	_cnt{}
{}
void GameFace::showPlayerMenu(Unit* unitStart, Unit* unit) {
	short tempPlayerHealth, tempPlayerArmor, tempAllyBotHealth, tempAllyBotArmor;
	
	if (unit->getId() == back_id::player_id) {
		tempPlayerHealth = healthArmorBalancerExtra(unitStart->getHealth(), unit->getHealth());
		tempPlayerArmor = healthArmorBalancerExtra(unitStart->getArmor(), unit->getArmor());
		tempPlayerArmor = (146 + tempPlayerArmor < 150) ? 4 : tempPlayerArmor;
		tempPlayerHealth = (146 + tempPlayerHealth < 152) ? 6 : tempPlayerHealth;
		_draw.textTransparence(true)
			.rectangle({ 146 + tempPlayerArmor , 600 }, { 346, 619 }, RGB(60, 50, 50))
			.rectangle({ 146 + tempPlayerHealth , 620 }, { 346, 641 }, RGB(60, 50, 50));
	}
	else {
		tempAllyBotHealth = healthArmorBalancerExtra(unitStart->getHealth(), unit->getHealth());
		tempAllyBotArmor = healthArmorBalancerExtra(unitStart->getArmor(), unit->getArmor());
		tempAllyBotHealth = (710 + tempAllyBotHealth < 712) ? 2 : tempAllyBotHealth;
		_draw.rectangle({ 710 + tempAllyBotArmor , 600 }, { 910, 619 }, RGB(60, 50, 50))
			.rectangle({ 710 + tempAllyBotHealth , 620 }, { 910, 641 }, RGB(60, 50, 50));
	}
	
	if (_cur->_player.getBestTime() < 10) {
		_draw.text("000", { 410, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(_cur->_player.getBestTime()), { 510, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL);
	}
	else if (_cur->_player.getBestTime() < 100) {
		_draw.text("00", { 410, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(_cur->_player.getBestTime()), { 480, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL);
	}
	else if (_cur->_player.getBestTime() < 1000) {
		_draw.text("0", { 410, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(_cur->_player.getBestTime()), { 450, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL);
	}
	else {
		_draw.text(to_string(_cur->_player.getBestTime()), { 420, 580 }, 90, 30, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.textTransparence(false);
	}
	_draw.image({ 70, 595 }, showModel(&_cur->_player))
		.image({ 630, 595 }, showModel(&_cur->_ally));
}
void GameFace::winGame() {
	_draw.textTransparence(true)
		.image({ 0,0 }, _pic.deskWin)
		.text("ÏÐÎÄÎËÆÈÒÜ", { 353,568 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÏÐÎÄÎËÆÈÒÜ", { 350,570 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Î×ÊÈ ÀÏÃÐÅÉÄÀ + 1", { 263,298 }, 80, 20, "Palatino Linotype", NULL, NULL)
		.text("Î×ÊÈ ÀÏÃÐÅÉÄÀ + 1", { 260,300 }, 80, 20, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÌÎÍÅÒÛ +" + to_string(_start->_player->getMoney() - _cur->_player.getMoney()),
		{ 303,378 }, 80, 20, "Palatino Linotype", NULL, NULL)
		.text("ÌÎÍÅÒÛ +" + to_string(_start->_player->getMoney() - _cur->_player.getMoney()),
		{ 300,380 }, 80, 20, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÍÀÃÐÀÄÀ", { 353,198 }, 80, 20, "Palatino Linotype", NULL, NULL)
		.text("ÍÀÃÐÀÄÀ", { 350,200 }, 80, 20, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÓÐÀ! ÃÅÐÎÈ×ÅÑÊÀß ÏÎÁÅÄÀ!", { 83,68 }, 120, 23, "Palatino Linotype", NULL, NULL)
		.text("ÓÐÀ! ÃÅÐÎÈ×ÅÑÊÀß ÏÎÁÅÄÀ!", { 80,70 }, 120, 23, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.textTransparence(false);
	border({ 285, 560 });
}
void  GameFace::drawEscape(COORD coord) {
	_draw.textTransparence(true)
		.image({ 0,0 }, _pic.deskEscape)
		.text("Òàíê", { 73,108 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Òàíê", { 70,110 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Çäîðîâüå", { 73,148 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Çäîðîâüå", { 70,150 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Áðîíÿ", { 73,188 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Áðîíÿ", { 70,190 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ñêîðîñòü", { 73,228 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ñêîðîñòü", { 70,230 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ñèëà", { 73,268 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ñèëà", { 70,270 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ñðàæåíèé", { 73,308 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ñðàæåíèé", { 70,310 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ïîáåä", { 73,348 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ïîáåä", { 70,350 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ïîðàæåíèé", { 73,388 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ïîðàæåíèé", { 70,390 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Î÷êè àïãðåéäà", { 73,428 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Î÷êè àïãðåéäà", { 70,430 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ìîíåòû", { 73,468 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ìîíåòû", { 70,470 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)

		.text("Óïðàâëåíèå", { 553,108 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Óïðàâëåíèå", { 550,110 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âëåâî", { 513,148 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Âëåâî", { 510,150 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âïðàâî", { 513,188 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Âïðàâî", { 510,190 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ââåðõ", { 513,228 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ââåðõ", { 510,230 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âíèç", { 513,268 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Âíèç", { 510,270 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âûñòðåë", { 513,308 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Âûñòðåë", { 510,310 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ïàóçà", { 513,348 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Ïàóçà", { 510,350 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âûõîä", { 513,388 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("Âûõîä", { 510,390 }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)

		.text("ÂÛÕÎÄ ÈÇ ÈÃÐÛ ÏÐÈÂÅÄÅÒ Ê ÏÎÐÀÆÅÍÈÞ!",
		{ 153,48 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("ÂÛÕÎÄ ÈÇ ÈÃÐÛ ÏÐÈÂÅÄÅÒ Ê ÏÎÐÀÆÅÍÈÞ!",
		{ 150,50 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(_start->_player->getName(), { 303,108 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(_start->_player->getName(), { 300,110 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getHealth()), { 303,148 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getHealth()), { 300,150 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getArmor()), { 303,188 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getArmor()), { 300,190 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getSpeed()), { 303,228 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getSpeed()), { 300,230 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getShotPower()), { 303,268 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getShotPower()), { 300,270 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getBattles()), { 303,308 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getBattles()), { 300,310 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getWins()), { 303,348 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getWins()), { 300,350 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getDefeat()), { 303,388 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getDefeat()), { 300,390 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getCommandPoints()), { 303,428 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getCommandPoints()), { 300,430 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(_start->_player->getMoney()), { 303,468 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text(to_string(_start->_player->getMoney()), { 300,470 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)

		.text("A", { 733,148 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("A", { 730,150 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("D", { 733,188 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("D", { 730,190 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("W", { 733,228 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("W", { 730,230 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("S", { 733,268 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("S", { 730,270 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("E", { 733,308 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("E", { 730,310 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("SPACE", { 733,348 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("SPACE", { 730,350 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("ESCAPE", { 733,388 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("ESCAPE", { 730,390 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)

		.text("ÏÐÎÄÎËÆÈÒÜ", { 133,568 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÏÐÎÄÎËÆÈÒÜ", { 130,570 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÂÛÕÎÄ", { 623,568 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÂÛÕÎÄ", { 620,570 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.textTransparence(false);
		border(coord);
}
void GameFace::isEscape(int key, bool& flag, COORD& coord) {
	if (key == KEY_ESCAPE) {
		coord = { 60, 560 };
		if (flag) flag = false;
		else flag = true;
	}
	if (flag) drawEscape(coord);
	if (key == KEY_LEFT && flag == true) {
		coord = { 60, 560 };
	}
	if (key == KEY_RIGHT && flag == true) {
		coord = { 485, 560 };
	}
	if (key == KEY_ENTER && flag == true) {
		flag = false;
		if (coord.X == 485) _cur->_redBase.setHealth(-1);
	}
}
void GameFace::paintGame(int controlAssistant, COORD& coord, bool& escape) {
	_draw.image(_map->getStartFieldCoord(), _pic.map);
	showCrash(_start->_ally, &_cur->_ally);
	showCrash(_start->_player, &_cur->_player);
	showCrash(_start->_enemyTop, &_cur->_enemyTop);
	showCrash(_start->_enemyBottom, &_cur->_enemyBottom);
	_draw.image(_cur->_player.getCoord(), showModel(&_cur->_player))
		.image(_cur->_enemyTop.getCoord(), showModel(&_cur->_enemyTop))
		.image(_cur->_enemyBottom.getCoord(), showModel(&_cur->_enemyBottom))
		.image(_cur->_ally.getCoord(), showModel(&_cur->_ally));
	showShooting();
	showShotMoment(&_cur->_ally);
	showShotMoment(&_cur->_player);
	showShotMoment(&_cur->_enemyTop);
	showShotMoment(&_cur->_enemyBottom);
	showHit(&_cur->_ally);
	showHit(&_cur->_player);
	showHit(&_cur->_enemyTop);
	showHit(&_cur->_enemyBottom);
	
	showHealth(_start->_enemyTop, &_cur->_enemyTop);
	showHealth(_start->_enemyBottom, &_cur->_enemyBottom);
	showHealth(_start->_ally, &_cur->_ally);
	showHealth(_start->_player, &_cur->_player);
	showBaseHealth();
	showPlayerMenu(_start->_player, &_cur->_player);
	showPlayerMenu(_start->_ally, &_cur->_ally);
	if (_cur->_blueBase.getHealth() <= 0) winGame();
	isEscape(controlAssistant, escape, coord);
	
	_draw.showPicture();
}

GameFace::~GameFace()
{}
