#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void ) {

	forms[0] = "presidential pardon";
	forms[1] = "robotomy request";
	forms[2] = "shrubbery creation";
	functions[0] = &Intern::CreatePPF;
	functions[1] = &Intern::CreateRRF;
	functions[2] = &Intern::CreateSCF;
}

const char*	Intern::FormDoesNotExistException::what() const noexcept {
	return ("Intern doesn't know that form yet.");
}

AForm* Intern::CreatePPF( const std::string& target ) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::CreateRRF( const std::string& target ) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::CreateSCF( const std::string& target ) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeForm( const std::string& name, const std::string& target ) {

	for (int i = 0; i < 3; i++)
		if (name == forms[i])
		{
			std::cout << "Intern creates " << forms[i] << " form" << std::endl;
			return ((this->*functions[i])(target));
		}

	throw FormDoesNotExistException();
}
