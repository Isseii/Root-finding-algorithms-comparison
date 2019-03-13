#ifndef _ROOTFINDER_H_
#define _ROOTFINDER_H_

#include <string>
#include "Condition.h"

namespace root {
	namespace finder {

		class RootResult {
		public:
			int iterations;
			std::string method;
			double value;
			double range_a;
			double range_b;
		};
		RootResult falsi(double(*fun)(double), double a, double b, Condition *warunek, int con, void(*callback)(RootResult));

		RootResult bisection();
	}
}

#endif // !_ROOTFINDER_H_
