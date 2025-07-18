#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form( void );
		Form( const std::string name, int gradeToSign, int gradeToExec );
		Form( const Form& other );
		Form& operator=( const Form& other );
		~Form();

		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExec() const;
		void				beSigned( const Bureaucrat& b );
};

std::ostream&	operator<<( std::ostream& out, const Form& f );
