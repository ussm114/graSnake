#pragma once
#include "Waz.h"
#include <conio.h> //kbhit, getch

class Plansza {
	int Ymax;
	int Xmax;
public:
	Plansza();
	~Plansza();
	void Graj(Waz&, Jedzenie);
	void NarysujGranice(void);
	// ponizsze funkcje powinne sie nazywac raczej Sprawdz czy wjechal w granice / w siebie
	bool SprawdzGranice(Waz&); // pomysl potem czy referencja jest konieczna 
	bool SprawdzWeza(Waz&); //sprawdz siebie - sprawdz czy nie wlaz³ w siebie
	void ZakonczGre(Waz, Jedzenie);
	//void PokazWynik(Waz);
};
