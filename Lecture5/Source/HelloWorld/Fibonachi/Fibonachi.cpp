// Fibonachi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <omp.h>


long long  fibonachi(long int n)
{
	if (n == 0 || n == 1)
		return 1;
	return fibonachi(n - 1) + fibonachi(n - 2);
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	long long fib[40];
//	time_t begin, end;
//	time(&begin);
//
//	#pragma omp parallel
//	{
//		#pragma omp for
//		for (int i = 0; i < 40; i++){
//			fib[i] = fibonachi(i);
//		}
//	}
//	time(&end);
//
//	printf("%f\n", difftime(end, begin));
//
//	return 0;
//}

//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	long long fib[40];
//	time_t begin, end;
//	time(&begin);
//
//	#pragma omp parallel
//	{
//		#pragma omp for ordered schedule(static, 1)
//		for (int i = 0; i < 40; i++){
//			fib[i] = fibonachi(i);
//		}
//	}
//	time(&end);
//
//	printf("%f\n", difftime(end, begin));
//
//	return 0;
//}


int _tmain(int argc, _TCHAR* argv[])
{
	long long fib[40];
	time_t begin, end;
	time(&begin);

	#pragma omp parallel
	{
		#pragma omp for ordered schedule(static,1)
		for (int i = 0; i < 40; i++){
			fib[i] = fibonachi(i);
			#pragma omp ordered
			{
				printf("%i ", fib[i]);
			}
		}
	}
	time(&end);

	printf("%f\n", difftime(end, begin));

	return 0;
}


