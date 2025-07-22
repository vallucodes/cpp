#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: Create all forms with intern, high enough level bureacrat\033[0m" << std::endl << std::endl;

	try {
		Bureaucrat bur("Ursula von der Leyen", 1);
		Intern intern;
		AForm *a, *b, *c;

		std::cout << bur << std::endl;

		a = intern.makeForm("presidential pardon", "Paul Le Roux");
		std::cout << *a << std::endl;
		bur.signForm(*a);
		bur.executeForm(*a);
		std::cout << *a << std::endl;

		b = intern.makeForm("robotomy request", "Wall-e");
		std::cout << *b << std::endl;
		bur.signForm(*b);
		bur.executeForm(*b);
		std::cout << *b << std::endl;

		c = intern.makeForm("shrubbery creation", "Pekka Pouta");
		std::cout << *c << std::endl;
		bur.signForm(*c);
		bur.executeForm(*c);
		std::cout << *c << std::endl;

		delete a;
		delete b;
		delete c;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2: Create invalid form with intern, high enough level bureacrat\033[0m" << std::endl << std::endl;

	try {
		Intern intern;
		AForm *a;
		a = intern.makeForm("invalid form", "Paul Le Roux");
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	test1();
	test2();
	return 0;
}
