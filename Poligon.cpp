#include "Poligon.h"


Poligon::Poligon() :
	_poligonHeight{2430},
	_poligonWidth{2450},
	_poligonMap(Map({ 0,0 }, { 0,0 }, { 220, 180 }, { 0, 0 }, { 0, 0 }, {0, 0}, 3)),
	Panzers()
{}

void Poligon::wellComePoligone() {
	if (_size > 0) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 500,10 }, var._panzerNameCoord, _size + 1, 90, var._loopFirst, var._iterator);
			_panzersFace.drawAllPanzers(_panzer, var._panzerNameCoord, _size, var._loopFirst);
		}
		if (var._result == 0) {
			vector<Player> tempPanzer = Panzers::searchPanzer(var._result);
			if (var._result > 0 && _size > 0) {
				for (int i = 0; i < _size; i++) {
					if (_panzer[i].getName() == tempPanzer[var._result - 1].getName()) {
						trainig(&_panzer[i], i);
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			trainig(&_panzer[var._result - 1], var._result - 1);
		}
	}
}
void Poligon::poligonInit() {
	int barrier = _poligonMap.getBarrier();
	for (int i = barrier + 65, k = _poligonHeight - barrier - 60; i > 0, k < _poligonHeight; i--, k++) {
		for (int j = 0; j < _poligonWidth; j++) {
			_poligonMap.setBackMap(i, j, back_id::wall_id);
			_poligonMap.setBackMap(k, j, back_id::wall_id);
		}
	}
	for (int i = 0; i < _poligonHeight; i++) {
		for (int j = barrier + 95, k = _poligonWidth - barrier - 50; j > 55, k < _poligonWidth; j--, k++) {
			_poligonMap.setBackMap(i, j, back_id::wall_id);
			_poligonMap.setBackMap(i, k, back_id::wall_id);
		}
	}
}
void Poligon::trainig(Player* panzer, int element) {
	VariablesForUtilities var;
	poligonInit();
	panzer->setMap(&_poligonMap);
	panzer->setCoord(220, 180);
	panzer->setId(back_id::player_id);
	int controlAssistant = 0;
	while (var._loopFirst) {
		panzer->backClear();
		panzer->backFill();
		panzer->setPastCoord(panzer->getCoord().X, panzer->getCoord().Y);
		controlAssistant = panzer->controls(true);
		panzer->shot(nullptr, nullptr, nullptr);
		_poligonFace.drawPoligon(*panzer, var._panzerCharacteristicsCoord);
		if (controlAssistant == KEY_ENTER) createPanzer(false, element);
		if (controlAssistant == KEY_ESCAPE) var._loopFirst = false;
		Sleep(80);
	}
}


Poligon::~Poligon(){}