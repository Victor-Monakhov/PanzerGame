#include "Profile.h"


Profile::Profile(string name, int code) :
	_name{name},
	_code{code},
	Poligon()
{}
Profile::Profile(const Profile& obj) 
{
	*this = obj;
}

string Profile::getName()const {
	return _name;
}
int Profile::getCode()const {
	return _code;
}
void Profile::setName(string name) {
	_name = name;
}
void Profile::setCode(int code) {
	_code = code;
}
//func        
bool Profile::operator>(const Profile& obj) {
	return (_name > obj._name);
}
bool Profile::operator<(const Profile& obj) {
	return (_name < obj._name);
}
Profile& Profile::operator=(const Profile& obj) {
	_name = obj._name;
	_code = obj._code;
	_work = obj._work;
	_size = obj._size;
	_map = obj._map;
	_redBase = obj._redBase;
	_panzer = obj._panzer;
	return *this;
}
Profile& Profile::operator=(Profile&& obj) {
	_name = obj._name;
	_code = obj._code;
	_work = obj._work;
	_size = obj._size;
	_map = obj._map;
	_redBase = obj._redBase;
	_panzer = obj._panzer;
	obj._name = "\0";
	obj._code = -1;
	obj._work = true;
	obj._size = 0;
	obj._map = nullptr;
	return *this;
}
ostream& operator<<(ostream& os, Profile& obj) {
	os << obj._name << " " << obj._code << " ";
	return os;
}
istream& operator >> (istream& is, Profile& obj) {
	is >> obj._name >> obj._code;
	return is;
}
void Profile::myProfile() {
	_work = true;
	while (_work) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._coordSpecial = _utility.specialProfileArrowMenu(var._coordSpecial, var._loopFirst);
			_profileFace.drawMainPage(var._coordSpecial);
		}
		if (var._coordSpecial.X == 50 && var._coordSpecial.Y == 250) {
			enterToFight();
			continue;
		}
		if (var._coordSpecial.X == 500 && var._coordSpecial.Y == 250) {
			myPanzers();
			continue;
		}
		if (var._coordSpecial.X == 50 && var._coordSpecial.Y == 600) {
			myGame();

			continue;
		}
		if (var._coordSpecial.X == 500 && var._coordSpecial.Y == 600) {
			_work = false;
			continue;
		}
	}
}
void Profile::myGame() {
	if (_size > 0) {
		bool loop = true;
		while (loop) {
			VariablesForUtilities var;
			while (var._loopSecond) {
				var._result = _utility.simpleVerticalArrowMenu({ 50,150 }, var._leftChoose, 4, 100, var._loopSecond, var._iterator);
				_profileFace.drawMyGamePage(var._leftChoose);
			}
			switch (var._result) {
			case 0: {
				////
				break;
			}
			case 1: {
				int temp = 0;
				while (var._loopFirst) {
					_utility.simpleVerticalArrowMenu({ 285, 560 }, var._leftChoose, 1, 0, var._loopFirst, temp);
					_profileFace.drawStatistic(_panzer);
				}
				break;
			}
			case 2: {
				/////
				break;
			}
			case 3: {
				loop = false;
				break;
			}
			}
		}
	}
	else {
		int temp = 0;
		VariablesForUtilities var;
		while (var._loopFirst) {
			_utility.simpleVerticalArrowMenu({ 286,403 }, var._leftChoose, 1, 0, var._loopFirst, temp);
			_profileFace.drawMessage2();
		}
	}
}
void Profile::myPanzers() {
	VariablesForUtilities var;
	while (var._loopFirst) {
		var._loopSecond = true;
		while (var._loopSecond) {
			var._coordSpecialPoligon = _utility.specialPoligonArrowMenu({ 50,420 }, var._coordSpecialPoligon, var._loopSecond, 3, 90);
			_panzersFace.drawMainPage(var._coordSpecialPoligon);
		}
		if (var._coordSpecialPoligon.X == 50 && var._coordSpecialPoligon.Y == 420) {
			wellComePoligone();
			savePanzers();
			continue;
		}
		if (var._coordSpecialPoligon.X == 50 && var._coordSpecialPoligon.Y == 510) {
			createPanzer(true, 0);
			if (_size > 0) {
				for(int i = 0; i < _size; i++)
				_panzer[i].setCode(_code);
			}
			savePanzers();
			continue;
		}
		if (var._coordSpecialPoligon.X == 50 && var._coordSpecialPoligon.Y == 600) {
			deletePanzer();
			savePanzers();
			continue;
		}
		if (var._coordSpecialPoligon.X == 500 && var._coordSpecialPoligon.Y == 600) {
			var._loopFirst = false;
			savePanzers();
			continue;
		}
	}
}
void Profile::enterToFight() {
	if (_size > 0) {
		bool loop = true;
		while (loop) {
			VariablesForUtilities var;
			while (var._loopSecond) {
				var._result = _utility.simpleVerticalArrowMenu({ 50,150 }, var._leftChoose, 5, 100, var._loopSecond, var._iterator);
				_profileFace.drawHardChoosePage(var._leftChoose);
			}
			switch (var._result) {
			case 0: {
				gameBegin(&_bc.easyEnemyTop, &_bc.easyEnemyBottom, &_bc.easyAlly, &_bc.easyBlueBase);
				loop = false;
				break;
			}
			case 1: {
				gameBegin(&_bc.middleEnemyTop, &_bc.middleEnemyBottom, &_bc.middleAlly, &_bc.middleBlueBase);
				loop = false;
				break;
			}
			case 2: {
				gameBegin(&_bc.hardEnemyTop, &_bc.hardEnemyBottom, &_bc.hardAlly, &_bc.hardBlueBase);
				loop = false;
				break;
			}
			case 3: {
				gameBegin(&_bc.killerEnemyTop, &_bc.killerEnemyBottom, &_bc.killerAlly, &_bc.killerBlueBase);
				loop = false;
				break;
			}
			case 4: {
				loop = false;
				break;
			}
			}	
		}
	}
	else {
		int temp = 0;
		VariablesForUtilities var;
		while (var._loopFirst) {
			_utility.simpleVerticalArrowMenu({ 286,403 }, var._leftChoose, 1, 0, var._loopFirst, temp);
			_profileFace.drawMessage1();
		}
	}
}
vector<Player> Profile::searchPanzer(int& result) {
	string tempPanzerName;
	VariablesForUtilities var;
	int tempSize = 0;
	tempSize = _size;
	vector<Player> tempPanzer = _panzer;
	while (var._loopFirst) {
		_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
		var._symbol = _utility.writer(tempPanzerName, var._symbolQuantity);
		_profileFace.drawSearchPanzer(var._rightChoose, tempPanzerName);
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
		result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, tempSize + 1, 100, var._loopSecond, var._iterator);
		_profileFace.drawAllPanzers(tempPanzer, var._coordRight, tempSize, var._loopSecond);
	}
	return tempPanzer;
}
void Profile::gameBegin(Bot* enemyTop, Bot* enemyBottom, Bot* ally, Base* blueBase) {
	if (_size > 0) {
		Map map;
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, _size + 1, 100, var._loopFirst, var._iterator);
			_profileFace.drawAllPanzers(_panzer, var._coordRight, _size, var._loopFirst);
		}
		if (var._result == 0) {
			vector<Player> tempPanzer = searchPanzer(var._result);
			if (var._result > 0 && _size > 0) {
				for (int i = 0; i < _size; i++) {
					if (_panzer[i].getName() == tempPanzer[var._result - 1].getName()) {
						Game game(&map, enemyTop, enemyBottom, ally, &_panzer[i], &_redBase, blueBase);
						game.run();
						savePanzers();
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			Game game(&map, enemyTop, enemyBottom, ally, &_panzer[var._result - 1], &_redBase, blueBase);
			game.run();
			savePanzers();
		}
	}
}
void Profile::savePanzers() {
	int  tempSize = 0, counter = 0, counter2 = 0;
	vector<Player> temp(1);
	fstream memoryPanzers;
	memoryPanzers.open("memoryPanzers.txt", ios::in);
	while (memoryPanzers >> temp[counter] && memoryPanzers.is_open()) {
		temp.push_back(Player());
		if (_size > 0 && temp[counter].getCode() == _code) {
			++tempSize;
		}
		++counter;
	}
	if (tempSize < _size) {
		for (int i{ tempSize }; i < _size; ++i) {
			temp.push_back(Player());
			temp[counter++] = _panzer[i];
		}
	}
	for (int i{}; i < counter; ++i) {
		bool del = true;
		if (temp[i].getCode() == _code) {
			for (int k{}; k < _size; ++k) {
				if (temp[i].getName() == _panzer[k].getName()) {
					del = false;
					break;
				}
			}
			if (del == true && counter > 0) {
				auto it = temp.cbegin();
				temp.erase(it + i);
				--counter;
				--i;
			}
			else {
				temp[i] = _panzer[counter2];
				++counter2;
			}
		}
	}
	memoryPanzers.close();
	memoryPanzers.open("memoryPanzers.txt", ios::out);
	for (int i{}; i < counter; ++i) {
		memoryPanzers << temp[i];
		if (i < counter - 1) { memoryPanzers << endl; }
	}
	memoryPanzers.close();
}
void Profile::initPanzers() {
	int counter = 0;
	vector<Player>temp(1);
	fstream memoryPanzers;
	memoryPanzers.open("memoryPanzers.txt", ios::in);
	while (memoryPanzers.is_open() && memoryPanzers >> temp[counter] ) {
		temp.push_back(Player());
		++counter;
	}
	for (int i{}; i < counter; ++i) {
		if (temp[i].getCode() == _code) {
			_panzer.push_back(temp[i]);
			_size = _panzer.size();
		}
	}
	memoryPanzers.close();
}
void Profile::savePanzersAfterProfileDelete() {
	short counter = 0, counter2 = 0;
	vector<Player>temp(1);
	fstream memoryPanzers;
	memoryPanzers.open("memoryPanzers.txt", ios::in);
	while (memoryPanzers.is_open() && memoryPanzers >> temp[counter]) {
		temp.push_back(Player());
		counter++;
	}
	for (int i{}; i < counter; ++i) {
		if (temp[i].getCode() == _code) {
			auto it = temp.cbegin();
			temp.erase(it + i);
			--counter;
			--i;
		}
	}
	memoryPanzers.close();
	memoryPanzers.open("memoryPanzers.txt", ios::out);
	for (int i{}; i < counter; ++i) {
		memoryPanzers << temp[i];
		if (i < counter - 1) { memoryPanzers << endl; }
	}
	memoryPanzers.close();
}

Profile::~Profile()
{}






