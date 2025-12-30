#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
double tab[100][4];
char znak[100][4];
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



