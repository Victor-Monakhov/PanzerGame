#include "Panzers.h"

Panzers::Panzers():
	_work {true},
	_size{},
	_map{ nullptr },
	_redBase{ Base() }
{}
Panzers::Panzers(const Panzers& obj) :
	_work{ obj._work },
	_size{ obj._size },
	_map{ obj._map },
	_redBase{ obj._redBase },
	_panzer{ obj._panzer }
{}
void Panzers::addPanzer() {
	_panzer.push_back(Player());
	_size = _panzer.size();
}
void Panzers::createPanzer(bool flag, int element) {
	VariablesForUtilities var;
	if (flag)addPanzer();
	if (_size > 0) {
		while (var._loopFirst) {
			element = (flag) ? _size - 1 : element;
			switch (var._iterator) {
			case 0: {
				if (!flag) { ++var._iterator; continue; }
				newPanzerName(var._loopFirst, var._iterator, element);
				break;
			}
			case 1: {
				if (!flag) { ++var._iterator; continue; }
				newPanzerModel(var._loopFirst, var._iterator, element);
				break;
			}
			case 2: {
				if (!flag) { ++var._iterator; continue; }
				goToCharacteristics(var._loopFirst, var._iterator, element);
				break;
			}
			case 3: {
				newPanzerHealth(var._loopFirst, var._iterator, element);
				if (!flag && var._iterator == 2) { var._loopFirst = false; }
				break;
			}
			case 4: {
				newPanzerArmor(var._loopFirst, var._iterator, element);
				break;
			}
			case 5: {
				newPanzerSpeed(var._loopFirst, var._iterator, element);
				break;
			}
			case 6: {
				newPanzerShotPower(var._loopFirst, var._iterator, element);
				break;
			}
			case 7: {
				create(var._loopFirst, var._iterator, element);
				break;
			}
			}
		}
	}
}
void Panzers::newPanzerName(bool& loop, int& iterator, int element) {
	if (loop == true) {
		bool busy = false;
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._escape = false;
			var._writing = _panzer[element].getName();
			_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
			var._symbol = _utility.writer(var._writing, var._symbolQuantity);
			_panzer[element].setName(var._writing);
			_panzersFace.drawNewPanzerName(var._panzerNameCoord, var._writing, busy);
			busy = false;
			if (var._escape == false) {
				if (_panzer[element].getName().size() < 2) {
					var._loopFirst = true;
					busy = true;
				}
			}
			if (var._escape == true) {
				auto it = _panzer.cbegin();
				_panzer.erase(it + element);
				_size = _panzer.size();
				loop = false;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::newPanzerModel(bool& loop, int& iterator, int element) {
	if (loop == true) {
		VariablesForUtilities var;
		bool pushLeft, pushRight;
		while (var._loopFirst) {
			pushLeft = false;
			pushRight = false;
			var._escape = false;
			_utility.simpleEnterEscapeTrueFalseArrowMenu(pushLeft, pushRight, var._loopFirst, var._escape);
			if (pushLeft && _panzer[element].getModel() > 1) {
				_panzer[element].setModel(_panzer[element].getModel() - 1);
			}
			else if (pushRight && _panzer[element].getModel() < 5) {
				_panzer[element].setModel(_panzer[element].getModel() + 1);
			}
			_panzersFace.drawNewPanzerModel(var._panzerModelCoord, _panzer[element], pushLeft, pushRight);
			if (var._escape == true) {
				--iterator;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::goToCharacteristics(bool& loop, int& iterator, int element) {
	VariablesForUtilities var;
	bool temp1, temp2;
	while (var._loopFirst) {
		var._escape = false;
		_utility.simpleEnterEscapeTrueFalseArrowMenu(temp1, temp2, var._loopFirst, var._escape);
		_panzersFace.drawNewPanzerModel(var._panzerCharacteristicsCoord, _panzer[element], false, false);
		if (var._escape == true) {
			--iterator;
			var._loopFirst = false;
		}
		if (!var._loopFirst && !var._escape) ++iterator;
	}
}
void Panzers::newPanzerHealth(bool& loop, int& iterator, int element) {
	if (loop == true) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._pushLeft = false;
			var._pushRight = false;
			var._escape = false;
			_utility.simpleTrueFalseArrowMenu(var._pushLeft, var._pushRight, var._loopFirst, var._escape);
			if (var._pushLeft && _panzer[element].getHealth() > 20) {
				_panzer[element].setHealth(_panzer[element].getHealth() - 20);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() + 1);
			}
			else if (var._pushRight && _panzer[element].getHealth() < 100 && _panzer[element].getCommandPoints() > 0) {
				_panzer[element].setHealth(_panzer[element].getHealth() + 20);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() - 1);
			}
			_panzersFace.drawNewPanzerCharacteristics(var._panzerHealthCoord, _panzer[element], var._pushLeft, var._pushRight);
			if (var._escape == true) {
				--iterator;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::newPanzerArmor(bool& loop, int& iterator, int element) {
	if (loop == true) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._pushLeft = false;
			var._pushRight = false;
			var._escape = false;
			_utility.simpleTrueFalseArrowMenu(var._pushLeft, var._pushRight, var._loopFirst, var._escape);
			if (var._pushLeft && _panzer[element].getArmor() > 20) {
				_panzer[element].setArmor(_panzer[element].getArmor() - 20);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() + 1);
			}
			else if (var._pushRight && _panzer[element].getArmor() < 100 && _panzer[element].getCommandPoints() > 0) {
				_panzer[element].setArmor(_panzer[element].getArmor() + 20);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() - 1);
			}
			_panzersFace.drawNewPanzerCharacteristics(var._panzerArmorCoord, _panzer[element], var._pushLeft, var._pushRight);
			if (var._escape == true) {
				--iterator;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::newPanzerSpeed(bool& loop, int& iterator, int element) {
	if (loop == true) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._pushLeft = false;
			var._pushRight = false;
			var._escape = false;
			_utility.simpleTrueFalseArrowMenu(var._pushLeft, var._pushRight, var._loopFirst, var._escape);
			if (var._pushLeft && _panzer[element].getSpeed() > 10) {
				_panzer[element].setSpeed(_panzer[element].getSpeed() - 3);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() + 1);
			}
			else if (var._pushRight && _panzer[element].getSpeed() < 22 && _panzer[element].getCommandPoints() > 0) {
				_panzer[element].setSpeed(_panzer[element].getSpeed() + 3);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() - 1);
			}
			_panzersFace.drawNewPanzerCharacteristics(var._panzerSpeedCoord, _panzer[element], var._pushLeft, var._pushRight);
			if (var._escape == true) {
				--iterator;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::newPanzerShotPower(bool& loop, int& iterator, int element) {
	if (loop == true) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._pushLeft = false;
			var._pushRight = false;
			var._escape = false;
			_utility.simpleTrueFalseArrowMenu(var._pushLeft, var._pushRight, var._loopFirst, var._escape);
			if (var._pushLeft && _panzer[element].getShotPower() > 1) {
				_panzer[element].setShotPower(_panzer[element].getShotPower() - 1);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() + 1);
			}
			else if (var._pushRight && _panzer[element].getShotPower() < 5 && _panzer[element].getCommandPoints() > 0) {
				_panzer[element].setShotPower(_panzer[element].getShotPower() + 1);
				_panzer[element].setCommandPoints(_panzer[element].getCommandPoints() - 1);
			}
			_panzersFace.drawNewPanzerCharacteristics(var._panzerShotPowerCoord, _panzer[element], var._pushLeft, var._pushRight);
			if (var._escape == true) {
				--iterator;
				var._loopFirst = false;
			}
			if (!var._loopFirst && !var._escape) ++iterator;
		}
	}
}
void Panzers::create(bool& loop, int& iterator, int element) {
	VariablesForUtilities var;
	bool temp1, temp2;
	while (var._loopFirst) {
		var._escape = false;
		_utility.simpleEnterEscapeTrueFalseArrowMenu(temp1, temp2, var._loopFirst, var._escape);
		_panzersFace.drawNewPanzerCharacteristics(var._panzerCharacteristicsCoord, _panzer[element], false, false);
		if (var._escape == true) {
			--iterator;
			var._loopFirst = false;
		}
		if (!var._loopFirst && !var._escape) loop = false;
	}
}
vector<Player> Panzers::searchPanzer(int& result) {
	string tempPanzerName;
	VariablesForUtilities var;
	int tempSize = 0;
	tempSize = _size;
	vector<Player> tempPanzer = _panzer;
	while (var._loopFirst) {
		_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
		var._symbol = _utility.writer(tempPanzerName, var._symbolQuantity);
		_panzersFace.drawSearchPanzer(var._panzerNameCoord, tempPanzerName);
		if (var._escape == true) tempPanzerName = "";
	}
	for (int i = 0; i < tempSize; ++i) {
		result = tempPanzer[i].getName().find(tempPanzerName);
		if (result == -1) {
			auto it = tempPanzer.cbegin();
			tempPanzer.erase(it + i);
			tempSize = tempPanzer.size();
			--i;
		}
	}
	while (var._loopSecond) {
		result = _utility.simpleVerticalArrowMenu({ 500,10 }, var._panzerNameCoord, tempSize + 1, 90, var._loopSecond, var._iterator);
		_panzersFace.drawAllPanzers(tempPanzer, var._panzerNameCoord, tempSize, var._loopSecond);
	}
	return tempPanzer;
}
void Panzers::deletePanzer() {
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
						auto it = _panzer.cbegin();
						_panzer.erase(it + i);
						_size = _panzer.size();
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			auto it = _panzer.cbegin();
			_panzer.erase(it + var._result - 1);
			_size = _panzer.size();
		}
	}
}

Panzers::~Panzers()
{}