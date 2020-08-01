#pragma once
#include "Game.h"
#include "Utilities.h"
#include "PanzersFace.h"
#include "BotContainer.h"

class Panzers {
protected:
	int _size;
	bool _work;
	Map* _map;
	vector<Player> _panzer;
	Base _redBase;
	BotContainer _ai;
	Utilities _utility;
	PanzersFace _panzersFace;
	void addPanzer();
	void newPanzerName(bool& loop, int& iterator, int element);
	void newPanzerModel(bool& loop, int& iterator, int element);
	void goToCharacteristics(bool& loop, int& iterator, int element);
	void newPanzerHealth(bool& loop, int& iterator, int element);
	void newPanzerArmor(bool& loop, int& iterator, int element);
	void newPanzerSpeed(bool& loop, int& iterator, int element);
	void newPanzerShotPower(bool& loop, int& iterator, int element);
	void create(bool& loop, int& iterator, int element);
	virtual vector<Player> searchPanzer(int& result);
	void deletePanzer();
public:
	Panzers();
	Panzers(const Panzers& obj);
	void createPanzer(bool flag, int element);
	vector<Player> getPanzers()const {
		return _panzer;
	}
	~Panzers();
};

