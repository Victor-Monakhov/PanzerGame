#pragma once
#include "PanzersFace.h"
class PoligonFace : public PanzersFace {
protected:
	
	virtual void drawStartMenu() override;
	void drawPanzerInformation(Player& panzer);
public:
	PoligonFace();
	void drawPoligon(Player& panzer, const COORD& coord);
	~PoligonFace();
};

