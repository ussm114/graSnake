#include "Jedzenie.h"
#include <stdlib.h>


Jedzenie::Jedzenie() {
}

Jedzenie::~Jedzenie() {
}

void Jedzenie::Losuj() {
	int x = ((double)rand() / RAND_MAX) * 66.0 ; // celowa autokonwersja
	int y = ((double)rand() / RAND_MAX) * 38.0; 
	this->SetPunkt(x+1, y+1); 
}
/*	int x = 66 * rand() / RAND_MAX;
int y = 38 * rand() / RAND_MAX; */

void Jedzenie::NarysujSie(int n) {
	gotoxy(this->x, this->y);
	cout << n;
}