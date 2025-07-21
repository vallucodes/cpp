#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("Presidential pardon form", 25, 5) {
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) :
	AForm("Presidential pardon form", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other) {
	target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	AForm::operator=(other);
	if (this != &other)
		target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
	if (getSigned() == false)
		throw FormNotSigned();
	if (executor.getGrade() > getGradeRequiredToExec())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by " << executor.getName() << "." << std::endl;
}
