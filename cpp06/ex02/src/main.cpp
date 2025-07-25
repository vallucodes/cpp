#include <iostream>
#include <filesystem>
#include <fstream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

unsigned long	get_file_content_weight(const char* path) {
	std::ifstream file(path);
	if (!file.is_open())
		throw std::runtime_error("Failed to open file");

	unsigned long sum = 0;
	char c;
	int count = 0;
	while (file.get(c) && count < 1024) {
		sum += static_cast<unsigned char>(c);
		count++;
	}
	return sum;
}

Base*	generate( void ) {
	int res = 0;
	try {
		unsigned long nb = get_file_content_weight("/proc/stat");
		res = (nb % 3);
	} catch (...) {
		std::cout << "Coulnd't generate number" << std::endl;
		return nullptr;
	}
	
	switch (res)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void	identify( Base* p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify( Base& p ) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...){}

	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...){}

	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...){}
}

void	test1() {
	Base* p = generate();
	identify(p);
	identify(*p);
}

int main()
{
	test1();
	return 0;
}
