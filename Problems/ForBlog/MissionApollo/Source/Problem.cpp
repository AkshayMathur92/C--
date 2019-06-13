#include "Problem.h"


Problem::Problem()
{
}


Problem::~Problem()
{
}

void Problem::runDemo() {
	std::cout << demoName() << std::endl;
	demo();
	std::cout << std::endl << std::endl;
}