#include "TimingAnalysis.hpp"
#include "HypervisorFinderLogic.hpp"

namespace HypervisorFinderLogic
{

void run()
{
	std::cout << "[HypervisorFinder] Running cpuid timing analysis..." << std::endl;
	auto cpuid_time = TimingAnalysis::cpuid_timing();
	std::cout << "[HypervisorFinder] cpuid timing: " << cpuid_time << " ticks" << std::endl;
	
	std::cout << "[HypervisorFinder] Running rdtsc timing analysis..." << std::endl;
	auto rdtsc_time = TimingAnalysis::rdtsc_timing();
	std::cout << "[HypervisorFinder] rdtsc timing: " << rdtsc_time << " ticks" << std::endl;

	std::cout << "[HypervisorFinder] Running fyl2xp1 timing analysis..." << std::endl;
	auto fyl2xp1_time = TimingAnalysis::fyl2xp1_timing();
	std::cout << "[HypervisorFinder] fyl2xp1 timing: " << fyl2xp1_time << " ticks" << std::endl;
}

}