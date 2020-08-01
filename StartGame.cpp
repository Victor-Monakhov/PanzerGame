#include "StartGame.h"

//private
StartGame::StartGame() :
	_size{ 0 }
{
	initProfiles();
}
StartGame::StartGame(const StartGame& obj):
	_startFace{obj._startFace},
	_utility{obj._utility},
	_size{obj._size},
	_profile{obj._profile}
{}
void StartGame::addProfile() {
	_profile.push_back(Profile());
	_size = _profile.size();
}
void StartGame::initProfileCode() {
	_profile[_size - 1].setCode(0);
	for (short i = 0; i < _size - 1; i++) {
		if (_profile[_size - 1].getCode() == _profile[i].getCode()) {
			_profile[_size - 1].setCode(_profile[_size - 1].getCode() + 1);
			i = -1;
		}
	}
}
void StartGame::firstCharNameToUp(int element) {
		string temp = _profile[element].getName().c_str();
		temp[0] = toupper(temp[0]);
		_profile[element].setName(temp);
}
vector<Profile> StartGame::searchProfile(int& result) {
	string tempProfileName;
	VariablesForUtilities var;
	int tempSize = 0;
	tempSize = _size;
	vector<Profile>tempProfile = _profile;
	while (var._loopFirst) {
		_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
		var._symbol = _utility.writer(tempProfileName, var._symbolQuantity);
		_startFace.drawSearchProfile(var._coordRight, tempProfileName);
		if (var._escape == true) tempProfileName = "";
	}
	for (int i = 0; i < tempSize; ++i) {
		result = tempProfile[i].getName().find(tempProfileName);
		if (result == -1) {
			auto it = tempProfile.cbegin();
			tempProfile.erase(it + i);
			tempSize = tempProfile.size();
			--i;
		}
	}
	while (var._loopSecond) {
		result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, tempSize + 1, 100, var._loopSecond, var._iterator);
		_startFace.drawProfileChoice(tempProfile, var._coordRight, tempSize, var._loopSecond);
	}
	return tempProfile;
}
vector<Profile> StartGame::changeName(int result) {
	VariablesForUtilities var;
	bool busy = false;
	string tempProfileName = _profile[result - 1].getName();
	while (var._loopFirst) {
		var._escape = false;
		_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
		var._writing = _profile[result - 1].getName();
		_startFace.drawNewProfile(var._coordRight, var._writing, busy);
		busy = false;
		var._symbol = _utility.writer(var._writing, var._symbolQuantity);
		_profile[result - 1].setName(var._writing);
		firstCharNameToUp(result - 1);
		if (var._escape == false) {
			if (_profile[result - 1].getName().size() < 2) {
				var._loopFirst = true;
				busy = true;
			}
			for (short i = 0; i < _size; i++) {
				if (_profile[i].getName() == _profile[result - 1].getName() && i != result - 1) {
					busy = true;
					var._loopFirst = true;
				}
			}
		}
		if (var._escape == true) _profile[result - 1].setName(tempProfileName);
	}
	return _profile;
}
void StartGame::newProfile() {
	bool busy = false;
	VariablesForUtilities var;
	addProfile();
	initProfileCode();
	while (var._loopFirst) {
		 var._escape = false;
		_utility.staticEnterEscapeMenu(var._loopFirst, var._escape, var._symbol);
		var._writing = _profile[_size - 1].getName();
		_startFace.drawNewProfile(var._coordRight, var._writing, busy);
		busy = false;
		var._symbol = _utility.writer(var._writing, var._symbolQuantity);
		_profile[_size - 1].setName(var._writing);
		firstCharNameToUp(_size - 1);
		if (var._escape == false) {
			if (_profile[_size - 1].getName().size() < 2) {
				var._loopFirst = true;
				busy = true;
			}
			for (short i = 0; i < _size - 1; i++) {
				if (_profile[i].getName() == _profile[_size - 1].getName()) {
					busy = true;
					var._loopFirst = true;
				}
			}
		}
		if (var._escape == true) {
			auto it = _profile.cbegin();
			_profile.erase(it + _size - 1);
			_size = _profile.size();
		};
	}
}
void StartGame::profileChoice() {
	if (_size > 0) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, _size+1, 100, var._loopFirst, var._iterator);
			_startFace.drawProfileChoice(_profile, var._coordRight, _size, var._loopFirst);
		}
		if (var._result == 0) {
			vector<Profile> tempProfile = searchProfile(var._result);
			if (var._result > 0 && _size > 0) {
				for (int i = 0; i < _size; i++) {
					if (_profile[i].getName() == tempProfile[var._result - 1].getName()) {
						_profile[i].myProfile();
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			_profile[var._result - 1].myProfile();
		}
	}
}
void StartGame::deleteProfile() {
	if (_size > 0) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, _size + 1, 100, var._loopFirst, var._iterator);
			_startFace.drawProfileChoice(_profile, var._coordRight, _size, var._loopFirst);
		}
		if (var._result == 0) {
			vector<Profile> tempProfile = searchProfile(var._result);
			if (var._result > 0 && _size > 0) {
				for (int i = 0; i < _size; i++) {
					if (_profile[i].getName() == tempProfile[var._result - 1].getName()) {
						_profile[i].savePanzersAfterProfileDelete();
						auto it = _profile.cbegin();
						_profile.erase(it + i);
						_size = _profile.size();
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			_profile[var._result - 1].savePanzersAfterProfileDelete();
			auto it = _profile.cbegin();
			_profile.erase(it + var._result - 1);
			_size = _profile.size();
			var._result = 0;
		}
	}
}
void StartGame::profileChange() {
	if (_size > 0) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 500,50 }, var._coordRight, _size + 1, 100, var._loopFirst, var._iterator);
			_startFace.drawProfileChoice(_profile, var._coordRight, _size, var._loopFirst);
		}
		if (var._result == 0) {
			vector<Profile> tempProfile =  searchProfile(var._result);
			if (var._result > 0 && _size > 0) {
				for (int i = 0; i < _size; i++) {
					if (_profile[i].getName() == tempProfile[var._result - 1].getName()) {
						_profile = changeName(i+1);
						var._result = 0;
						break;
					}
				}
			}
		}
		if (var._result > 0 && _size > 0) {
			_profile = changeName(var._result);
			var._result = 0;
		}
	}
}
void StartGame::saveProfiles() {
	fstream memoryProfiles;
	memoryProfiles.open("memoryProfiles.txt", ios::out);
	for (short i = 0; i < _size; i++) {
		memoryProfiles << _profile[i];
		if (i < _size - 1) { memoryProfiles << endl; }
	}
	memoryProfiles.close();
}
void StartGame::initProfiles() {
	int counter = 0;
	vector<Profile> temp(1);
	fstream memoryProfiles;
	memoryProfiles.open("memoryProfiles.txt", ios::in);
	while (memoryProfiles.is_open() && memoryProfiles >> temp[counter]) {
		temp.push_back(Profile());
		++counter;
	}
	for (int i{}; i < counter; ++i) {
		_profile.push_back(temp[i]);
		_size = _profile.size();
		_profile[i].initPanzers();
	}
	memoryProfiles.close();
}
void StartGame::profileSort() {
	for (short i = 0; i < _size; i++) {
		for (short j = i + 1; j < _size; j++) {
			if (_profile[i].getName() > _profile[j].getName()) {
				swap(_profile[i], _profile[j]);
			}
		}
	}
}
//public
//main func
void StartGame::start() {
	_work = true;
	while (_work) {
		VariablesForUtilities var;
		while (var._loopFirst) {
			var._result = _utility.simpleVerticalArrowMenu({ 50,50 }, var._coordLeft, 5, 100, var._loopFirst, var._iterator);
			_startFace.drawMainPage(var._coordLeft);
		}
		switch (var._result) {
		case 0: {
			newProfile();
			profileSort();
			saveProfiles();
			break;
		}
		case 1: {
			profileChoice();
			break;
		}
		case 2: {
			deleteProfile();
			saveProfiles();
			break;
		}
		case 3: {
			profileChange();
			profileSort();
			saveProfiles();
			break;
		}
		case 4: {
			_work = false;
			break;
		}
		}
	}
}
StartGame::~StartGame()
{}
