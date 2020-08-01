#pragma once
#include "Game.h"

struct VariablesForUtilities{
private:
	friend class StartGame;
	friend class Profile;
	friend class Poligon;
	friend class Panzers;
	COORD _coordLeft = { 50,50 };
	COORD _leftChoose = { 50, 150 };
	COORD _coordRight = { 500,50 };
	COORD _rightChoose = { 500, 150 };
	COORD _panzerNameCoord = { 500, 10 };
	COORD _panzerModelCoord = {500, 280};
	COORD _panzerCharacteristicsCoord = { 500, 460 };
	COORD _panzerHealthCoord = { 500, 100 };
	COORD _panzerArmorCoord = { 500, 190 };
	COORD _panzerSpeedCoord = { 500, 280 };
	COORD _panzerShotPowerCoord = { 500, 370 };
	COORD _coordSpecial = { 50, 250 };
	COORD _coordSpecialPoligon = { 50,420 };
	string _writing;
	int _result = 0;
	int _iterator = 0;
	int _symbolQuantity = 10;
	bool _loopFirst = true;
	bool _loopSecond = true;
	bool _pushLeft = false;
	bool _pushRight = false;
	bool _escape = false;
	char _symbol = 224;
};

class Utilities
{
public:
	Utilities();
	void showCursor(bool showHide);
	void staticEnterEscapeMenu(bool& loop, bool& escape, char symbol);
	COORD dynamicEnterEscapeMenu(COORD startCoord, COORD coord, short items, short step, bool& loop, bool& escape, char symbol);
	int simpleVerticalArrowMenu(COORD startCoord, COORD& coord, short items, short step, bool& loop, int& iterator);
	COORD writerVerticalArrowMenu(COORD startCoord, COORD coord, short items, short step, bool& loop, char symbol);
	COORD specialProfileArrowMenu(COORD coord, bool& loop);
	COORD specialPoligonArrowMenu(COORD start, COORD coord, bool& loop, short items, short step);
	void simpleEnterEscapeTrueFalseArrowMenu(bool& left, bool& right, bool& loop, bool& escape);
	void simpleTrueFalseArrowMenu(bool& left, bool& right, bool& loop, bool& escape);



	COORD horizontalMenu1(COORD startCoord, COORD coord, short items, short step, bool& loop);
	COORD horizontalMenu2(COORD startCoord, COORD coord, short items, short step, bool& loop, bool& escape, char symbol);
	COORD horizontalMenu3(COORD startCoord, COORD coord, short items, short step, bool& loop);
	char writer(string& text, const int symbolQuantity);
	bool checkDigits(string str, char rangeFrom, char rangeTo);
	~Utilities();
};

