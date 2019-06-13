#pragma once
#include <string>
class Problem
{
public:
	Problem();
	virtual ~Problem();
	virtual void demo() = 0;
	void runDemo();
};

