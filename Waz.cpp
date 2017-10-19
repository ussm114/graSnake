#include "Waz.h"

Waz::Waz() : ileSegmentow(4), kierunek('d') {
	//poczatkowa d³ugosc weza to 10 segmentów
	for (int i = 0; i < this->ileSegmentow; i++) {
		tab[i] = new Punkt;
		tab[i]->SetPunkt(2, 11 - i);
	}
}
//kasowanie tablicy wskaznikow
Waz::~Waz() {
	for (int i = 0; i < this->ileSegmentow; i++) {
		delete tab[i];
	}
}

void Waz::NarysujSie() {
	for (int i = 0; i < this->ileSegmentow - 1; i++) { // uwazac na -1 przy this->ileSegmentow
		tab[i]->NarysujSie(); 
	}
	char c = this->ileSegmentow;
	tab[c - 1]->NarysujSie(c);
}

void Waz::PrzesunOJeden() {
	int c, d;
	//poczynaj¹c od drugiego(!) segmentu, nadajemy mu wartosc wczeœniejszego (2gi dostanie 1go, itd)
	//for (int a = 1; a < this->ileSegmentow; a++)  //wersja alternatywna, z b³êdem (skrócenie wêza do postaci 1-2 segmentów)
	for (int a = this->ileSegmentow - 1; a > 0; a--) {
		c = tab[a-1]->GetX();
		d = tab[a-1]->GetY();
		this->tab[a]->SetPunkt(c, d); //wykorzystujê gettery do nadania wartosci punktowi
	}
	//nadanie wartosci pierwszemu
	int up_down = 0;
	int left_right = 0;
	switch (kierunek) {
	case 'w':
		up_down = -1;
		//left_right = 0; raczej niekonieczne
		break;
	case 's':
		up_down = 1;
		//left_right = 0; jw
		break;
	case 'd':
		left_right = 1;
		//up_down = 0;
		break;
	case 'a':
		left_right = -1;
		//up_down = 0;
		break;
	}
	c = tab[0]->GetX();
	d = tab[0]->GetY();
	tab[0]->SetPunkt(c + left_right, d + up_down);
}

void Waz::Urosnij() {
	tab[ileSegmentow++] = new Punkt; // zwiekszenie o jeden tablicy Punktów - tab
	// w sumie to nie trzeba setowac bo samo siê zasetuje przy funkcji PrzesunOJeden()
}
