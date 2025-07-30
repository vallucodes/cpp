#pragma once
#include <iostream>
#include <exception>
#include <string>

class Form;

class Bureaucrat {

	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		const std::string&	getName( void ) const;
		int					getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm( Form& f );
};

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& b );
