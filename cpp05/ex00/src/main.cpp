#include "Bureaucrat.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: increment grade. High level bureaucrat Ursula von der Leyen\033[0m" << std::endl << std::endl;

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
		std::cout << e.what() << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2: decrement grade. Low level bureaucrat Sanna Marin\033[0m" << std::endl << std::endl;

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
		std::cout << e.what() << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: initialize too high grade. High level bureaucrat Martin Adams\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Martin Adams", 0);
		std::cout << bur << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: initialize too low grade. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Maria Ohisalo", 9999);
		std::cout << bur << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


void	test5() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest5: copying bureaucrats\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat b1("Iratxe Garcia Perez", 58);
		Bureaucrat b2(b1);
		Bureaucrat b3;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		b3 = b2;
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
