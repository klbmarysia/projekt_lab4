

#include <iostream>
#include <stdlib.h>
#include <string>
#include "headerFile.h"

using namespace std ;




int main() {
	
	while (true) {
		
		if (dataCounter >= 50) {
			cout << "przeliczenia od teraz nie beda zapisywane!"<< endl;
		}
		menu();
		float temp=0;
		float wynik = 0;
		int wybor=0;
		int zbadaj=0;
		char znak1 = '\0';
		char znak2 = '\0';
		int n = 1;
		int line = 1;
		
		cout << "wybierz ";
		cin >> wybor;
		if (cin.fail()) {
			cin.clear();
			cout << "to nie jest liczba, wcisnij eter by rozpaczac ponownie :)";
			string d;
			getline(cin, d);
			cin.ignore();
			system("cls");
			continue;
		}

		switch (wybor) {
		case 1:
			
			cout << "1-przeliczanie Fahr -> celsius: " << endl;
			temp = pobierzF();
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie"<< endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
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
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
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
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
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
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
			zbadaj = check(temp, 'C');
			if (zbadaj == -999.0) {
				cout << "nie istnieje taka temperatura. "<<endl;

			}
			else {
				wynik = CtoK(temp);
				cout << temp << " stopni celsiusa to " << wynik << " stopni Kelwina."<< endl;
			}
			znak1 = 'C';
			znak2 =  'K';
			break;
		case 5:
			cout << "5- przelicz Kelwin - > Celsius: " << endl;
			temp = pobierzK();
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
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
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
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
		case 7:
			menu2();
			historia();
			if (conversionFailed) {
				cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
				string lol;
				getline(cin, lol);
				cin.ignore();
				system("cls");
				conversionFailed = false;
				continue;
			}
			break;
		case 8:
			if (dataCounter > 0) {


				system("cls");
				historiacala();
				usuwanie();
				if (conversionFailed) {
					cout << "Nie prawidlowa wartosc, wcisnij enter by rozpoczac ponownie" << endl;
					string lol;
					getline(cin, lol);
					cin.ignore();
					system("cls");
					conversionFailed = false;
					continue;
				}
				historiacala();
			}
			else {
				cout << "Nie mozesz usunac nic z historii, bo jej nie masz :)" << endl;
				string d;
				getline(cin, d);
				cin.ignore();
				system("cls");
				continue;
			}
			break;
		case 9:
			if (dataCounter > 0) {
				system("cls");
				historiacala();

				edit();
				if (conversionFailed) {
					cout << "Blad, wcisnij enter by rozpoczac ponownie" << endl;
					string lol;
					getline(cin, lol);
					cin.ignore();
					system("cls");
					conversionFailed = false;
					continue;
				}
			}
			else {
				cout << "nie mozesz edytowac historii, bo jej nie masz." << endl;
				string d;
				getline(cin, d);
				cin.ignore();
				system("cls");
				continue;
			}

		case 10:
			los();
			
			historiacala();
			



		}
		if (wybor > 10 or wybor < 1) {
			cout << "program zostaje wylączony " << endl;
			return 0;
		}
		
		


			
		
		
		if (dataCounter < 50 && wybor >= 1 && wybor < 7) {
			tab[dataCounter][0] = temp;
			tab[dataCounter][2] = wynik;
			znak[dataCounter][1] = znak1;
			znak[dataCounter][3] = znak2;
			dataCounter = dataCounter + 1;
		}
		
		
		cout << "wcisnij enter by rozpaczac ponownie.";
		string enter;
		cin.ignore();
		getline(cin, enter);
		system("cls");
		
	}

}








