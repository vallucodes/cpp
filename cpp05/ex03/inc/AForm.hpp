#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm( void ) = delete;
		AForm( const std::string name, int gradeToSign, int gradeToExec );
		AForm( const AForm& other );
		AForm& operator=( const AForm& other );
		virtual ~AForm();

		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class	AlreadySignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class	FormNotSignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExec() const;
		void				beSigned( const Bureaucrat& b );
		virtual void		execute( const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<( std::ostream& out, const AForm& f );
