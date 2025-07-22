#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern {

	private:
		std::string	forms[3];
		AForm*		(Intern::*functions[3])(const std::string& target);

	public:
		Intern( void );
		Intern( const Intern& other ) = delete;
		Intern& operator=( const Intern& other ) = delete;
		~Intern() = default;

		class FormDoesNotExistException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		AForm* CreatePPF( const std::string& target );
		AForm* CreateRRF( const std::string& target );
		AForm* CreateSCF( const std::string& target );

		AForm*	makeForm( const std::string& name, const std::string& target );
};
