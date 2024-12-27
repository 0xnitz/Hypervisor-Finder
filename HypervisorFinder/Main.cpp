#include "HypervisorFinderLogic.hpp"

#include <iostream>

int main()
{
	try
	{
		std::cout << "[HypervisorFinder] Starting..." << std::endl;

		HypervisorFinderLogic::run();

		std::cout << "[HypervisorFinder] Finished!"<< std::endl;
	}
	catch (...)
	{
		std::cout << "[HypervisorFinder] An error occurred!" << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}