#include "StartFace.h"

StartFace::StartFace()
{
	_pastCoord = 50;
}
void StartFace::drawStartMenu() {
	_draw.text("ÕŒ¬€… œ–Œ‘»À‹", { 63,58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÕŒ¬€… œ–Œ‘»À‹", { 60,60 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("¬€¡Œ– œ–Œ‘»Àﬂ", { 63,158 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("¬€¡Œ– œ–Œ‘»Àﬂ", { 60,160 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("”ƒ¿À»“‹ œ–Œ‘»À‹", { 63,258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("”ƒ¿À»“‹ œ–Œ‘»À‹", { 60,260 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("»Ãﬂ œ–Œ‘»Àﬂ", { 63,358 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("»Ãﬂ œ–Œ‘»Àﬂ", { 60,360 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("¬€’Œƒ", { 63,458 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("¬€’Œƒ", { 60,460 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void StartFace::drawProfiles(vector<Profile>& profile, COORD& coord, int size, bool loop) {
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
			_draw.text(profile[i].getName(), { 523, _tempCoord.Y - 2 }, 60, 15, "Palatino Linotype", NULL, NULL)
				.text(profile[i].getName(), { 520, _tempCoord.Y }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
			if (_tempCoord.Y < 560) _tempCoord.Y += 100;
		}
		coord.Y = _pastCoord;
	}
	else {
		_pastCoord = 50;
		_dynamicStart = 0;
		_dynamicFinish = 0;
	}
}
void StartFace::drawMainPage(const COORD& coord) {
	_draw.image({ 0,0 }, _pic.startDesk);
	border(coord);
	_draw.textTransparence(true);
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void StartFace::drawNewProfile(const COORD& coord, const string& writing, bool busy) {
	_draw.image({ 0,0 }, _pic.deskProfileName)
		.textTransparence(true);
	drawStartMenu();
	border({ coord.X, coord.Y + 100 });
	_draw.text("¬¬≈ƒ»“≈ »Ãﬂ", { 523, 58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("¬¬≈ƒ»“≈ »Ãﬂ", { 520, 60 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(writing, { coord.X + 23, coord.Y + 98 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(writing, { coord.X + 20, coord.Y + 100 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	if (busy) _draw.rectangle({ 500, 250 }, { 900, 330 }, RGB(60, 50, 50))
		.text("ËÏˇ ÌÂ‰ÓÒÚÛÔÌÓ", { 523, 258 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ËÏˇ ÌÂ‰ÓÒÚÛÔÌÓ", { 520, 260 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	_draw.textTransparence(false)
		.showPicture();
}
void StartFace::drawProfileChoice(vector<Profile>& profile, COORD& coord, int size, bool loop) {
	_draw.image({ 0,0 }, _pic.deskProfileUniversal)
		.textTransparence(true);
	drawStartMenu();
	_draw.text("œŒ»— ", { 523, 58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("œŒ»— ", { 520, 60 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
	drawProfiles(profile, coord, size, loop);
	_draw.textTransparence(false)
		.showPicture();
}
void StartFace::drawSearchProfile(const COORD& coord, const string& writing) {
	_draw.image({ 0,0 }, _pic.deskProfileUniversal)
		.textTransparence(true);
	drawStartMenu();
	border({ coord.X, coord.Y });
	_draw.text(writing, { 523, 58 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(writing, { 520, 60 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	_draw.textTransparence(false)
		.showPicture();
}
StartFace::~StartFace()
{}
