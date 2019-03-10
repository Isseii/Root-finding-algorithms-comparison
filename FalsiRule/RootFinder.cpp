#include "rootfinder.h"

using namespace root::finder;

//RootResult falsi() {
//	return;
//}

// conf
	//double epsilon = 0.00001;
	//double a = -1;
	//double b = 3;
	//int iter = 16;
	//int i = 0;
	//bool op = false;
	//// wsk
	//double(*fun)(double) = fun_quad;
	//bool(*condition)(int, int, double, double) = aproximation;
	//double fa, fb, fo, xa = a, xb = b;
	//fa = fun(a); fb = fun(b);

	//if (fa*fb > 0) return 1;

	//do {
	//	xa = xb;
	//	xb = a - fa*((b - a) / (fb - fa));
	//	fo = fun(xb);

	//	if (fo*fa < 0) {
	//		b = xb; fb = fo;
	//	}
	//	else {
	//		a = xb; fa = fo;
	//	}
	//	i++;
	//} while (condition(i, iter, epsilon, abs(fo)));
	//	
	//std::cout << xb << std::endl;


double example_fun(double x) {
	return 50 * x * x * x + 5;
}

double fun_quad(double x) {
	return x * x * x * x - 5;
}

auto aproximation(int i, int c, double e, double f) { return f > e; }

auto iteration(int i, int c, double e, double f) { return i <= c; }

RootResult root::finder::falsi(double(*fun)(double), double a, double b, Condition *warunek, int &i, double &fo)
{
	double fa= fun(a), fb=fun(b), xa = a, xb =b;
	RootResult result;
	result.method = "FALSI";
	result.range_a = a;
	result.range_b = b;
	do {
		xa = xb;
		xb = a - fa * ((b - a) / (fb - fa));
		fo = fun(xb);

		if (fo*fa < 0) {
			b = xb; fb = fo;
		}
		else {
			a = xb; fa = fo;
		}
		i++;
	} while (warunek->check());
	result.iterations = i;
	result.value = xb;

	return result;
}
