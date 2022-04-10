/*************************************************************************
 > File Name: main.c
 > Author: Winter
 > Created Time: 2022年04月10日 星期日 17时48分09秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include "String.h"

int main(int argc, char* argv[])
{
	std::cout << "copy constructor test" << std::endl;
	String x("xxx");
	String cop = x; // copy constructor

	std::cout << "copy assignment test" << std::endl;
	x = cop; // copy assignment

	std::cout << "move assignment test" << std::endl;
	String a("jackaaa");
	String b("fluybbb");
	a = std::move(b); // move assignment
	std::cout << b << std::endl;
	std::cout << b.length() << std::endl;
	std::cout << a << std::endl;

	std::cout << "move construct test" << std::endl;
	String c = String("hello"); // move constructor
	std::cout << c << std::endl;

	std::cout << "operator<< test" << std::endl;
	std::cout << c << std::endl;

	std::cout << "operator>> test" << std::endl;
	String in;
	std::cin >> in;
	std::cout << in << std::endl;

	std::cout << "operator == test" << std::endl;
	String aa = "hello";
	String bb = "hello";
	String cc = "hello1";
	std::cout << (aa == bb) << "," << (aa == cc) << std::endl;

	std::cout << "operator + test" << std::endl;
	String ad ("aaa");
	String bd("lucy");
	String cd = ad + bd;
	std::cout << cd << std::endl;

	std::cout << "c_str() test" << std::endl;
	std::cout << cd.c_str() << std::endl;

	std::cout << "legth() test" << std::endl;
	std::cout << cd.length() << std::endl;
	return 0;
}