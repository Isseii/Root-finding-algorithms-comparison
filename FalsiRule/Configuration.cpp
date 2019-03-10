#include "Configuration.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace conf;
using namespace std;

// wybieranie funkcji
int conf::fun_selection()
{
	cout << "Wskaz funkcje" << endl;

	char selection; // zmienna do której wprowadzamy wybór
	int option = 0; // `x` bedzie zawiera³ liczbê [1,4] odpowiadajac¹ danej funkcji

	while (!option) {
		selection = _getch(); // alternatywa dla ` cin >> `
		option = extractSelection(selection, 4);
	}

	cout << "Wybor: " << selection << endl;

	return option;
}

// okreslanie zakresu poszukiwan
tuple<double, double> conf::specify_range(double (*fun)(double))
{
	cout << "Podaj zakres poszukiwan ( w formacie [a,b] ! )" << endl;
	double x = 1, y = 1;
	string temp;
	do {
		getline(cin, temp);
		if (sscanf_s(temp.c_str(), "[%lf,%lf]", &x, &y) < 2) {
			cout << "Nieprawidlowe dane" << endl;
			x = y = 1;
			continue;
		}

		cout << ((x * y) > 0 ? "Warunek ` a * b < 0 ` nie zostal spelniony" : "") << endl;

	} while (fun(x)*fun(y) > 0);

	cout << "[ a: " << x << ", b: " << y << " ]" << endl;

	return std::tuple<double, double>(x,y);
}

// okreslenie warunku konca poszukiwan
int conf::specify_condition()
{
	cout << "Okresl w jaki sposob algorytm powinien zostac zatrzymany: " << endl;
	cout << " a) dokladnosc \t b) wykonanie iteracji" << endl;

	int conSelect = 0;
	char selection;

	while (!conSelect) {
		selection = _getch();
		conSelect = extractSelection(selection, 2);
	}

	cout << "Wybor: " << selection << endl;

	return conSelect;
}

// przerabia podanego chara na indeks w zakresie od znaku `a` do `a` + `range` 
int conf::extractSelection(char s, int range) {

	if (!('a' <= s && s < 'a' + range)) return 0; // wartosc jest poza poprawnym zakresem

	int x = s - 96; // przeksztac wartosc na int z zakresu [1,4]

	return x;
}
