#include "Functions.h"

double funs::power(double x, int exponent)
{
	double result = x;
	for (int i = 1; i < exponent; i++) {
		result *= x;
	}
	return result;
}

double funs::exponent(int x, double base)
{
	double result = base;
	for (int i = 1; i < x; i++) {
		result *= base;
	}
	return result;
}

double custom::fun::fun1(double x)
{
	return power(x, 2) - 5;
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
