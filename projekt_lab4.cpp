

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float x);
float CtoK(float x);
float KtoC(float x);
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
		return 1;
	}
}


void menu() {
	cout << "1-przelicz Fahr -> Celsius " << endl << "2-przelicz Fahr - > Kelwin" << endl
		<< "3-przelicz Celsius -> Fahr" << endl << "4- przelicz celsius -> kelwin " << endl
		<< "5- przelicz Kelwin - > Celsius " << endl << "6-przelicz Kelwin -> Fahr" << endl
		<< "7- zakonc dzialanie programu " << endl;
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

int main() {
	while (true) {
		menu();
		float temp;
		float wynik;
		int wybor;
		int zbadaj;
		cout << "wybierz ";
		cin >> wybor;

		switch (wybor) {
		case 1:
			
			cout << "1-przeliczanie Fahr -> celsius: ";
			temp = pobierzF();
			zbadaj = check(temp, 'F');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";

			}
			else {
				wynik = FtoC(temp);
				cout << temp << " stopni Fahr to " << wynik << " stopni celsiusa.";

			}

			break;
		case 2:
			cout << "2-przelicz Fahr -> Kelwin: " << endl;
			temp = pobierzF();
			zbadaj = check(temp, 'F');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";

			}
			else {
				wynik = FtoK(temp);
				cout << temp << " stopni Fahr to " << wynik << " stopni Kelwina.";
			}
			break;
		case 3:
			cout << "przelicz Celsius -> Fahr: " << endl;
			temp = pobierzC();
			zbadaj = check(temp, 'C');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";

			}
			else {
				wynik = CtoF(temp);
				cout << temp << " stopni celsiusa to " << wynik << " stopni Farh.";
			}
			break;
		case 4:
			cout << "4- przelicz celsius -> kelwin: " << endl;
			temp = pobierzC();
			zbadaj = check(temp, 'C');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";

			}
			else {
				wynik = CtoK(temp);
				cout << temp << " stopni celsiusa to " << wynik << " stopni Kelwina.";
			}
			break;
		case 5:
			cout << "5- przelicz Kelwin - > Celsius: " << endl;
			temp = pobierzK();
			zbadaj = check(temp, 'K');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";
			}
			else {
				wynik = KtoC(temp);
				cout << temp << " stopni kelwina to " << wynik << " stopni Celsiusa.";
			}
			break;
		case 6:
			cout << "6 - przelicz Kelwin -> Fahr: " << endl;
			temp = pobierzK();
			zbadaj = check(temp, 'K');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. ";
			}
			else {
				wynik = KtoF(temp);
				cout << temp << " stopni Kelwina to " << wynik << " stopni Fahr.";
			}
			break;
		}
		if (wybor > 6 or wybor < 1) {
			cout << "program zostaje wylączony ";
			return 0;
		}
		cout << "wcisnij enter by rozpaczac ponownie.";
		string enter;
		cin.ignore();
		getline(cin, enter);
		
		system("cls");
	}
}


/*
int main() {
	menu();
	int wybor;
	cout << "wybierz ";
	cin >> wybor;
	switch(wybor) {
	case 1:
		cout << "1-przeliczanie Fahr -> kelw: ";
		float x, y;//x-fahr, y-cels
		x = pobierzF();
		y = FtoC(x);
		cout << x << " fahr" << " -> " << y << " Celsius " << endl;
				
		break;
	case 2:
		cout << "2-przelicz Fahr -> Kelwin: " << endl;
		float a,b;//a- fahr, b-kelwin
		a = pobierzF();
		b = FtoK(a);
		cout << a << " fahr" << " -> " << b << " kelw" << endl;
		break;
	case 3:
		cout << "przelicz Celsius -> Fahr: " << endl;
		float c, d;//c-celsius, d-fahr
		c = pobierzC();
		d = CtoF(c);
		cout << c << " celsius" << " -> " << d << " fahr" << endl;
		break;
	case 4:
		cout << "4- przelicz celsius -> kelwin: " << endl;
		float e,f ;//e-celsius, f-kelw
		e = pobierzC();
		f = CtoK(e);
		cout << e << " celsius" << " -> " << f << " kelw" << endl;
		break;
	case 5:
		cout << "5- przelicz Kelwin - > Celsius: " << endl;
		float kelw, celsius;
		kelw = pobierzK();
		celsius = KtoC(kelw);
		cout << kelw << " kelw" << " -> " << celsius << " celsius" << endl;
		break;
	case 6:
		cout << "6 - przelicz Kelwin -> Fahr: " << endl;
		float g, fahr; //g-kelw
		g = pobierzK();
		fahr = KtoF(g);
		cout << g << " kelw" << " -> " << fahr << " fahr" << endl;
		break;

	}
	if (wybor > 6 or wybor < 1) {
		cout << "program zostaje wylączony " ;
		return 0;
	}
	


	
}

*/


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





