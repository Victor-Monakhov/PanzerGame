#include "Utilities.h"

Utilities::Utilities()
{
}
void Utilities::showCursor(bool showHide) {
	HANDLE window = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(window, &structCursorInfo);
	structCursorInfo.bVisible = showHide;
	SetConsoleCursorInfo(window, &structCursorInfo);
}
int Utilities::simpleVerticalArrowMenu(COORD startCoord, COORD& coord, short items, short step, bool& loop, int& iterator) {
	if (_kbhit()) {
		switch (_getch()) {
		case KEY_UP: {
			coord.Y -= step;
			--iterator;
			if (coord.Y < startCoord.Y) {
				coord.Y = coord.Y + (step * items);
				iterator = items - 1;
			}
			break;
		}
		case KEY_DOWN: {
			coord.Y += step;
			++iterator;
			if (coord.Y >(startCoord.Y + (step * (items - 1)))) {
				coord.Y = startCoord.Y;
				iterator = 0;
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		case KEY_ESCAPE: {loop = false; iterator = -1; break; }
		default: break;
		}
	}
	return iterator;
}
COORD Utilities::writerVerticalArrowMenu(COORD startCoord, COORD coord, short items, short step, bool& loop, char symbol) {
	if (_kbhit()) {
		COORD tempCoord = startCoord;
		switch (symbol) {
		case KEY_UP: {
			coord.Y -= step;
			if (coord.Y < tempCoord.Y) {
				coord.Y = coord.Y + (step * items);
			}
			break;
		}
		case KEY_DOWN: {
			coord.Y += step;
			if (coord.Y >(tempCoord.Y + (step * (items - 1)))) {
				coord.Y = tempCoord.Y;
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		case KEY_ESCAPE: {loop = false; coord = startCoord; break; }
		default: break;
		}
	}
	return coord;
}
COORD Utilities::dynamicEnterEscapeMenu(COORD startCoord, COORD coord, short items, short step, bool& loop, bool& escape, char symbol) {
	switch (symbol) {
	case KEY_ENTER: {
		coord.Y += step;
		if (coord.Y >(startCoord.Y + (step * (items - 1)))) { loop = false; }
		break;
	}
	case KEY_ESCAPE: {
		coord.Y -= step;
		if (coord.Y < startCoord.Y) { loop = false; escape = true; }
		break;
	}
	default: break;
	}
	return coord;
}
void Utilities::staticEnterEscapeMenu( bool& loop, bool& escape, char symbol) {
	switch (symbol) {
	case KEY_ENTER: {
		loop = false; 
		break;
	}
	case KEY_ESCAPE: {
		loop = false; escape = true; 
		break;
	}
	default: break;
	}
}
COORD Utilities::specialProfileArrowMenu( COORD coord, bool& loop) {
	if (_kbhit()) {
		char button;
		button = _getch();
		switch (button) {
		case KEY_UP: {
			coord.Y -= 350;
			if (coord.Y < 250) {
				coord.Y = 600;
			}
			break;
		}
		case KEY_DOWN: {
			coord.Y += 350;
			if (coord.Y > 600) {
				coord.Y = 250;
			}
			break;
		}
		case KEY_RIGHT: {
			coord.X += 450;
			if (coord.X > 500) {
				coord.X = 50;
			}
			break;
		}
		case KEY_LEFT: {
			coord.X -= 450;
			if (coord.X < 50) {
				coord.X = 500;
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		default: break;
		}
	}
	return coord;
}
COORD Utilities::specialPoligonArrowMenu(COORD start, COORD coord, bool& loop, short items, short step) {
	if (_kbhit()) {
		char button;
		button = _getch();
		switch (button) {
		case KEY_UP: {
			if (coord.X == 50) {
				coord.Y -= step;
			}
			if (coord.Y < start.Y) {
				coord.Y = coord.Y + (step * items);
			}
			break;
		}
		case KEY_DOWN: {
			if (coord.X == 50) {
				coord.Y += step;
			}
			if (coord.Y > start.Y + (step * (items - 1))) {
				coord.Y = start.Y;
			}
			break;
		}
		case KEY_RIGHT: {
			if (coord.X == 500 && coord.Y == 600) {
				coord = { 50, 600 };
			}
			else if (coord.X == 50 && coord.Y == 600) {
				coord = { 500, 600 };
			}
			break;
		}
		case KEY_LEFT: {
			if (coord.X == 50 && coord.Y == 600) {
				coord = { 500, 600 };
			}
			else if (coord.X == 500 && coord.Y == 600) {
				coord = { 50, 600 };
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		default: break;
		}
	}
	return coord;
}
void Utilities::simpleEnterEscapeTrueFalseArrowMenu(bool& left, bool& right, bool& loop, bool& escape) {
	if (_kbhit()) {
		char button;
		button = _getch();
		switch (button) {
		case KEY_LEFT: {
			left = true;
			break;
		}
		case KEY_RIGHT: {
			right = true;
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		case KEY_ESCAPE: {loop = false; escape = true; break; }
		default: break;
		}
	}
}
void Utilities::simpleTrueFalseArrowMenu(bool& left, bool& right, bool& loop, bool& escape) {
	if (_kbhit()) {
		char button;
		button = _getch();
		switch (button) {
		case KEY_LEFT: {
			left = true;
			break;
		}
		case KEY_RIGHT: {
			right = true;
			break;
		}
		case KEY_DOWN: {loop = false; break; }
		case KEY_ENTER: {loop = false; break; }
		case KEY_UP: {loop = false; escape = true; break; }
		case KEY_ESCAPE: {loop = false; escape = true; break; }
		default: break;
		}
	}
}




COORD Utilities::horizontalMenu1(COORD startCoord, COORD coord, short items, short step, bool& loop) {
	if (_kbhit()) {
		COORD tempCoord = startCoord;
		char button;
		button = _getch();
		switch (button) {
		case KEY_LEFT: {
			coord.X -= step;
			if (coord.X < tempCoord.X) {
				coord.X = coord.X + (step * items);
			}
			break;
		}
		case KEY_RIGHT: {
			coord.X += step;
			if (coord.X >(tempCoord.X + (step * (items - 1)))) {
				coord.X = tempCoord.X;
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		case KEY_ESCAPE: {loop = false; coord = { -1,-1 }; break; }
		default: break;
		}
	}
	return coord;
}
COORD Utilities::horizontalMenu2(COORD startCoord, COORD coord, short items, short step, bool& loop, bool& escape, char symbol) {
	switch (symbol) {
	case KEY_ENTER: {
		coord.X += step;
		if (coord.X >(startCoord.X + (step * (items - 1)))) { loop = false; }
		break;
	}
	case KEY_ESCAPE: {
		coord.X -= step;
		if (coord.X < startCoord.X) { loop = false; escape = true; }
		break;
	}
	default: break;
	}
	return coord;
}
COORD Utilities::horizontalMenu3(COORD startCoord, COORD coord, short items, short step, bool& loop) {
	if (_kbhit()) {
		COORD tempCoord = startCoord;
		char button;
		button = _getch();
		switch (button) {
		case KEY_LEFT: {
			coord.X -= step;
			if (coord.X < tempCoord.X) {
				coord.X = tempCoord.X;
			}
			break;
		}
		case KEY_RIGHT: {
			coord.X += step;
			if (coord.X >(tempCoord.X + (step * (items - 1)))) {
				coord.X = tempCoord.X +(step * (items-1));
			}
			break;
		}
		case KEY_ENTER: {loop = false; break; }
		case KEY_ESCAPE: {loop = false; coord = { -1,-1 }; break; }
		default: break;
		}
	}
	return coord;
}
char Utilities::writer (string& writing, const int symbolQuantity) {
	char symbol = '\0';
	if (_kbhit()) {
		int letterCounter;
		letterCounter = (writing == " ") ? writing.length() - 1 : writing.length();
		if (letterCounter > symbolQuantity) letterCounter = symbolQuantity;
		char* tempArr = new char[symbolQuantity + 2];
		static bool block224 = false;
		strcpy(tempArr, writing.c_str());
			symbol = _getch();
			//arrows return two values( 224='a'=-32 and personal)
			if ((symbol == KEY_UP || symbol == KEY_DOWN || symbol == KEY_RIGHT || symbol == KEY_LEFT) && block224 == true) {
				--letterCounter;
				if (letterCounter < 0) letterCounter = 0;
				tempArr[letterCounter] = '\0';
			}
			switch (symbol) {
			case KEY_BACKSPACE: {
				--letterCounter;
				if (letterCounter < 0) letterCounter = 0;
				tempArr[letterCounter] = '\0';
				break;
			}
			case KEY_ENTER: {break; }
			case KEY_ESCAPE: {break; }
			case KEY_UP: {if (block224 == true) { block224 = false; break; } }
			case KEY_DOWN: {if (block224 == true) { block224 = false; break; } }
			case KEY_LEFT: {if (block224 == true) { block224 = false; break; } }
			case KEY_RIGHT: {if (block224 == true) { block224 = false; break; } }
			case KEY_SPACE: {break; }
			default: {
				block224 = (symbol == 224 || symbol == 'à' || symbol == -32) ? true : false;
				tempArr[letterCounter] = symbol;
				tempArr[++letterCounter] = '\0';
				break;
			}
			}
		writing = "\0";
		for (int i = 0; i < strlen(tempArr); i++) {
			writing += tempArr[i];
		}
		delete[]tempArr;
	}
	return symbol;
}
bool Utilities::checkDigits(string str, char rangeFrom, char rangeTo) {
	bool result = true;
	for (int i = 0; i < str.length(); i++) {
		result = (str[i] >= rangeFrom && str[i] <= rangeTo);
		if (result == false) { break; }
	}
	return result;
}


Utilities::~Utilities()
{
}
