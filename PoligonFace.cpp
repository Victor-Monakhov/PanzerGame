#include "PoligonFace.h"


PoligonFace::PoligonFace()
{}
void PoligonFace::drawStartMenu() {
	_draw.text("ÏÎËÈÃÎÍ", { 153,428 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÏÎËÈÃÎÍ", { 150,430 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÑÎÇÄÀÒÜ ÒÀÍÊ", { 73,518 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÑÎÇÄÀÒÜ ÒÀÍÊ", { 70,520 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÓÄÀËÈÒÜ ÒÀÍÊ", { 73,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÓÄÀËÈÒÜ ÒÀÍÊ", { 70,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÂÛÕÎÄ", { 643,608 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÂÛÕÎÄ", { 640,610 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("ÓËÓ×ØÈÒÜ ÒÀÍÊ", { 523,468 }, 60, 15, "Palatino Linotype", NULL, NULL)
		.text("ÓËÓ×ØÈÒÜ ÒÀÍÊ", { 520,470 }, 60, 15, "Palatino Linotype", RGB(255, 255, 255), NULL);
}
void PoligonFace::drawPanzerInformation(Player& panzer) {
	_draw.textTransparence(true)
		.text("Taíê", { 513, 18 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Taíê", { 510, 20 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Óðîâåíü", { 513, 48 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Óðîâåíü", { 510, 50 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Çäîðîâüå", { 513, 78 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Çäîðîâüå", { 510, 80 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Áðîíÿ", { 513, 108 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Áðîíÿ", { 510, 110 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ñêîðîñòü", { 513, 138 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Ñêîðîñòü", { 510, 140 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ñèëà", { 513, 168 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Ñèëà", { 510, 170 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Äàëüíîñòü âûñòðåëà", { 513, 198 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Äàëüíîñòü âûñòðåëà", { 510, 200 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âðåìÿ âîçðàæäåíèÿ", { 513, 228 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Âðåìÿ âîçðàæäåíèÿ", { 510, 230 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Âñåãî ñðàæåíèé", { 513, 258 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Âñåãî ñðàæåíèé", { 510, 260 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ïîáåä", { 513, 288 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Ïîáåä", { 510, 290 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ëó÷øåå âðåìÿ", { 513, 318 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Ëó÷øåå âðåìÿ", { 510, 320 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Î÷êè àïãðåéäà", { 513, 348 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Î÷êè àïãðåéäà", { 510, 350 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)
		.text("Ìîíåò", { 513, 378 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text("Ìîíåò", { 510, 380 }, 30, 10, "Palatino Linotype", RGB(255, 255, 255), NULL)

		.text(panzer.getName(), { 763, 18 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(panzer.getName(), { 760, 20 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getLevel()), { 763, 48 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getLevel()), { 760, 50 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getHealth()), { 763, 78 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getHealth()), { 760, 80 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getArmor()), { 763, 108 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getArmor()), { 760, 110 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getSpeed()), { 763, 138 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getSpeed()), { 760, 140 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getShotPower()), { 763, 168 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getShotPower()), { 760, 170 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getShotDistance()), { 763, 198 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getShotDistance()), { 760, 200 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getRespawnTime()), { 763, 228 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getRespawnTime()), { 760, 230 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getBattles()), { 763, 258 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getBattles()), { 760, 260 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getWins()), { 763, 288 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getWins()), { 760, 290 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getBestTime()), { 763, 318 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getBestTime()), { 760, 320 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getCommandPoints()), { 763, 348 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getCommandPoints()), { 760, 350 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL)
		.text(to_string(panzer.getMoney()), { 763, 378 }, 30, 10, "Palatino Linotype", NULL, NULL)
		.text(to_string(panzer.getMoney()), { 760, 380 }, 30, 10, "Palatino Linotype", RGB(255, 0, 0), NULL);
}
void PoligonFace::drawPoligon(Player& panzer, const COORD& coord) {
	_draw.image({ 0,0 }, _pic.deskPanzerMenu);
	border(coord);
	_draw.textTransparence(true);
	drawStartMenu();
	drawPanzerInformation(panzer);
	_draw.image(panzer.getCoord(), showModel(&panzer));
	if (panzer.getBullet()->getSpeed() != 0)
		_draw.image(panzer.getBullet()->getCoord(), showBullet(&panzer));
	showShotMoment(&panzer);
	showHit(&panzer);
	showHealth(&panzer, &panzer);
	_draw.textTransparence(false)
		.showPicture();
}

PoligonFace::~PoligonFace()
{}
