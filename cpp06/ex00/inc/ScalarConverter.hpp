#pragma once
#include <iostream>
#include <exception>

enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOFLOAT,
	PSEUDODOUBLE,
	INVALID
};

class ScalarConverter {

	public:
		ScalarConverter( void ) = delete;
		ScalarConverter( const ScalarConverter &other ) = delete;
		~ScalarConverter( void ) = delete;
		ScalarConverter &operator=( const ScalarConverter &other ) = delete;

		class	nonDisplayableException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		static void convert( const std::string& nb );
};
