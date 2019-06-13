#include "Problem.h"
#include <iostream>


Problem::Problem()
{
}


Problem::~Problem()
{
}

void Problem::runDemo() {
	std::cout << getProblemStatement() << std::endl;
	demo();
	std::cout << std::endl;
	std::cout << getProblemSolvingStatement() << std::endl;
	std::cout << getComplexityStatement() << std::endl;
	std::cout << getLearningStatement() << std::endl;
}