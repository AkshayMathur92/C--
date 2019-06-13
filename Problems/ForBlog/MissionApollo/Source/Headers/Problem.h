#pragma once
#include <string>
#include <iostream>
using namespace std::literals::string_literals;
class Problem
{
public:
	Problem();
	virtual ~Problem();
	virtual void demo() = 0;
	virtual std::string demoName() = 0;
	void runDemo();
};

