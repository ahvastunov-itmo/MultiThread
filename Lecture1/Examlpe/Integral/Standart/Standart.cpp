// Standart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>


double liner(double x){
	return x;
}

int _tmain(int argc, _TCHAR* argv[])
{
	time_t start_time;
	time_t finish_time;

	int eteration_count = 100000000000; // количество итераций
	int a = 0;						 // левая граница интегрирования
	int b = 1;						 // правая граница интегрирования
	double x;

	time(&start_time);

	double step = (double)(b - a) / eteration_count;
	double total = (liner(a) + liner(b))*step / 2;
	for (int i = 0; i < eteration_count; ++i)
	{	
		x = a + i* step;
		total += liner(x)*step;
	}	
	time(&finish_time);

	std::cout << "Result is: " << total << " Operation time: " << difftime(finish_time, start_time) << std::endl;
	return 0;
}

