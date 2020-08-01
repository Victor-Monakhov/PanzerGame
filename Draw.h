#pragma once
#include "Map.h"
using namespace std;

class Draw
{
private:
	PAINTSTRUCT ps;
	HWND _window;
	HDC _hdc;
	HDC _tempDc;       // for temp buffer
	HBITMAP _hBit;     //
	int _windowWidth, _windowHeight;
	static long long updateCounter; //be on the safe side for window updating
public:
	explicit Draw(int windowWidth, int windowHeight);
	//explicit Draw(HWND& window, int windowWidth, int windowHeight);
	Draw& rectangle(COORD leftTopCoord, COORD rightBotCoord, COLORREF color);
	Draw& ellipse(COORD leftTopCoord, COORD rightBotCoord, COLORREF color);
	Draw& text(string writing, COORD leftTopCoord, int fontHeight, int fontWidth, string fontType, 
				COLORREF color, COLORREF backColor);
	Draw& image(const COORD& coord, const WCHAR*adress);
	Draw& textTransparence(bool background);
	HDC getHdc();
	HWND* getHWND();
	void setHdc(HDC hdc);
	void showPicture();
	void setWindow(HWND window);
	void setWinWidth(int width);
	void setWinHeight(int height);
	~Draw();
};

