#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: grade of bureaucrat too low for form. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Maria Ohisalo", 110);
		std::cout << bur << std::endl;
		Form a("A1245", 7, 7);
		bur.signForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2: grade of bureaucrat is enough for signing form. High level bureaucrat Ursula von der Leyen\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		std::cout << bur << std::endl;
		Form a("A1246", 7, 7);
		bur.signForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: form copying\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Antonio Decaro", 3);
		Form a("A1247", 7, 7);
		std::cout << a << std::endl;
		Form b;
		std::cout << b << std::endl;
		Form c(a);
		bur.signForm(a);
		std::cout << c << std::endl;
		b = a;
		std::cout << b << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: form grade too high\033[0m" << std::endl << std::endl;

	try {
		Form a("A1248", 0, 7);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test5() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: form grade too low\033[0m" << std::endl << std::endl;

	try {
		Form a("A1248", 56, 160);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test6() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest6: grade of bureaucrat is exactly correct for signing form. High level bureaucrat Ursula von der Leyen\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		std::cout << bur << std::endl;
		Form a("A1249", 1, 1);
		bur.signForm(a);
		std::cout << a << std::endl;
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
	test6();
	return 0;
}
