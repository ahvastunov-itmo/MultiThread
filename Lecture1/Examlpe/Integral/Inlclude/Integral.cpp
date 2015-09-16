#include "stdafx.h"
#include "Integral.h"


double integrate(const std::function<double(double)>& func, const double a, const double b, const int n){
	double step = (b - a) / n;

	double result = (func(a) + func(b))*step / 2;
	for (int i = 0; i < n; ++i){
		result += func(a + i* step)*step;
	}

	return result;
}


