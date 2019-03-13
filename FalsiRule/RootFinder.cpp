#include "RootFinder.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace root::finder;

RootResult root::finder::falsi(double(*fun)(double), double a, double b, Condition *warunek, int con, void(*callback)(RootResult))
{
	std::cout << "falsi started..." << std::endl;
	double fa = fun(a), fb = fun(b), xa = a, xb = b, fo;
	int i = 0;
	void* var = nullptr;
	switch (con)
	{
	case 1: var = &fo; break;
	case 2: var = &i;  break;
	}
	RootResult result;
	result.method = "FALSI";
	result.range_a = a;
	result.range_b = b;
	do {
		xa = xb;
		xb = a - fa * ((b - a) / (fb - fa));
		fo = fun(xb);

		if (fo == std::numeric_limits<double>::infinity()) {
			std::cout << "The hell ?" << std::endl;
		}
		if (fo*fa < 0) {
			b = xb; fb = fo;
		}
		else {
			a = xb; fa = fo;
		}
		i++;
	} while (warunek->check(var) && fo != 0);
	result.iterations = i;
	result.value = xb;
	callback(result);
	return result;
}
