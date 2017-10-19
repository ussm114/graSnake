#pragma once
#include "Punkt.h"
#include <time.h> // rand

class Jedzenie : public Punkt {
public:
	Jedzenie();
	~Jedzenie();
	void Losuj(); // losuje na mapie miejsce gdzie ma siê pojawiæ jedzenie
	void NarysujSie(int);
};

