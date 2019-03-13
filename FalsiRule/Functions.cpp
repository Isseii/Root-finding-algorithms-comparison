#include "Functions.h"
#include <stdlib.h>

double funs::power(double x, int exponent)
{
	if (exponent == 0) return 1;
	double result = x;
	for (int i = 1; i < abs(exponent); i++) {
		result *= x;
	}
	if (exponent < 0) return 1 / result;
	return result;
}

double funs::exponent(int x, double base)
{
	if (x == 0) return 1;
	double result = base;
	for (int i = 1; i < abs(x); i++) {
		result *= base;
	}
	if (x < 0) return 1 / result;
	return result;
}

double custom::fun::fun1(double x)
{
	return power(x, 2) - 4;
}

double custom::fun::fun2(double x)
{
	return power(x, 4) - power(x, 3) - 50 + power(x, 2);
}

double custom::fun::fun3(double x)
{
	return exponent(x, 2) - exponent(x, 5);
}

double custom::fun::fun4(double x)
{
	return exponent(x, 5) + power(x, 3);
}
namespace custom {
	namespace fun {
		using namespace custom::fun;
		extern double(*functions[4])(double) { fun1, fun2, fun3, fun4 };
	}
}
