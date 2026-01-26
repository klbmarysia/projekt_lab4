#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
double tab[100][100];
char znak[100][100];
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
int usuwanie();
int historiacala();
int edit();
int los();
int funkcjalos(int x);








bool conversionFailed = false;
int convertToInteger(const char vector[], int size);

int convertToInteger(const char vector[], int size) {
	int result = 0;
	bool isNegative = false;
	for (int i = 0; i < size; i ++) {
		if (vector[i] == '\0') {
			break;
		}
		if (isdigit(vector[i])) {
			result = result * 10 + (vector[i] - '0');

		}
		else if (vector[i] == '-' && i == 0) {
			isNegative = true;
		}
		else if (vector[i] == '+' && i == 0) {
			continue;
		}
		else {
			if (conversionFailed == false) {
				conversionFailed = true;
			}
		}

	}
	if (isNegative) {
		return -result;

	}
	else {
		return result;
	}
}



int funkcjalos(int x) {
	int tmp = 0;
	srand(time(NULL));
	for (int i = 0; i < x; i++) {


		
		char litery[] = { 'F', 'C', 'K' };
		int los = rand() % 3;
		//cout << litery[los];
		if (litery[los] == 'F') {
			int tmp = rand() % (1000 - (-459) + 1) + (-459);
			tab[dataCounter][0] = tmp;
			znak[dataCounter][1] = 'F';
			
			
			char litery2[] = { 'C', 'K' };
			int los2 = rand() % 2;
			if (litery2[los2] == 'C'){
				tab[dataCounter][2] = FtoC(tmp);
				znak[dataCounter][3] = 'C';
			}
			else {
				tab[dataCounter][2] = FtoK(tmp);
				znak[dataCounter][3] = 'K';
			}
			
			dataCounter = dataCounter + 1;

		}
		else if (litery[los] == 'K') {
			int tmp = rand() % 1001;
			tab[dataCounter][0] = tmp;
			znak[dataCounter][1] = 'K';
			
			char litery2[] = { 'C', 'F' };
			int los2 = rand() % 2;
			if (litery2[los2] == 'C') {
				tab[dataCounter][2] = KtoC(tmp);
				znak[dataCounter][3] = 'C';
			}
			else {
				tab[dataCounter][2] = KtoF(tmp);
				znak[dataCounter][3] = 'F';
			}
			dataCounter = dataCounter + 1;
		}
		else if (litery[los] == 'C') {
			int tmp = rand() % (727 - (-273) + 1) + (-273);
			tab[dataCounter][0] = tmp;
			znak[dataCounter][1] = 'C';
			
			char litery2[] = { 'F', 'K' };
			int los2 = rand() % 2;
			if (litery2[los2] == 'F') {
				tab[dataCounter][2] = CtoF(tmp);
				znak[dataCounter][3] = 'F';
			}
			else {
				tab[dataCounter][2] = CtoK(tmp);
				znak[dataCounter][3] = 'K';
			}
			dataCounter = dataCounter + 1;
		}


	}
	return 1;
}

int los() {
	int wartosc = 0;
	int decyzja = 0; 
	cout << "Ile losowych wartosci przeliczyc? ";


	cin >> wartosc;
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return 1;
	}
	else if (dataCounter * 2 + wartosc * 2 > 100) {
		cout << "Liczba losow wychodzi po za zakres tablicy," << endl
			<< "czy wygenerowaæ tyle losow ile zostalo miejsca(napisz '1' - jesli chcesz lub '0' - jesli nie.): ";
		cin >> decyzja;
		if (decyzja == 0) {
			return 5;
		}
		else if  (decyzja == 1){
			wartosc = 50 - dataCounter;
			funkcjalos(wartosc);
			return 1;
		}
	

	}
	
	else {
		funkcjalos(wartosc);
		return 1;
	}
}

int edit() {
	int edit;
	float nowaTemp = 0;
	char jednostka = '\0';
	char jednostka2 = '\0';
	float temp = 0;
	int zbadaj = 0;
	float wynik = 0;
	
	
	cout << "Podaj wiersz, ktory chcesz zedytowac: ";
	cin >> edit;
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return -1;
	}
	cout << "Podaj nowa temperature: ";
	cin >> nowaTemp;
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return -1;
	}
	cout << "Podaj jednostke(podaj F, C lub K): ";
	cin >> jednostka;
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return -1;
	}
	cout << "Podaj na co chcesz przeliczyc(podaj F, C lub K): ";
	cin >> jednostka2;
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return -1;
	}
	if ((jednostka == 'F'|| jednostka == 'f') && (jednostka2 == 'C'|| jednostka2 == 'c')) {
		
		zbadaj = check(nowaTemp, 'F');
		if (zbadaj == -999.0) {
			cout << "nie istnieje taka temperatura. " << endl;

		}
		else {
			wynik = FtoC(nowaTemp);
			cout << nowaTemp << " stopni Fahr to " << wynik << " stopni celsiusa." << endl;

		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'F';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'C';
		return 1;
		
	}
	else if ((jednostka == 'F' || jednostka == 'f') && (jednostka2 == 'K' || jednostka2 == 'c')) {
		zbadaj = check(nowaTemp, 'F');
		if (zbadaj == -999.0) {
			cout << "Nie istnieje taka temperatura. " << endl;
		}
		else {
			wynik = FtoK(nowaTemp);
			cout << nowaTemp << " stopni Fahr to " << wynik << " stopni kelwinow" << endl;
		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'F';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'K';
		return 1;
	}
	else if ((jednostka == 'C' || jednostka == 'c') && (jednostka2 == 'F' || jednostka2 == 'f')) {
		zbadaj = check(nowaTemp, 'C');
		if (zbadaj == -999.0) {
			cout << "Nie istnieje taka temperatura. " << endl;
		}
		else {
			wynik = CtoF(nowaTemp);
			cout << nowaTemp << " stopni celsiusa to " << wynik << " stopni Fahr " << endl;
		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'C';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'F';
		return 1;
	}
	else if ((jednostka == 'C'|| jednostka =='c') && (jednostka2 == 'K' ||jednostka2 == 'k')) {
		zbadaj = check(nowaTemp, 'C');
		if (zbadaj == -999.0) {
			cout << "Nie istnieje taka temperatura. " << endl;
		}
		else {
			wynik = CtoK(nowaTemp);
			cout << nowaTemp << " stopni celsiusa to " << wynik << " stopni Kelwinow " << endl;
		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'C';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'K';
		return 1;

	}
	else if ((jednostka == 'K'|| jednostka =='k') && (jednostka2 == 'C'|| jednostka2 == 'c')) {
		zbadaj = check(nowaTemp, 'K');
		if (zbadaj == -999.0) {
			cout << "Nie istnieje taka temperatura. " << endl;
		}
		else {
			wynik = KtoC(nowaTemp);
			cout << nowaTemp << " stopni Kelwina to " << wynik << " stopni celsiusa " << endl;
		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'K';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'C';
		return 1;
	}
	else if ((jednostka == 'K'|| jednostka == 'k') && (jednostka2 == 'F'|| jednostka2 =='f')) {
		zbadaj = check(nowaTemp, 'K');
		if (zbadaj == -999.0) {
			cout << "Nie istnieje taka temperatura. " << endl;
		}
		else {
			wynik = KtoF(nowaTemp);
			cout << nowaTemp << " stopni Kelwinow to " << wynik << " stopni Fahr " << endl;
		}
		tab[edit - 1][0] = nowaTemp;
		znak[edit - 1][1] = 'K';
		tab[edit - 1][2] = wynik;
		znak[edit - 1][3] = 'F';
		return 1;
	}
	else {
		 cout << "zostaly podane zle znaki, historia nie zostala zmieniona!"<< endl;
		 conversionFailed = true;
	 }
	

}









	

int historiacala() {
	for (int i = 0; i < dataCounter; i = i + 1) {
		cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
	}
	return 1;

}

int usuwanie() {
	int entityToRemove = 0;
	cout << "Podaj ktora linijke chcesz usunac: ";
	cin >> entityToRemove;// entitytoremove*2 - 2 i entitytoremove*2- 1 -> indeksy do usuniêcia
	
	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return 1;
	}
	else {
		for (int i = entityToRemove - 1; i <= dataCounter; i++) {
			tab[i][0] = tab[i + 1][0];
			znak[i][1] = znak[i + 1][1];
			tab[i][2] = tab[i + 1][2];
			znak[i][3] = znak[i + 1][3];
		}
		dataCounter -= 1;
		return 1;
	}

	
	/*for (int i = entityToRemove - 1; i <= dataCounter; i++) {
		tab[i][0] = tab[i+1][0];
		znak[i][1] = znak[i + 1][1];
		tab[i][2] = tab[i + 1][2];
		znak[i][3] = znak[i + 1][3];
	}
	dataCounter -= 1;
	return 1;
	*/
}





void menu2() {
	cout << "1. Tylko C - > inne" << endl << "2. Tylko F -> inne" << endl << "3. Tylko K -> inne" << endl << "4. cala historia" << endl;
}

int historia() {
	
	int x = 0;
	cout << "Podaj numer: ";
	cin >> x;

	if (cin.fail()) {
		cin.clear();
		string d;
		getline(cin, d);
		conversionFailed = true;
		return 1;
	}
	if (x < 1 || x > 4) {
		cout << "Nie ma takiej opcji. ";
		return 0;
	}
	else if (x == 1) {
		for (int i = 0; i < dataCounter ; i = i + 1) {
			if (znak[i][1] == 'C') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'C') {
				cout << "Brak danych.";
				break;
				
			}
			
			else {
				return 0;
			}
		}
		return 1;
	}
	else if (x == 2) {
		for (int i = 0; i < dataCounter ; i = i + 1) {
			if (znak[i][1] == 'F') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'F') {
				cout << "Brak danych.";
				break;
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	else if (x == 3) {
		for (int i = 0; i < dataCounter ; i = i + 1) {
			if (znak[i][1] == 'K') {
				cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
			}
			else if (znak[i][1] != 'K') {
				cout << "Brak danych.";
				break;
			}
			else {
				return 0;
			}


		}
		return 1;
	}
	else if (x == 4) {
		for (int i = 0; i < dataCounter ; i = i + 1) {
			cout << "<" << i + 1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
		}
	}
	return 1;
	
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
		<< "7- poka¿ historie" << endl << "8- opcja usuwania z historii" << endl << "9- opcja edytowanie historii" << endl
		<< "10- losowe wypelnianie historii"<< endl << "11- zakonc dzialanie programu " << endl;
}
float pobierzF() {
	float fahr;
	cout << "podaj farh: ";
	cin >> fahr;
	
	if(cin.fail()) {
		cin.clear();
		
		string d;
		getline(cin, d);
		
		conversionFailed = true;
		return 0;
	}
	
	else {
		return fahr;
	}
}
float pobierzK() {
	float x;
	cout << "podaj kelwiny: ";
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cout << "to nie jest liczba";
		string d;
		getline(cin, d);
		conversionFailed = true;
		return 0;

		
	}
	else {
		return x;
	}
	
}
 float pobierzC() {
	float x;
	cout << "podaj celsius ";
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cout << "to nie jest liczba";
		string d;
		getline(cin, d);
		conversionFailed = true;
		return 0;
	}
	else {
		return x;
	}
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




