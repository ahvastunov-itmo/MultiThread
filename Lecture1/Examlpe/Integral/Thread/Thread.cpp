// Thread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Inlclude/Integral.h"
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

std::mutex mutex;
double result;

void thread_integrate(int a, int b, int step_count){
	
	double part_integral = integrate(a, b, step_count);	
	std::lock_guard<std::mutex> guard(mutex);
	result += part_integral;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int thread_count = 4;

	if (argc == 2)
		thread_count = _wtoi(argv[1]);

	std::vector<std::thread> threads;
	double step_length = ((double)(b - a))/thread_count;
	
	time_t start_time;
	time_t finish_time;	
	time(&start_time);

	for (int i = 0; i < thread_count; ++i){
		threads.push_back(std::thread(thread_integrate, a + step_length*i, 
									  a + step_length*(i + 1), eteration_count / thread_count));
	}

	for (auto it = threads.begin(); it != threads.end(); ++it){
		if ((*it).joinable())
			(*it).join();
	}
	
	time(&finish_time);

	std::cout << "Result is: " << result << " Operation time: " << difftime(finish_time, start_time) << std::endl;
	getchar();

	return 0;
}

