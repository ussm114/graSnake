#pragma once
#include "Punkt.h"
#include "Jedzenie.h"

//wê¿a robimy jako kompozycjê tych segmentów-punktów
class Waz {
	friend class Plansza;
	char kierunek; // przechowuje wartosc gdzie idziemy, niech to bêdzie w/a/s/d
	int ileSegmentow;
	Punkt* tab[100];
public:
	Waz();
	~Waz();
	void NarysujSie();
	void PrzesunOJeden();
	void Urosnij();
	void SetKierunek(char czar) {
		this->kierunek = czar;
	}
	int getileSegmentow() {
		return this->ileSegmentow;
	}
};


