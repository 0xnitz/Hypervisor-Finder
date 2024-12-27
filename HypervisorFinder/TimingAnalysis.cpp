#include "TimingAnalysis.hpp"

#include <intrin.h>
#include <Windows.h>

namespace TimingAnalysis
{

double cpuid_timing()
{
	double cpuid_time = 0;
	LARGE_INTEGER start_ticks = {};
	LARGE_INTEGER end_ticks = {};
	static cpuid_arguments CPUID_ARGUMENTS;

	for (size_t i = 0; i < TIMES_TO_RUN_INSTRUCTION; i++)
	{
		QueryPerformanceCounter(&start_ticks);
		__cpuid(reinterpret_cast<int*>(&CPUID_ARGUMENTS), 1);
		QueryPerformanceCounter(&end_ticks);

		double delta = end_ticks.QuadPart - start_ticks.QuadPart;

		cpuid_time += delta;
	}

	return cpuid_time / TIMES_TO_RUN_INSTRUCTION;
}

double rdtsc_timing()
{
	double rdtsc_time = 0;
	LARGE_INTEGER start_ticks = {};
	LARGE_INTEGER end_ticks = {};

	for (size_t i = 0; i < TIMES_TO_RUN_INSTRUCTION; i++)
	{
		QueryPerformanceCounter(&start_ticks);
		__rdtsc();
		QueryPerformanceCounter(&end_ticks);

		double delta = end_ticks.QuadPart - start_ticks.QuadPart;
		
		rdtsc_time += delta;
	}

	return rdtsc_time / TIMES_TO_RUN_INSTRUCTION;
}

double fyl2xp1_timing()
{
	double fyl2xp1_time = 0;
	LARGE_INTEGER start_ticks = {};
	LARGE_INTEGER end_ticks = {};

	for (std::size_t i = 0; i < TIMES_TO_RUN_INSTRUCTION; ++i)
	{
		QueryPerformanceCounter(&start_ticks);
		run_fyl2xp1();
		QueryPerformanceCounter(&end_ticks);

		double delta = end_ticks.QuadPart - start_ticks.QuadPart;

		fyl2xp1_time += delta;
	}

	return fyl2xp1_time / TIMES_TO_RUN_INSTRUCTION;
}

}