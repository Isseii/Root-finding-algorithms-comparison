#include <iostream>
#include <thread>
#include <math.h>

#include "Configuration.h"
#include "Functions.h"
#include "Condition.h"
#include "RootFinder.h"

#include "gnuplot_i.hpp"


double a, b, epsilon;
int iter, fun_i, con_i;
double(*fun)(double);
Condition * warunek;

int main() {
	std::string path = "A:\\Program Files/gnuplot\\bin";
	Gnuplot::set_GNUPlotPath(path);
	Gnuplot main_plot;
	main_plot.set_title("tytul wykresu");
	main_plot.set_xlabel("podpis osi odcietych");
	main_plot.set_ylabel("podpis osi rzednych");
	main_plot.set_style("lines");
	main_plot.set_grid();
	main_plot.set_xrange(-6, 6);
	main_plot.set_yrange(-4, 4);
	main_plot.plot_equation("(x**4 + x**3 - 2*x**2 - sin(x**2))", "");
	

	//double x = pow(1.7, 2.5);

	//std::cout << std::boolalpha << (l==std::numeric_limits<double>::infinity()) << std::endl;

	fun_i = conf::fun_selection();
	fun = custom::fun::functions[fun_i];

	std::tie(a, b) = conf::specify_range(fun);

	con_i = conf::specify_condition();
	switch (con_i) {
	case 1: warunek = new Epsilon(epsilon); break;
	case 2: warunek = new Iteration(iter); break;
	}

	using namespace std;
	auto lambda = [](auto res) {
		cout << "finished" << endl;
		cout << "Metoda: " << res.method << endl;
		cout << "Iteracje: " << res.iterations << endl;
		cout << "Wynik: " << res.value << endl;
	};
    auto result = std::thread(root::finder::falsi, fun, a, b, warunek, con_i, lambda);

	cout << "im here" << endl;
	result.join();

	system("pause");
	return 0;
}