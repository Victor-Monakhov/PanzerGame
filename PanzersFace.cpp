#include "PanzersFace.h"

PanzersFace::PanzersFace(int dynamicStart, int dynamicFinish, int pastCoord) :
	_dynamicStart{ dynamicStart },
	_dynamicFinish{ dynamicFinish },
	_pastCoord{ pastCoord },
	_tempCoord{ 0,0 }
{}
void PanzersFace::drawStartMenu() {
	_draw.text("œŒÀ»√ŒÕ", { 153,428 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("œŒÀ»√ŒÕ", { 150,430 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("—Œ«ƒ¿“‹ “¿Õ ", { 73,518 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("—Œ«ƒ¿“‹ “¿Õ ", { 70,520 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("”ƒ¿À»“‹ “¿Õ ", { 73,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("”ƒ¿À»“‹ “¿Õ ", { 70,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("¬€’Œƒ", { 643,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("¬€’Œƒ", { 640,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void PanzersFace::drawPanzerCreaterMenu() {
	_draw.text("Õ¿«¬¿Õ»≈ “¿Õ ¿", { 523, 18 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("Õ¿«¬¿Õ»≈ “¿Õ ¿", { 520, 20 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÃŒƒ≈À‹ “¿Õ ¿", { 533, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÃŒƒ≈À‹ “¿Õ ¿", { 530, 290 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("’¿–¿ “≈–»—“» »", { 523, 468 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("’¿–¿ “≈–»—“» »", { 520, 470 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void PanzersFace::drawPanzerCharacteristicsMenu(Player& panzer) {
	_draw.text("Œ◊ » ¿œ√–≈…ƒ¿:", { 513, 18 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("Œ◊ » ¿œ√–≈…ƒ¿:", { 510, 20 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("«ƒŒ–Œ¬‹≈:", { 543, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("«ƒŒ–Œ¬‹≈:", { 540, 110 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("/100", { 803, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("/100", { 800, 110 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("¡–ŒÕﬂ:", { 543, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("¡–ŒÕﬂ:", { 540, 200 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("/100", { 803, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("/100", { 800, 200 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("— Œ–Œ—“‹:", { 543, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("— Œ–Œ—“‹:", { 540, 290 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("/22", { 803, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("/22", { 800, 290 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("—»À¿:", { 543, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("—»À¿:", { 540, 380 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("/5:", { 803, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("/5:", { 800, 380 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("—Œ¡–¿“‹ “¿Õ ", { 553, 468 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("—Œ¡–¿“‹ “¿Õ ", { 550, 470 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)

		.text("<<", { 503, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<", { 500, 110 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("<<", { 503, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<", { 500, 200 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("<<", { 503, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<", { 500, 290 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("<<", { 503, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<", { 500, 380 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(">>", { 873, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>", { 870, 110 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(">>", { 873, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>", { 870, 200 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(">>", { 873, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>", { 870, 290 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(">>", { 873, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>", { 870, 380 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)

		.text(to_string(panzer.getCommandPoints()), { 843, 18 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getCommandPoints()), { 840, 20 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getHealth()), { 753, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getHealth()), { 750, 110 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getArmor()), { 753, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getArmor()), { 750, 200 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getSpeed()), { 753, 288 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getSpeed()), { 750, 290 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getShotPower()), { 753, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getShotPower()), { 750, 380 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
}
void PanzersFace::drawMainPage(const COORD& coord) {
	_draw.image({ 0,0 }, _pic.deskPoligonMenu);
	border(coord);
	_draw.textTransparence(true);
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void PanzersFace::drawNewPanzerName(const COORD& coord, string& writing, bool busy) {
	_draw.image({ 0,0 }, _pic.deskPanzerNameModel);
	border(coord);
	_draw.textTransparence(true);
	drawPanzerCreaterMenu();
	_draw.text(writing, { 523, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(writing, { 520, 110 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	if (busy) _draw.rectangle({ 500, 190 }, { 900, 270 }, RGB(60, 50, 50))
		.text("ËÏˇ ÌÂ‰ÓÒÚÛÔÌÓ", { 523, 198 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ËÏˇ ÌÂ‰ÓÒÚÛÔÌÓ", { 520, 200 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void PanzersFace::drawNewPanzerModel(const COORD& coord, Player& panzer, bool pushLeft, bool pushRight) {
	_draw.image({ 0,0 }, _pic.deskPanzerNameModel);
	border(coord);
	_draw.textTransparence(true);
	drawPanzerCreaterMenu();
	COLORREF colorLeft = (pushLeft) ? RGB(255, 0, 0) : RGB(255, 255, 255);
	COLORREF colorRight = (pushRight) ? RGB(255, 0, 0) : RGB(255, 255, 255);
	Sleep(50);
	_draw.text(panzer.getName(), { 523, 108 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(panzer.getName(), { 520, 110 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text(to_string(panzer.getModel()), { 688, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getModel()), { 685, 380 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text("<<<", { 513, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<<", { 510, 380 }, 60, 15, "Palatino Linotype", colorLeft, NULL)
		.text(">>>", { 843, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>>", { 840, 380 }, 60, 15, "Palatino Linotype", colorRight, NULL)
		.text(to_string(panzer.getModel()), { 688, 378 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getModel()), { 685, 380 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.image({ 220, 180 }, showModel(&panzer));
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void PanzersFace::drawNewPanzerCharacteristics(const COORD& coord, Player& panzer, bool pushLeft, bool pushRight) {
	_draw.image({ 0,0 }, _pic.deskPanzerCharacteristics);
	border(coord);
	_draw.textTransparence(true);
	drawPanzerCharacteristicsMenu(panzer);
	COLORREF colorLeft = (pushLeft) ? RGB(255, 0, 0) : RGB(255, 255, 255);
	COLORREF colorRight = (pushRight) ? RGB(255, 0, 0) : RGB(255, 255, 255);
	Sleep(50);
	if (coord.Y < 450)
		_draw.text("<<", { 503, coord.Y + 8 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("<<", { 500, coord.Y + 10 }, 60, 15, "Palatino Linotype", colorLeft, NULL)
		.text(">>", { 873, coord.Y + 8 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(">>", { 870, coord.Y + 10 }, 60, 15, "Palatino Linotype", colorRight, NULL);
	_draw.image({ 220, 180 }, showModel(&panzer));
	drawStartMenu();
	_draw.textTransparence(false)
		.showPicture();
}
void PanzersFace::drawPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) {
	if (loop) {
		_tempCoord = { 520, 100 };
		if (coord.Y - _pastCoord > 100) _dynamicStart -= 2;
		if (_pastCoord - coord.Y > 100) _dynamicStart += 2;
		if (_pastCoord > coord.Y) --_dynamicStart;
		if (_pastCoord < coord.Y) ++_dynamicStart;
		if (_dynamicStart > size) _dynamicStart = 0;
		if (_dynamicStart < 0)_dynamicStart = size;
		_pastCoord = coord.Y;
		if (_dynamicStart > 5) { coord.Y = 460; }
		border({ coord.X, coord.Y });
		_dynamicFinish = (size < 5) ? size : (_dynamicStart > 5) ? _dynamicStart : 5;
		for (int i = (_dynamicStart <= 5) ? 0 : _dynamicStart - 5; i < _dynamicFinish; i++) {
			_draw.text(panzer[i].getName(), { 523, _tempCoord.Y - 2 }, 60, 15, "Palatino Linotype", NULL, NULL)
				.text(panzer[i].getName(), { 520, _tempCoord.Y }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
			if (_tempCoord.Y < 460) _tempCoord.Y += 90;
		}
		coord.Y = _pastCoord;
		if(coord.Y > 50)_draw.image({ 220, 180 }, showModel(&panzer[_dynamicStart - 1]));
	}
	else {
		_pastCoord = 10;
		_dynamicStart = 0;
		_dynamicFinish = 0;
	}
}
void PanzersFace::drawSearchPanzer(const COORD& coord, const string& writing) {
	_draw.image({ 0,0 }, _pic.deskPanzerCharacteristics)
		.textTransparence(true);
	drawStartMenu();
	border({ coord.X, coord.Y });
	_draw.text(writing, { 523, 18 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text(writing, { 520, 20 }, 60, 15, "Palatino Linotype", RGB(255, 0, 0), NULL);
	_draw.textTransparence(false)
		.showPicture();
}
void PanzersFace::drawAllPanzers(vector<Player>& panzer, COORD& coord, int size, bool loop) {
	_draw.image({ 0,0 }, _pic.deskPanzerCharacteristics)
		.textTransparence(true);
	drawStartMenu();
	_draw.text("œŒ»— ", { 523, 8 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("œŒ»— ", { 520, 10 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
	drawPanzers(panzer, coord, size, loop);
	_draw.textTransparence(false)
		.showPicture();
}
PanzersFace::~PanzersFace()
{}
