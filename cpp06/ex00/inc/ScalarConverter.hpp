#pragma once
#include <iostream>
#include <exception>

class ScalarConverter {

	private:


	public:
		class	nonDisplayableException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		static void convert( const std::string& nb );
};
