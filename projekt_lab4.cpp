

#include <iostream>
using namespace std;
float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float x);
float CtoK(float x);
float KtoC(float x);
float KtoF(float x);
void menu();
void menu() {
	cout << "1-przelicz Fahr -> Celsius " << endl << "2-przelicz Fahr - > Kelwin" << endl
		<< "3-przelicz Celsius -> Fahr" << endl << "4- przelicz celsius -> kelwin " << endl
		<< "5- przelicz Kelwin - > Celsius " << endl << "6-przelicz Kelwin -> Fahr" << endl
		<< "7- zakonc dzialanie programu " << endl;
}

int main() {
	menu();
	int wybor;
	cout << "wybierz ";
	cin >> wybor;
	switch(wybor) {
	case 1:
		cout << "Przeliczanie Fahr na Celsius: " << endl;
		float fahr, celsius;
		for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
			celsius = FtoC(fahr);
			cout << fahr << " " << celsius << endl;
		}
		break;
	case 2:
		cout << "2-przelicz Fahr - > Kelwin: " << endl;
		float fahr, kelw;
		for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
			kelw = FtoK(fahr);
			cout << kelw << " " << celsius << endl;
		}
		break;
	case 3:
		cout << "przelicz Celsius -> Fahr: " << endl;
		float celsius, fahr;
		for (celsius = 0.0; celsius <= 200; celsius = celsius + 20) {
			fahr = CtoF(celsius);
		}
		break;
	case 4:


	}

	

	
}



/*int main() {
	float fahr, celsius;
	for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
		celsius = FtoC(fahr);
		cout << fahr << " " << celsius << endl;
	}
	return 0; 
		
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





