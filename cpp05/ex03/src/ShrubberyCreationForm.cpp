#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) :
	AForm("Shrubbery creation form", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm(other) {
	target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	AForm::operator=(other);
	if (this != &other)
		target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char*	ShrubberyCreationForm::FileCreationError::what() const noexcept {
	return ("\033[38;5;220mSystem error: Could not open the file for writing.\033[0m");
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
	if (getSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExec())
		throw GradeTooLowException();

	try {
		std::ofstream outfile(target + "_shrubbery");
		if (!outfile.is_open()) {
			throw FileCreationError();
	}
			outfile
			<< "     🌲\n"
			<< "     /\\\n"
			<< "    /**\\\n"
			<< "   /****\\\n"
			<< "  /******\\\n"
			<< " /********\\\n"
			<< "    ||||\n"
			<< "............\n"
			<< std::endl;
			outfile.close();
			std::cout << "Shrubbery created in " << target + "_shrubbery" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
