// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>


int _tmain(int argc, _TCHAR* argv[])
{
	#pragma omp parallel
		printf("Hello world\n");
	return 0;
}

