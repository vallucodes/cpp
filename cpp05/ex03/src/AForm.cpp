#include "AForm.hpp"

AForm::AForm( void ) :
	_name("Default Form"),
	_signed(false),
	_gradeToSign(1),
	_gradeToExec(1)
{}

AForm::AForm( const std::string name, int gradeToSign, int gradeToExec ) :
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

AForm::AForm( const AForm& other )  :
	_name(other.getName()),
	_signed(other.getSigned()),
	_gradeToSign(other.getGradeRequiredToSign()),
	_gradeToExec(other.getGradeRequiredToExec())
{}

AForm&	AForm::operator=( const AForm& other ) {
	if (this != &other)
		_signed = other.getSigned();
	return *this;
}

AForm::~AForm() {
	std::cout << "Form " << getName() << " was shredded." << std::endl;
}

const char*	AForm::GradeTooHighException::what() const noexcept {
	return ("grade is too high.");
}

const char*	AForm::GradeTooLowException::what() const noexcept {
	return ("grade is too low.");
}

const char*	AForm::FormNotSigned::what() const noexcept {
	return ("form is not signed.");
}

const std::string&	AForm::getName() const {
	return _name;
}

bool	AForm::getSigned() const {
	return _signed;
}

int	AForm::getGradeRequiredToSign() const {
	return _gradeToSign;
}

int	AForm::getGradeRequiredToExec() const {
	return _gradeToExec;
}

void	AForm::beSigned( const Bureaucrat& b ) {
	if (b.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream&	operator<<( std::ostream& out, const AForm& f ) {
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
