

#include <iostream>
#include <stdlib.h>
#include <string>
#include "headerFile.h"

using namespace std ;




int main() {
	while (true) {
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
			znak2 =  'K';
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
		case 7:
			for (int i = 0; i < dataCounter/2 ; i = i + 1) {
				cout << "<" << i+1 << "> " << tab[i][0] << " " << znak[i][1] << " " << tab[i][2] << " " << znak[i][3] << endl;
				
				

			}
			return 0;
		}
		if (wybor > 7 or wybor < 1) {
			cout << "program zostaje wylączony " << endl;
			return 0;
		}
		
		tab[dataCounter/2][0] = temp;
		tab[dataCounter/2][2] = wynik;
		znak[dataCounter/2][1] = znak1;
		znak[dataCounter/2][3] = znak2;
		
		
		
		
		dataCounter = dataCounter + 2;
		cout << "wcisnij enter by rozpaczac ponownie.";
		string enter;
		cin.ignore();
		getline(cin, enter);
		system("cls");
		
	}

}








