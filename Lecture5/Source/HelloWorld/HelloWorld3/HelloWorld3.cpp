// HelloWorld3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>

int _tmain(int argc, _TCHAR* argv[])
{
	#pragma omp parallel
	#pragma omp for
	for (int i = 0; i < 10; i++){
		printf("%d: Hello world from thread %d\n", i, omp_get_thread_num());
	}

	return 0;
}

