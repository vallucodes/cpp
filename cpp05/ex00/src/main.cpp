#include "Bureaucrat.hpp"

void	test1() {
	std::cout << "test1: High level bureacrat Ursula von der Leyen" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 5);
		std::cout << bur << std::endl;
		for (int i = 0; i < 8; i++)
		{
			bur.incrementGrade();
			std::cout << bur << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl << std::endl;
	}
}

void	test2() {
	std::cout << "test2: Low level bureacrat Sanna Marin" << std::endl << std::endl;

	try {
		Bureaucrat bur("Sanna Marin", 145);
		std::cout << bur << std::endl;
		for (int i = 0; i < 8; i++)
		{
			bur.decrementGrade();
			std::cout << bur << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl << std::endl;
	}
}

void	test3() {
	std::cout << "test3: Copying bureacrats" << std::endl << std::endl;

	try {
		Bureaucrat b1("Iratxe Garcia Perez", 58);
		Bureaucrat b2(b1);
		Bureaucrat b3;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		b3 = b2;
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl << std::endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	return 0;
}
