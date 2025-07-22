#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) :
	name("default"),
	grade(70)
{}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : name(name) {
	if (grade < 1)
	{
		std::cout << "Bureacrat: ";
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		std::cout << "Bureacrat: ";
		throw GradeTooLowException();
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	name(other.getName()),
	grade(other.getGrade())
{}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
		grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << *this << ", left the Brussels."<< std::endl;
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
