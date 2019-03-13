#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_
#include <tuple>

namespace conf {
	// wybieranie funkcji
	int fun_selection();

	// okreslanie zakresu poszukiwan
	std::tuple<double, double> specify_range(double(*fun)(double));

	// okreslenie warunku konca poszukiwan
	int specify_condition();

	// przerabia podanego chara na indeks w zakresie od znaku `a` do `a` + `range` 
	int extractSelection(char s, int range);
}

#endif // !_CONFIGURATION_H_
