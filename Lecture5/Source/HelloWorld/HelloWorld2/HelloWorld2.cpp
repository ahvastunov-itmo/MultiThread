// HelloWorld2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int thread_id, thread_num;
	#pragma omp parallel private(thread_id)
	{
		thread_id = omp_get_thread_num();
		printf("%d Hello world\n", thread_id);
		
		if (thread_id == 0){
			thread_num = omp_get_num_threads();
			printf("Number of threads %d\n", thread_num);
		}
	}
	
	
	return 0;
}


