

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
		float x, y;//x - fahr, y- celsius
		for (x = 0.0; x <= 200; x = x + 20) {
			y = FtoC(x);
			cout << x << " -> " << y << endl;
		}
		break;
	case 2:
		cout << "2-przelicz Fahr - > Kelwin: " << endl;
		float a,b;//a- fahr, b-kelwin
		for (a = 0.0; a <= 200; a = a + 20) {
			b = FtoK(a);
			cout << a << " -> " << b << endl;
		}
		break;
	case 3:
		cout << "przelicz Celsius -> Fahr: " << endl;
		float c, d;//c-celsius, d-fahr
		for (c = 0.0; c <= 200; c = c + 20) {
			d = CtoF(c);
			cout << c << " -> " << d << endl;
		}
		break;
	case 4:
		cout << "4- przelicz celsius -> kelwin: " << endl;
		float e,f ;//e-celsius, f-kelw
		for (e = 0.0; e <= 200; e = e + 20) {
			f = CtoK(e);
			cout << e << " ->" << f << endl;
		}
		break;
	case 5:
		cout << "5- przelicz Kelwin - > Celsius: " << endl;
		float kelw, celsius;
		for (kelw = 0.0; kelw <= 200; kelw = kelw + 20) {
			celsius = KtoC(kelw);
			cout << kelw << " -> " << celsius << endl;

		}
		break;
	case 6:
		cout << "6 - przelicz Kelwin->Fahr" << endl;
		float g, fahr; //g-kelw
		for (g = 0.0; g <= 200; g = g + 20) {
			fahr = KtoF(g);
			cout << g << " -> " << fahr << endl;
		}

	}
	if (wybor > 6 or wybor < 1) {
		cout << "program zostaje wylączony " ;
		return 0;
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





