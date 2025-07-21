#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: grade of bureaucrat is enough for signing and executing form. High level bureaucrat Ursula von der Leyen\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		std::cout << bur << std::endl;

		PresidentialPardonForm a("Pekka");
		bur.signForm(a);
		bur.executeForm(a);
		std::cout << a << std::endl;

		RobotomyRequestForm b("Jari");
		bur.signForm(b);
		bur.executeForm(b);
		std::cout << b << std::endl;

		ShrubberyCreationForm c("trees");
		bur.signForm(c);
		bur.executeForm(c);
		std::cout << c << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2_0() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2.0: grade of bureaucrat too low for executing form but high enough to sign: Presidential. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Maria Ohisalo", 15);
		std::cout << bur << std::endl;
		PresidentialPardonForm a("Jukka");
		bur.signForm(a);
		bur.executeForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2_1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2.1: grade of bureaucrat too low for executing form but high enough to sign: Robotomy. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Maria Ohisalo", 51);
		std::cout << bur << std::endl;
		RobotomyRequestForm a("Jukka");
		bur.signForm(a);
		bur.executeForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2_2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2.2: grade of bureaucrat too low for executing form but high enough to sign: Shrubbery. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Maria Ohisalo", 140);
		std::cout << bur << std::endl;
		ShrubberyCreationForm a("Jukka");
		bur.signForm(a);
		bur.executeForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2_3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2.3: 2 different bureacrats signing and executing: Presidential. Low level bureaucrat Maria Ohisalo\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur1("Ursula von der Leyen", 1);
		Bureaucrat bur2("Maria Ohisalo", 20);
		std::cout << bur1 << std::endl;
		std::cout << bur2 << std::endl;
		PresidentialPardonForm a("Jukka");
		bur2.signForm(a);
		bur2.executeForm(a);
		bur1.executeForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: grade of bureaucrat too low for executing and signing. Low level bureaucrat Sofia Virta\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Sofia Virta", 147);
		std::cout << bur << std::endl;

		PresidentialPardonForm a("Jukka");
		bur.signForm(a);
		bur.executeForm(a);
		std::cout << a << std::endl;

		RobotomyRequestForm b("Jari");
		bur.signForm(b);
		bur.executeForm(b);
		std::cout << b << std::endl;

		ShrubberyCreationForm c("Lari");
		bur.signForm(c);
		bur.executeForm(c);
		std::cout << c << std::endl;

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: trying to execute form that is not signed. High level bureaucrat Ursula von der Leyen\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		std::cout << bur << std::endl;

		PresidentialPardonForm a("Pekka");
		bur.executeForm(a);
		std::cout << a << std::endl;

		RobotomyRequestForm b("Jari");
		bur.executeForm(b);
		std::cout << b << std::endl;

		ShrubberyCreationForm c("Lari");
		bur.executeForm(c);
		std::cout << c << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test5() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest5: Test file creation error: chmod -w .\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		std::cout << bur << std::endl;

		ShrubberyCreationForm b("trees");
		bur.signForm(b);
		bur.executeForm(b);
		std::cout << b << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test6() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest6: abstract class: uncomment to test compilation\033[0m" << std::endl << std::endl;

	// AForm a;
}

void	test7() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest7: form copying: PresidentialPardonForm\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Antonio Decaro", 3);
		PresidentialPardonForm a("some_target");
		std::cout << "a: " << a << std::endl;
		PresidentialPardonForm b;
		std::cout << "b: " << b << std::endl;
		PresidentialPardonForm c(a);
		std::cout << "c: " << c << std::endl;
		bur.signForm(a);
		std::cout << "c: " << c << std::endl;
		b = a;
		std::cout << "b: " << b << std::endl;
		PresidentialPardonForm d(a);
		std::cout << "d: " << d << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test8() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest8: form copying: RobotomyRequestForm\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Antonio Decaro", 3);
		RobotomyRequestForm a("some_target");
		std::cout << "a: " << a << std::endl;
		RobotomyRequestForm b;
		std::cout << "b: " << b << std::endl;
		RobotomyRequestForm c(a);
		std::cout << "c: " << c << std::endl;
		bur.signForm(a);
		std::cout << "c: " << c << std::endl;
		b = a;
		std::cout << "b: " << b << std::endl;
		RobotomyRequestForm d(a);
		std::cout << "d: " << d << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test9() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest9: form copying: ShrubberyCreationForm\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Antonio Decaro", 3);
		ShrubberyCreationForm a("some_target");
		std::cout << "a: " << a << std::endl;
		ShrubberyCreationForm b;
		std::cout << "b: " << b << std::endl;
		ShrubberyCreationForm c(a);
		std::cout << "c: " << c << std::endl;
		bur.signForm(a);
		std::cout << "c: " << c << std::endl;
		b = a;
		std::cout << "b: " << b << std::endl;
		ShrubberyCreationForm d(a);
		std::cout << "d: " << d << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	test1();
	test2_0();
	test2_1();
	test2_2();
	test2_3();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 0;
}
