#include "Form.hpp"

Form::Form( const std::string name, int gradeToSign, int gradeToExec ) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
	{
		std::cout << "Form: ";
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150)
	{
		std::cout << "Form: ";
		throw GradeTooLowException();
	}
}

Form::Form( const Form& other )  :
	_name(other.getName()),
	_signed(other.getSigned()),
	_gradeToSign(other.getGradeRequiredToSign()),
	_gradeToExec(other.getGradeRequiredToExec())
{}

Form&	Form::operator=( const Form& other ) {
	if (this != &other)
		_signed = other.getSigned();
	return *this;
}

Form::~Form() {
	std::cout << "Form " << getName() << " was shredded." << std::endl;
}

const char*	Form::GradeTooHighException::what() const noexcept {
	return ("grade is too high.");
}

const char*	Form::GradeTooLowException::what() const noexcept {
	return ("grade is too low.");
}

const char*	Form::AlreadySignedException::what() const noexcept {
	return ("form is already signed!");
}

const std::string&	Form::getName() const {
	return _name;
}

bool	Form::getSigned() const {
	return _signed;
}

int	Form::getGradeRequiredToSign() const {
	return _gradeToSign;
}

int	Form::getGradeRequiredToExec() const {
	return _gradeToExec;
}

void	Form::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	if (getSigned() == true)
		throw AlreadySignedException();
	_signed = true;
}

std::ostream&	operator<<( std::ostream& out, const Form& f ) {
	out << "\nForm name: " << f.getName() << "\nIs signed: ";
	if (f.getSigned() == true)
		out << "Yes";
	else
		out << "No";
	out << "\nMinimum grade required to sign: "
		<< f.getGradeRequiredToSign() << "\nMinimum grade required to execute: "
		<< f.getGradeRequiredToExec() << "\n";
	return out;
}
