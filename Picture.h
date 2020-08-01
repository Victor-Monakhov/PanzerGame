#pragma once

#include "Map.h"

class Picture {
public:
	//panzers
	const WCHAR* greenPanzer[4];
	const WCHAR* brownPanzer[4];
	const WCHAR* whitePanzer[4];
	const WCHAR* yellowPanzer[4];
	const WCHAR* greyPanzer[4];
	//for game process
	const WCHAR* map = L"images/map.bmp";
	const WCHAR* shot0 = L"images/shot0.bmp";
	const WCHAR* shot1 = L"images/shot1.bmp";
	const WCHAR* fire0 = L"images/shotFire0.bmp";
	const WCHAR* fire1 = L"images/shotFire1.bmp";
	const WCHAR* fire2 = L"images/shotFire2.bmp";
	const WCHAR* fire3 = L"images/shotFire3.bmp";
	const WCHAR* boom = L"images/boom.bmp";
	const WCHAR* boom2 = L"images/boom2.bmp";
	const WCHAR* boom3 = L"images/boom3.bmp";
	const WCHAR* deathRed = L"images/deathRed.bmp";
	const WCHAR* deathBlue = L"images/deathBlue.bmp";
	//home menu
	const WCHAR* startDesk = L"images/startDesk.bmp";
	const WCHAR* deskProfileName = L"images/deskProfileName.bmp";
	const WCHAR* deskProfileUniversal = L"images/deskProfileUniversal.bmp";
	const WCHAR* deskProfileMenu = L"images/deskProfileMenu.bmp";
	const WCHAR* deskPoligonMenu = L"images/deskPoligonMenu.bmp";
	const WCHAR* deskPanzerNameModel = L"images/deskPanzerNameModel.bmp";
	const WCHAR* deskPanzerCharacteristics = L"images/deskPanzerCharacteristics.bmp";
	const WCHAR* deskPanzerMenu = L"images/deskPanzerMenu.bmp";
	const WCHAR* deskError = L"images/errorMessage.bmp";
	const WCHAR* startDeskTwo = L"images/startDeskTwo.bmp";
	const WCHAR* deskProfileUniversalTwo = L"images/deskProfileUniversalTwo.bmp";
	const WCHAR* deskStatistics = L"images/deskStatistics.bmp";
	const WCHAR* deskEscape = L"images/deskEscape.bmp";
	const WCHAR* deskWin = L"images/deskWin.bmp";
	const WCHAR* deskMyGame = L"images/myGameDesk.bmp";
	Picture()
	{
		greenPanzer[0] = L"images/green0.bmp";
		greenPanzer[1] = L"images/green1.bmp";
		greenPanzer[2] = L"images/green2.bmp";
		greenPanzer[3] = L"images/green3.bmp";
		//brown panzer
		brownPanzer[0] = L"images/brown0.bmp";
		brownPanzer[1] = L"images/brown1.bmp";
		brownPanzer[2] = L"images/brown2.bmp";
		brownPanzer[3] = L"images/brown3.bmp";
		//white panzer
		whitePanzer[0] = L"images/white0.bmp";
		whitePanzer[1] = L"images/white1.bmp";
		whitePanzer[2] = L"images/white2.bmp";
		whitePanzer[3] = L"images/white3.bmp";
		//yellow panzer
		yellowPanzer[0] = L"images/yellow_0.bmp";
		yellowPanzer[1] = L"images/yellow1.bmp";
		yellowPanzer[2] = L"images/yellow2.bmp";
		yellowPanzer[3] = L"images/yellow3.bmp";
		//grey panzer
		greyPanzer[0] = L"images/grey0.bmp";
		greyPanzer[1] = L"images/grey1.bmp";
		greyPanzer[2] = L"images/grey2.bmp";
		greyPanzer[3] = L"images/grey3.bmp";
	}
};
