//// Problem1-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include "pch.h"
//#include <iostream>
//#include <math.h>
//#include <array>
//#include <algorithm>
//#include <functional>
//
//#define Sec 1000000.00
//#define Min Sec*60
//#define Hour Min*60
//#define Day Hour*24
//#define Month Day*31
//#define Year Day*365
//#define Century  Year*100
//
//long double solution(std::function<long double(long double)> func, const long double time) {
//	return (time / func(2)) * 2;
//}
//
//int main()
//{
//	std::function<long double (long double)> flog = [](const long double a) -> long double { return log2l(a); };
//	std::function<long double(long double)> fsqrt = [](const long double a) -> long double { return sqrtl(a); };
//	std::function<long double(long double)> fidentity = [](const long double a) -> long double { return a; };
//	std::function<long double(long double)> fnlog = [](const long double a) -> long double { return (a * logl(a)); };
//	std::function<long double(long double)> fsqr = [](const long double a) -> long double { return (a * a); };
//	std::function<long double(long double)> fcube = [](const long double a) -> long double { return (a * a * a); };
//	std::function<long double(long double)> fpow = [](const long double a) -> long double { return powl(2,a); };
//	std::array<std::function<long double(long double)>, 7> functions = { flog, fsqrt, fidentity , fnlog,fsqr, fcube, fpow };
//	std::array<const long double, 7> times = { Sec, Min , Hour , Day, Month, Year, Century };
//	for (std::function<long double(long double)> func : functions){
//		for (const long double time : times) {
//			std::cout << solution(func, time) << " ";
//		}
//		std::cout << std::endl ;
//	}
//	return 0;
//}
//
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
