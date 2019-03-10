#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

namespace funs {
	// potega
	double power(double x, int exponent);

	// wykladnik
	double exponent(int x, double base);

}

namespace custom {
	namespace fun {

		using namespace funs;
		// x^2 - 5
		double fun1(double x);
		// x^4 -x^3 - 50 + x^2
		double fun2(double x);
		// 2^x - 5^x
		double fun3(double x);
		// 5^x + x^3
		double fun4(double x);

		extern double(*functions[4])(double);
	}
}

#endif // !_FUNCTIONS_H_
