#include "ProfileFace.h"



ProfileFace::ProfileFace()
{}

void ProfileFace::drawStartMenu() {
	_draw.text("� ���!!!", { 183,258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("� ���!!!", { 180,260 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("��� �����", { 583,258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("��� �����", { 580,260 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("��� ����", { 153,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("��� ����", { 150,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("�����", { 643,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�����", { 640,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void ProfileFace::drawChooseMenu() {
	_draw.text("��������", { 63,58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("��������", { 60,60 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("������", { 63,158 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("������", { 60,160 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("�������", { 63,258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�������", { 60,260 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("�������", { 63,358 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�������", { 60,360 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("����� �������", { 63,458 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����� �������", { 60,460 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("�����", { 63,558 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�����", { 60,560 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void ProfileFace::drawHardChoosePage(const COORD& coord) {
	_draw.image({ 0,0 }, _pic.deskProfileUniversalTwo);
	border(coord);
	_draw.textTransparence(true);
	drawChooseMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void ProfileFace::drawMainPage(const COORD& coord) {
	_draw.image({ 0,0 }, _pic.deskProfileMenu);
	border(coord);
	_draw.textTransparence(true);
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void ProfileFace::drawMessage1() {
	_draw.image({ 0,0 }, _pic.deskError)
		.textTransparence(true)
		.text("� ��� ��� �����!", { 343,148 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("� ��� ��� �����!", { 340,150 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("�������� ���� ��� ��", { 303,208 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�������� ���� ��� ��", { 300,210 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("������ ��������", { 343,268 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("������ ��������", { 340,270 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("����������", { 353,398 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����������", { 350,400 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.textTransparence(false);
	border({ 276, 393 });
	_draw.showPicture();
}
void ProfileFace::drawMessage2() {
	_draw.image({ 0,0 }, _pic.deskError)
		.textTransparence(true)
		.text("� ��� ��� �����!", { 343,148 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("� ��� ��� �����!", { 340,150 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("�������� ���� ��� ��", { 303,208 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�������� ���� ��� ��", { 300,210 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("����� � '��� ����'", { 323,268 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����� � '��� ����'", { 320,270 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("����������", { 353,398 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����������", { 350,400 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.textTransparence(false);
	border({ 276, 393 });
	_draw.showPicture();
}
void ProfileFace::drawMyGameMenu() {
	_draw.text("��� ����", { 63,58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("��� ����", { 60,60 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("�������", { 63,158 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�������", { 60,160 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("����������", { 63,258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����������", { 60,260 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("����������", { 63,358 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("����������", { 60,360 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("�����", { 63,458 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�����", { 60,460 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void ProfileFace::drawMyGamePage(const COORD& coord) {
	_draw.image({ 0,0 }, _pic.deskMyGame);
	border(coord);
	_draw.textTransparence(true);
	drawMyGameMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void ProfileFace::drawStatistic(vector<Player> panzers) {
	for (int i = 0; i < panzers.size(); i++) {
		for (int j = i + 1; j < panzers.size(); j++) {
			if (panzers[i].getWins() < panzers[j].getWins()) {
				swap(panzers[i], panzers[j]);
			}
		}
	}
	_draw.image({ 0,0 }, _pic.deskStatistics)
		.textTransparence(true)
		.text("�", { 63,38 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("�", { 60,40 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("1", { 68,103 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("1", { 65,105 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("2", { 68,168 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("2", { 65,170 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("3", { 68,233 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("3", { 65,235 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("4", { 68,298 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("4", { 65,300 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("5", { 68,363 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("5", { 65,365 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("6", { 68,428 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("6", { 65,430 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("7", { 68,493 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("7", { 65,495 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("����", { 108,38 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("����", { 105,40 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("�����", { 353,38 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("�����", { 350,40 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("���������", { 488,38 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("���������", { 485,40 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("��������", { 703,38 }, 40, 12, "Palatino Linotype", NULL, NULL)
		.text("��������", { 700,40 }, 40, 12, "Palatino Linotype", RGB(255, 0, 0), NULL);
		short y = 105, barrier = (panzers.size() < 7) ? panzers.size() : 7;
	for (int i = 0; i < barrier; i++) {
		_draw.text(panzers[i].getName(), { 108,y - 2 }, 40, 12, "Palatino Linotype", NULL, NULL)
			.text(panzers[i].getName(), { 105,y }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(panzers[i].getWins()), { 403,y - 2 }, 40, 12, "Palatino Linotype", NULL, NULL)
			.text(to_string(panzers[i].getWins()), { 400,y }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(panzers[i].getDefeat()), { 593,y - 2 }, 40, 12, "Palatino Linotype", NULL, NULL)
			.text(to_string(panzers[i].getDefeat()), { 590,y }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL)
			.text(to_string(panzers[i].getBattles()), { 803,y - 2 }, 40, 12, "Palatino Linotype", NULL, NULL)
			.text(to_string(panzers[i].getBattles()), { 800,y }, 40, 12, "Palatino Linotype", RGB(255, 255, 255), NULL);
		y += 65;
	}
	_draw.text("�����", { 413,568 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�����", { 410,570 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
	border({ 285, 560 });
	_draw.textTransparence(false)
		.showPicture();
}
void ProfileFace::drawAllPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) {
	_draw.image({ 0,0 }, _pic.deskProfileUniversalTwo)
		.textTransparence(true);
	drawChooseMenu();
	_draw.text("�����", { 523, 58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("�����", { 520, 60 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
	drawPanzers(panzer, coord, size, loop);
	_draw.textTransparence(false)
		.showPicture();
}
void ProfileFace::drawPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) {
	if (loop) {
		_tempCoord = { 520, 160 };
		if (coord.Y - _pastCoord > 110) _dynamicStart -= 2;
		if (_pastCoord - coord.Y > 110) _dynamicStart += 2;
		if (_pastCoord > coord.Y) --_dynamicStart;
		if (_pastCoord < coord.Y) ++_dynamicStart;
		if (_dynamicStart > size) _dynamicStart = 0;
		if (_dynamicStart < 0)_dynamicStart = size;
		_pastCoord = coord.Y;
		if (_dynamicStart > 5) { coord.Y = 550; }
		border({ coord.X, coord.Y });
		_dynamicFinish = (size < 5) ? size : (_dynamicStart > 5) ? _dynamicStart : 5;
		for (int i = (_dynamicStart <= 5) ? 0 : _dynamicStart - 5; i < _dynamicFinish; i++) {
			_draw.text(panzer[i].getName(), { 523, _tempCoord.Y - 2 }, 60, 15, "Palatino Linotype", NULL, NULL)
				.text(panzer[i].getName(), { 520, _tempCoord.Y }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
			if (_tempCoord.Y < 560) _tempCoord.Y += 100;
		}
		coord.Y = _pastCoord;
	}
	else {
		_pastCoord = 10;
		_dynamicStart = 0;
		_dynamicFinish = 0;
	}
}
void ProfileFace::drawSearchPanzer(const COORD& coord, const string& writing) {
	_draw.image({ 0,0 }, _pic.deskProfileUniversalTwo)
		.textTransparence(true);
	drawChooseMenu();
	border({ coord.X, coord.Y });
	_draw.text(writing, { 523, 58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(writing, { 520, 60 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	_draw.textTransparence(false)
		.showPicture();
}
ProfileFace::~ProfileFace()
{
}
