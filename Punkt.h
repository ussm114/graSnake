#pragma once
#include <iostream>
using namespace std;
#include <windows.h>  //Sleep

class Punkt {
	friend class Waz;
	friend class Plansza;
	friend class Jedzenie;
	int x;
	int y;
	//char czar; // w konstruktorze jest jako 0 ustawiony
public:
	Punkt(int, int);
	Punkt(void);
	void SetPunkt(int, int);
	bool operator==(Punkt pkt);
	void operator=(Punkt pkt);
	//gettery sa potrzebne do funkcji Waz::PrzesunOJeden()
	int GetX(void) {
		return this->x;
	}
	int GetY(void) {
		return this->y;
	}
	~Punkt();
	void gotoxy(int, int);
	void NarysujSie(char c = 48) {
		gotoxy(this->x, this->y);
		cout << c; // chwilowo!
	}
};


