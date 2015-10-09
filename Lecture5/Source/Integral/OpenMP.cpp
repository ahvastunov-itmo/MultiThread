// OpenMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>
#include <time.h>
#include <iostream>

/*
линейная функция для интеграции
*/
double liner(double x){
	return x;
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
	time_t start_time;
	time_t finish_time;

	int eteration_count = 100000; // количество итераций
	int a = 0;						 // левая граница интегрирования
	int b = 1;						 // правая граница интегрирования
	double x;

	time(&start_time);

	double step = (double)(b - a) / eteration_count;
	double total = (liner(a) + liner(b))*step / 2;
	

	double t = 0;
	#pragma omp parallel for
	for (int i = 0; i < eteration_count; ++i)
	{
		x = a + i* step;
		total += liner(x)*step;
	}
	

	
	time(&finish_time);

	std::cout << "Result is: " << total << " Operation time: " << difftime(finish_time, start_time) << std::endl;
	return 0;
}
*/

/*
int _tmain(int argc, _TCHAR* argv[])
{
	time_t start_time;
	time_t finish_time;

	int eteration_count = 10000000; // количество итераций
	int a = 0;						 // левая граница интегрирования
	int b = 1;						 // правая граница интегрирования

	time(&start_time);

	double total = 0;
	double x;
	double step = (float)(b - a) / eteration_count;

	total = (liner(a) + liner(b))*step / 2;

	#pragma omp parallel for private(x)
	for (int i = 0; i < eteration_count; ++i){
		x = a + i*step;
		total += liner(x)*step;
	}

	time(&finish_time);
	std::cout << "Result is: " << total << " Operation time: " << difftime(finish_time, start_time) << std::endl;
	return 0;
}

*/

/*

int _tmain(int argc, _TCHAR* argv[])
{
	time_t start_time;
	time_t finish_time;

	int eteration_count = 10000000000; // количество итераций
	int a = 0;						 // левая граница интегрирования
	int b = 1;						 // правая граница интегрирования

	time(&start_time);

	double total = 0;
	double x;
	double step = (float)(b - a) / eteration_count;

	int num_of_threads = omp_get_num_threads();
	double* totals = new double[num_of_threads];
	total = (liner(a) + liner(b))*step / 2;
	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		#pragma omp for private(x) nowait
		for (int i = 0; i < eteration_count; ++i){
			totals[id] += liner(a + i*step)*step;
		}
		#pragma omp critical
		total += totals[id];
	}

	time(&finish_time);
	std::cout << "Result is: " << total << " Operation time: " << difftime(finish_time, start_time) << std::endl;


	delete totals;
	return 0;
}



*/



int _tmain(int argc, _TCHAR* argv[])
{
	time_t start_time;
	time_t finish_time;

	int eteration_count = 100000000; // количество итераций
	int a = 0;						 // левая граница интегрирования
	int b = 1;						 // правая граница интегрирования

	time(&start_time);
	
	double total = 0;
	double x;
	double step = (float)(b - a) / eteration_count;

	total = (liner(a) + liner(b))*step / 2;
	#pragma omp parallel
	#pragma omp for	private(x) reduction(+:total)
	for (int i = 0; i < eteration_count; ++i){
		x = a + i*step;
		total += liner(x)*step;
	}

	time(&finish_time);
	std::cout << "Result is: " << total << " Operation time: " << difftime(finish_time, start_time) << std::endl;
	return 0;
}

