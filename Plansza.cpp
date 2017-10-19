#include "Plansza.h"

Plansza::Plansza() : Xmax(68), Ymax(40) { // plansze ustawiamy na tyle, sprawdz losowanie jedzenia, musi byc mniejsze o margines bezpieczenstwa losowania
}

Plansza::~Plansza() {
}

void Plansza::ZakonczGre(Waz snake, Jedzenie food) {
	int licznik = 0;
	while (licznik++ != 7000) {
		food.Losuj();
		food.NarysujSie(0);
		//Sleep(1);
	}
	system("cls");
	cout << "score: " << snake.ileSegmentow << endl;
	cout << " .....::::::::  to juz jest koniec  :::::::::............." << endl;
}

bool Plansza::SprawdzGranice(Waz& snake) {
	int X = 0;
	for (int Y = 0; Y <= this->Ymax; Y++) {
			if (snake.tab[0]->x == X && snake.tab[0]->y == Y) return true;  //innymi s³owy if(g³owa wjedzie w granicê)
	}
	X = this->Xmax;
	for (int Y = 0; Y <= this->Ymax; Y++) {
		if (snake.tab[0]->x == X && snake.tab[0]->y == Y)  return true;
	}
	int Y = 0;
	for (int X = 0; X <= this->Xmax; X++) {
		if (snake.tab[0]->x == X && snake.tab[0]->y == Y) return true;
	}
	Y = this->Ymax;
	for (int X = 0; X <= this->Xmax; X++) {
		if (snake.tab[0]->x == X && snake.tab[0]->y == Y) return true;
	}
	return false; //jesli nie stwierdzi sie zadnej kolizji
}

bool Plansza::SprawdzWeza(Waz& snake) {
	for (int i = 3; i < snake.ileSegmentow; i++) { //posprawdzac wystarczy od 3 elementu i = 3
		if (*(snake.tab[0]) == *(snake.tab[i])) return true;
	}
	return false;
}

void Plansza::NarysujGranice(void) {
	Punkt temp; // najszybszy sposob narysowania to wykorzystanie punktu
	for (int i = 0; i <= this->Xmax; i++) {
		temp.SetPunkt(i, 0);
		temp.NarysujSie(220); // narysuj kwadrat zamalowany
	}
	for (int i = 0; i <= this->Xmax; i++) {
		temp.SetPunkt(i, this->Ymax);
		temp.NarysujSie(220);
	}
	for (int i = 0; i <= this->Ymax; i++) {
		temp.SetPunkt(this->Xmax, i);
		temp.NarysujSie(220);
	}
	for (int i = 0; i <= this->Ymax; i++) {
		temp.SetPunkt(0, i);
		temp.NarysujSie(220);
	}
}

/*void Plansza::PokazWynik(Waz snake) {
	//Punkt przypal;
	idz_do_XY(71, 3);
	cout << snake.getileSegmentow();
}*/

//bardzo wa¿ne-w¹¿ musi byæ przekazany przez referencjê, przekazanie przez wartosc skutkuje wysypaniem siê programu

void Plansza::Graj(Waz& snake, Jedzenie food) {
	char c;
	//bool a, b;
	int n, licznik = 1;
	snake.NarysujSie();
	food.Losuj();
	food.NarysujSie(0);
	while (true) {
		if (_kbhit()) {
			c = _getch();
			if (c == 'w' || c == 'a'|| c == 's' || c == 'd') //idiotoodpornosc
				snake.SetKierunek(c); //ustawienie kierunku wê¿a
		}
		// co int n-ty krok przesun weza
		if (licznik % 700 == 0) {
			snake.PrzesunOJeden();
			system("cls");
			snake.NarysujSie();  //przed narysowaniem wê¿a przyda³oby siê wyczyscic ekran, trzeba te¿ znowu narysowac jedzenie
			n = snake.ileSegmentow;
			food.NarysujSie(n);
			NarysujGranice();
			//PokazWynik(snake);
			if (this->SprawdzGranice(snake) ||  this->SprawdzWeza(snake)) //sprawdz od razu czy aby nie wjechal w granicê mapy lub w siebie. dbamy o szybkosc, stosujê: || zamiast:  | 
				break; //jeœli tak to koñczymy grê
			// powyzszy if ma na celu szybkie wykonywanie
			//obsluga w przypadku gdy siê wlezie w jedzenie; st¹d ;;;;;
			if (*(snake.tab[0]) == (Punkt)food) {
				snake.Urosnij(); // w¹¿  powiêkszony
				food.Losuj();			//wylosuj i narysuj nowe jedzenie
				n = snake.ileSegmentow;
				food.NarysujSie(n);
			} //dot¹d
		}
		licznik++;
	}
	ZakonczGre(snake, food);
}



//zajawka metody graj. fajnie lata. mozna urosn¹c co 1 lub 2 przesuniêcia se sprawdzic
/*void Plansza::Graj(Waz& snake) {
	while (true) {
		snake.SetKierunek('d');
		snake.NarysujSie();
		Sleep(100);
		snake.Urosnij();
		snake.PrzesunOJeden();
		system("cls");
		snake.NarysujSie();
		Sleep(100);
		snake.SetKierunek('s');
		snake.Urosnij();
		snake.PrzesunOJeden();
		system("cls");
		snake.NarysujSie();
		Sleep(100);
		system("cls");
	}
	cout << "finito" << endl;
}
*/
