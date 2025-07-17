#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

}

Bureaucrat::Bureaucrat( const std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat&  ) {

}

Bureaucrat::~Bureaucrat() {

}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("grade too low!");
}

const std::string&	Bureaucrat::getName( void ) const {
	return name;
}

int	Bureaucrat::getGrade( void ) const {
	return grade;
}

void	Bureaucrat::incrementGrade( void ) {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade( void ) {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& b ) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
