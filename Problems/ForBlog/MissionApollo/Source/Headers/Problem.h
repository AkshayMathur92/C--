#pragma once
#include <string>
class Problem
{
public:
	Problem();
	virtual ~Problem();
	virtual std::string getProblemStatement() = 0;
	virtual std::string getComplexityStatement() = 0;
	virtual std::string getLearningStatement() = 0;
	virtual std::string getProblemSolvingStatement() = 0;
	virtual void demo() = 0;
	void runDemo();
};

