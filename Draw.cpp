#include "Draw.h"

long long Draw::updateCounter = 0;
//for console
Draw::Draw(int windowWidth, int windowHeight) :_windowWidth{windowWidth}, _windowHeight{windowHeight} {				
	_window = GetConsoleWindow();
	_hdc = GetDC(_window);
	_tempDc = CreateCompatibleDC(_hdc);
	_hBit = CreateCompatibleBitmap(_hdc, _windowWidth, _windowHeight);
}
////for window
//Draw::Draw(HWND& window, int windowWidth, int windowHeight) :_windowWidth{ windowWidth }, _windowHeight{windowHeight} {
//	_window = window;
//	_hdc = GetDC(_window);
//	_tempDc = CreateCompatibleDC(_hdc);
//	_hBit = CreateCompatibleBitmap(_hdc, _windowWidth, _windowHeight);
//	_tempDc = BeginPaint(_window, &ps);
//}


Draw& Draw::rectangle(COORD leftTopCoord, COORD rightBotCoord, COLORREF color) {
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(_tempDc, brush);
	Rectangle(_tempDc, leftTopCoord.X, leftTopCoord.Y, rightBotCoord.X, rightBotCoord.Y);
	DeleteObject(brush);
	return *this;
}
Draw& Draw::ellipse(COORD leftTopCoord, COORD rightBotCoord, COLORREF color) {
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(_tempDc, brush);
	Ellipse(_tempDc, leftTopCoord.X, leftTopCoord.Y, rightBotCoord.X, rightBotCoord.Y);
	DeleteObject(brush);
	return *this;
}
Draw& Draw::text(string writing, COORD leftTopCoord, int fontHeight, int fontWidth, string fontType, COLORREF color, COLORREF backColor) {
	HFONT font = CreateFontA(fontHeight, fontWidth, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontType.c_str());
	SelectObject(_tempDc, font);
	SetBkColor(_tempDc, backColor);
	SetTextColor(_tempDc, color);
	TextOutA(_tempDc, leftTopCoord.X, leftTopCoord.Y, writing.c_str(), strlen(writing.c_str()));
	
	DeleteObject(font);
	return *this;
}
Draw& Draw::image(const COORD& coord, const WCHAR* adress) {
	HDC tempDc = CreateCompatibleDC(_tempDc);
	HBITMAP tempHBit = (HBITMAP)LoadImageW(NULL, adress, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	SelectObject(tempDc, tempHBit);
	BitBlt(_tempDc, coord.X, coord.Y, _windowWidth, _windowHeight, tempDc, 0, 0, SRCCOPY);
	DeleteDC(tempDc);
	tempDc = nullptr;
	DeleteObject(tempHBit);
	tempHBit = nullptr;
	return *this;
}
Draw& Draw::textTransparence(bool background) {
	if (background) SetBkMode(_tempDc, TRANSPARENT);
	else SetBkMode(_tempDc, OPAQUE);
	return *this;
}
void Draw::showPicture() {
	++updateCounter;				
	SelectObject(_tempDc, _hBit);
	BitBlt(_hdc, 0, 0, _windowWidth, _windowHeight, _tempDc, 0, 0, SRCCOPY);
	if (updateCounter == 5000) {                        // be on the safe side
	//	InvalidateRect(_window, NULL, FALSE);			//
		updateCounter = 0;								//
	}		
	//EndPaint(_window, &ps);
}

HDC Draw::getHdc() {
	return _hdc;
}
HWND* Draw::getHWND() {
	return &_window;
}
void Draw::setHdc(HDC hdc) {
	_hdc = hdc;
}
void Draw::setWindow(HWND window) {
	_window = window;
}
void Draw::setWinWidth(int width) {
	_windowWidth = width;
}
void Draw::setWinHeight(int height) {
	_windowHeight = height;
}
Draw::~Draw(){
	DeleteDC(_hdc);
	DeleteDC(_tempDc);
	DeleteObject(_hBit);
	DeleteObject(_window);
	_hdc = NULL;
	_tempDc = NULL;
	_hBit = NULL;
	_window = NULL;
}
