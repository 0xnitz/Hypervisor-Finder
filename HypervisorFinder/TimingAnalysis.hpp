#pragma once

#include <iostream>

namespace TimingAnalysis
{

extern "C" void __fastcall run_fyl2xp1(void);

struct cpuid_arguments
{
	uint32_t m_eax;

	uint32_t m_ebx;

	uint32_t m_ecx;

	uint32_t m_edx;
};

static constexpr size_t TIMES_TO_RUN_INSTRUCTION = 10000;

double cpuid_timing();

double rdtsc_timing();

double fyl2xp1_timing();

}