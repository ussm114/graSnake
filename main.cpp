#include <process.h> //system("cls");
#include "Plansza.h"
#include "Jedzenie.h"

// waz.cpp urosnij - ++ileSegmentow tez zatrzyma program gdy¿ nast¹pi przeskoczenie indeksu tablicy; ponadto (tam¿e) przesun o jeden - pêtla for
// srand(time(NULL)) do maina koniecznie a nie do jedzenia.cpp
//plansza.cpp konstruktor

int main(void) {
	srand(time(0)); //time.h
	Plansza plan;
	Waz snejk;
	Jedzenie food;
	plan.Graj(snejk, food);
	//plan.PokazWynik(snejk);
	return 0;
}
