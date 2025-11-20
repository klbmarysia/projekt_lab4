

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
double tab[100];
char znak[100];
int dataCounter = 0;


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
		float temp=0;
		float wynik = 0;
		int wybor=0;
		int zbadaj=0;
		char znak1;
		char znak2;
		cout << "wybierz ";
		cin >> wybor;

		switch (wybor) {
		case 1:
			
			cout << "1-przeliczanie Fahr -> celsius: " << endl;
			temp = pobierzF();
			zbadaj = check(temp, 'F');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. " << endl;

			}
			else {
				wynik = FtoC(temp);
				cout << temp << " stopni Fahr to " << wynik << " stopni celsiusa." << endl;

			}
			znak1 = 'F';
			znak2 = 'C';
			break;
		case 2:
			cout << "2-przelicz Fahr -> Kelwin: " << endl;
			temp = pobierzF();
			zbadaj = check(temp, 'F');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. " << endl;

			}
			else {
				wynik = FtoK(temp);
				cout << temp << " stopni Fahr to " << wynik << " stopni Kelwina." << endl;
			}
			znak1 = 'F';
			znak2 = 'K';
			break;
		case 3:
			cout << "przelicz Celsius -> Fahr: " << endl;
			temp = pobierzC();
			zbadaj = check(temp, 'C');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. " << endl;

			}
			else {
				wynik = CtoF(temp);
				cout << temp << " stopni celsiusa to " << wynik << " stopni Farh."<<endl;
			}
			znak1 = 'C';
			znak2 = 'F';
			break;
		case 4:
			cout << "4- przelicz celsius -> kelwin: " << endl;
			temp = pobierzC();
			zbadaj = check(temp, 'C');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. "<<endl;

			}
			else {
				wynik = CtoK(temp);
				cout << temp << " stopni celsiusa to " << wynik << " stopni Kelwina."<< endl;
			}
			znak1 = 'C';
			znak2 = 'K';
			break;
		case 5:
			cout << "5- przelicz Kelwin - > Celsius: " << endl;
			temp = pobierzK();
			zbadaj = check(temp, 'K');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. "<< endl;
			}
			else {
				wynik = KtoC(temp);
				cout << temp << " stopni kelwina to " << wynik << " stopni Celsiusa."<< endl;
			}
			znak1 = 'K';
			znak2 = 'C';
			break;
		case 6:
			cout << "6 - przelicz Kelwin -> Fahr: " << endl;
			temp = pobierzK();
			zbadaj = check(temp, 'K');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. " << endl;;
			}
			else {
				wynik = KtoF(temp);
				cout << temp << " stopni Kelwina to " << wynik << " stopni Fahr."<< endl;
			}
			znak1 = 'K';
			znak2 = 'F';
			break;
		}
		if (wybor > 6 or wybor < 1) {
			cout << "program zostaje wylączony " << endl;
			return 0;
		}
		
		tab[dataCounter] = temp;
		tab[dataCounter + 1] = wynik;
		znak[dataCounter] = znak1;
		znak[dataCounter+1] = znak2;
		dataCounter = dataCounter + 2;
		int linia = dataCounter / 2;
		for (int i = 0; i <= linia; i= i +2) {
			cout << tab[i]<<" " << znak[i]<<" " << tab[i + 1] <<" " << znak[i + 1]<<" " << endl;

		}
		cout << "wcisnij enter by rozpaczac ponownie.";
		string enter;
		cin.ignore();
		getline(cin, enter);
		system("cls");
		
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





