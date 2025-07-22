#include <random>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) :
	AForm("Robotomy request form", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other) {
	target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	AForm::operator=(other);
	if (this != &other)
		target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
	if (getSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExec())
		throw GradeTooLowException();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 1);
	bool success = dist(gen) == 1;

	if (success == true)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
