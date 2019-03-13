#include <iostream>
#include "Condition.h"

using namespace std;
Epsilon::Epsilon(double &e) {
	cout << "Podaj wartosc przyblizenia: ";
	cin >> e;
	epsilon = &e;
}

bool Epsilon::check(void *addr) {
	double fo = *(double*)addr;
	return abs(fo) > *epsilon;
}


Iteration::Iteration(int &m) {
	cout << "Podaj liczbe maksymalna liczbe iteracji: ";
	cin >> m;
	max = &m;
}

bool Iteration::check(void *addr) {
	int i = *(int*)addr;
	return i <= *max;
}

