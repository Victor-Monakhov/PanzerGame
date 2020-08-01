#include "StartGame.h"

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title TAHKÈ");
	system("mode con cols=135 lines=57");
	srand(time(NULL));
	StartGame _start;
	Utilities _utility;
	_utility.showCursor(false);
	_start.start();
	return 0;
}
