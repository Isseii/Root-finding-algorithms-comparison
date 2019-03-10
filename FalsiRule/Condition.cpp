#include <iostream>
#include "Condition.h"

using namespace std;
Epsilon::Epsilon(double &f, double &e) {
	cout << "Podaj wartosc przyblizenia: ";
	cin >> e;
	epsilon = &e;
	fo = &f;
}

bool Epsilon::check() {
	return abs(*fo) > *epsilon;
}

Iteration::Iteration(int &i, int &m) {
	cout << "Podaj liczbe maksymalna liczbe iteracji: ";
	cin >> m;
	counter = &i;
	max = &m;
}

bool Iteration::check() {
	return *counter <= *max;
}

bool Condition::check() {
	return 0;
}