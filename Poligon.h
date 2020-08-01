#pragma once
#include "Panzers.h"
#include "PoligonFace.h"

class Poligon : public Panzers{
protected:
	const int _poligonHeight;
	const int _poligonWidth;
	Map _poligonMap;
	PoligonFace _poligonFace;
public:
	Poligon();
	void wellComePoligone();
	void poligonInit();
	void trainig(Player* panzer, int element);
	~Poligon();
};

