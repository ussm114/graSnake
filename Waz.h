#pragma once
#include "Punkt.h"
#include "Jedzenie.h"

//w�a robimy jako kompozycj� tych segment�w-punkt�w
class Waz {
	friend class Plansza;
	char kierunek; // przechowuje wartosc gdzie idziemy, niech to b�dzie w/a/s/d
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


