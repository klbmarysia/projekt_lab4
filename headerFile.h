#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
double tab[8][4];
char znak[8][4];
int dataCounter = 0;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float x);
float CtoK(float x);
float KtoC(float x) ;
float KtoF(float x);
float pobierzF();
float pobierzK();
float pobierzC();
void menu();
int check(float temp, char stopnie);
void menu2();
int historia();






void menu2() {
	cout << "1. Tylko C - > inne" << endl << "2. Tylko F -> inne" << endl << "3. Tylko K -> inne" << endl << " 4. cala historia" << endl;
}

int historia() {
	int x = 0;
	cout << "Podaj numer: ";
	cin >> x;
	if (x < 1 || x > 4) {
		cout << "Nie ma takiej opcji. ";
		return 0;
	}
	else if (x == 1) {
		for (int i = 0; i < dataCounter / 2; i = i + 1) {
			if (znak[i][1] == 'C') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'C') {
				//cout << "Brak danych.";
				return 2;
			}
			
			else {
				return 0;
			}
		}
	}
	else if (x == 2) {
		for (int i = 0; i < dataCounter / 2; i = i + 1) {
			if (znak[i][1] == 'F') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'F') {
				//cout << "Brak danych.";
				return 2;
			}
			else {
				return 0;
			}
		}
	}
	else if (x == 3) {
		for (int i = 0; i < dataCounter / 2; i = i + 1) {
			if (znak[i][1] == 'K') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'K') {
				//cout << "Brak danych.";
				return 2;
			}
			else {
				return 0;
			}


		}
	}
	else if (x == 4) {
		for (int i = 0; i < dataCounter / 2; i = i + 1) {
			cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
		}
	}
}

	int check(float temp, char stopnie) {
	if (temp < 0 and stopnie == 'K') {
		return -999;
	}
	else if (temp < -273.15 and stopnie == 'C') {
		return -999;
	}
	else if (temp < -459.67 and stopnie == 'F') {
		return -999;
	}
	else {
		return  1;
	}
}

void menu() {
	cout << "1-przelicz Fahr -> Celsius " << endl << "2-przelicz Fahr - > Kelwin" << endl
		<< "3-przelicz Celsius -> Fahr" << endl << "4- przelicz celsius -> kelwin " << endl
		<< "5- przelicz Kelwin - > Celsius " << endl << "6-przelicz Kelwin -> Fahr" << endl
		<< "7- poka¿ historie" << endl << "8- zakonc dzialanie programu " << endl;
}
float pobierzF() {
	float fahr;
	cout << "podaj farh: ";
	cin >> fahr;
	return fahr;
}
float pobierzK() {
	float x;
	cout << "podaj kelwiny: ";
	cin >> x;
	return x;
}
 float pobierzC() {
	float x;
	cout << "podaj celsius ";
	cin >> x;
	return x;
}


float FtoC(float stopnie) {
	float wynik = (5.0 / 9.0) * (stopnie - 32.0);
	return wynik;
}
float FtoK(float stopnie) {
	float wynik = (stopnie + 459.67) * (5.0 / 9.0);
	return wynik;
}
float CtoF(float x) {
	float wynik = x * (9.0 / 5.0) + 32;
	return wynik;
}
float CtoK(float x) {
	float wynik = x + 273.15;
	return wynik;
}
float KtoC(float x) {
	float wynik = x - 273.15;
	return wynik;
}
float KtoF(float x) {
	float wynik = x * 9.0 / 5.0 - 459.67;
	return wynik;
}



