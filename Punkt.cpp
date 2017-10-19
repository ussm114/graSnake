#include "Punkt.h"

Punkt::Punkt(void) {
}

Punkt::~Punkt() {
}

// funkcja gotxy() dziêki http://cs.dvc.edu/HowTo_Cgotoxy.html
void Punkt::gotoxy(int x, int y) { //
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void Punkt::SetPunkt(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}

bool Punkt::operator==(Punkt pkt) {
	if (pkt.x == this->x && pkt.y == this->y) return true;
	return false;
}

void Punkt::operator=(Punkt pkt) {
	this->x = pkt.x;
	this->y = pkt.y;
}

//void narysuj sie jest w nag³ówku 