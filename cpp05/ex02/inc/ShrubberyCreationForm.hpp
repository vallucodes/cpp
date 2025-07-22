#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {

	private:
		std::string	target;

	public:
		ShrubberyCreationForm( void ) = delete;
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();

		class FileCreationError : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		void execute( const Bureaucrat& executor ) const override;
};
