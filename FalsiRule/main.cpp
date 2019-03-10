#include <iostream>

#include "Configuration.h"
#include "Functions.h"
#include "Condition.h"
#include "rootfinder.h"

double a, b, epsilon, fa, fb, fo;
int iter, i, fun_i, con_i;
double(*fun)(double);
Condition * warunek;


int main() {
	fun_i = conf::fun_selection();
	fun = custom::fun::functions[fun_i - 1];

	std::tie(a, b) = conf::specify_range(fun);

	con_i = conf::specify_condition();
	switch (con_i) {
	case 1: warunek = new Epsilon(fo, epsilon); break;
	case 2: warunek = new Iteration(i, iter); break;
	}
	

	using namespace std;
	auto result = root::finder::falsi(fun, a, b, warunek, i, fo);
	cout << "Metoda: " << result.method << endl;
	cout << "Iteracje: " << result.iterations << endl;
	cout << "Wynik: " << result.value << endl;

	system("pause");
	return 0;
}