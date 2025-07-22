#pragma once
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

	private:
		std::string	target;

	public:
		PresidentialPardonForm( void ) = delete;
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
		~PresidentialPardonForm();

		void execute( const Bureaucrat& executor ) const override;
};
