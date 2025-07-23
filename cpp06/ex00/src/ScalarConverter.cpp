#include "ScalarConverter.hpp"

static void	printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	validateInput( const std::string& nb ) {
	if (nb.length() == 1)
		return true;
	bool dotIsPresent = false;
	bool fIsPresent = false;
	for (int i = 0; i < nb.length(); i++)
	{
		if (nb[i] == 'f' && nb[i + 1] == '\0' && fIsPresent == false)
			return true;
		if (nb[i] == '.' && dotIsPresent == false)
		{
			dotIsPresent = true;
			continue ;
		}
		if (std::isdigit(nb[i]) || (dotIsPresent == false))

		else
			return false;
	}
}

static void	handleChar( const std::string& nb ) {

	std::cout << "char: ";
	try {
		if (nb.length() == 1 && !std::isdigit(nb[0]))
		{
			char c = nb[0];
			std::cout << "'" << c << "'" << std::endl;
			return ;
		}
		int res = std::stoi(nb);
		if (res < -128 || res > 127)
			throw std::out_of_range("dummy");
		if (res == 127 || res < 32)
			throw ScalarConverter::nonDisplayableException();
		std::cout << "'" << static_cast<char>(res) << "'" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

static void	handleInt( const std::string& nb ) {

	std::cout << "int: ";
	try {
		int res = std::stoi(nb);
		std::cout << res << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::convert( const std::string& nb ) {

	if (!validateInput(nb))
		printImpossible();
	handleChar(nb);
	handleInt(nb);
	// handleFloat(nb);
	// handleDouble(nb);
}

const char*	ScalarConverter::nonDisplayableException::what() const noexcept {
	return ("Non displayable");
}

// char:			32					-126
// int:				-2147483648			2147483647
// float			-3.40282e+38		3.40282e+38
// double			-1.79769e+308		1.79769e+308

// all possible valid input:

// normal numbers:		1 32 64 -34 +42
// printable chars:	a k P, tab
// float:				543f 0.4f 0.45f
// special:			-inff +inff -inf +inf nanf nan


// -----------------------------------------
// [ Test: Invalid string representation ]
// -----------------------------------------
// [ Input: '❤' ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: 'abc' ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '\t' ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '' '' ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '😀' ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Test: string representation for Char ]
// -----------------------------------------
// [ Input: 'a' ]
// char: 'a'
// int: 97
// float: 97.0f
// double: 97.0
// -----------------------------------------
// [ Input: '	' ]
// char: '	'
// int: 9
// float: 9.0f
// double: 9.0
// -----------------------------------------
// [ Input: ' ' ]
// char: ' '
// int: 32
// float: 32.0f
// double: 32.0
// -----------------------------------------
// [ Input: 'Z' ]
// char: 'Z'
// int: 90
// float: 90.0f
// double: 90.0
// -----------------------------------------
// [ Input: '*' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '+' ]
// char: '+'
// int: 43
// float: 43.0f
// double: 43.0
// -----------------------------------------
// [ Input: '/' ]
// char: '/'
// int: 47
// float: 47.0f
// double: 47.0
// -----------------------------------------
// [ Input: '@' ]
// char: '@'
// int: 64
// float: 64.0f
// double: 64.0
// -----------------------------------------
// [ Input: '?' ]
// char: '?'
// int: 63
// float: 63.0f
// double: 63.0
// -----------------------------------------
// [ Input: '0': Invalid conversion type ]
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// -----------------------------------------
// [ Input: '9': Invalid conversion type ]
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// -----------------------------------------
// [ Input: '木': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: 'ã': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '€': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Test: string representation for Integer ]
// -----------------------------------------
// [ Input: '1' ]
// char: Non displayable
// int: 1
// float: 1.0f
// double: 1.0
// -----------------------------------------
// [ Input: '-2' ]
// char: Non displayable
// int: -2
// float: -2.0f
// double: -2.0
// -----------------------------------------
// [ Input: '2222' ]
// char: impossible
// int: 2222
// float: 2222.0f
// double: 2222.0
// -----------------------------------------
// [ Input: '+42' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '-42' ]
// char: Non displayable
// int: -42
// float: -42.0f
// double: -42.0
// -----------------------------------------
// [ Input: 'INT_MAX' ]
// INT_MAX = 2147483647
// char: impossible
// int: 2147483647
// float: 2.14748e+09.0f
// double: 2147483647.0
// -----------------------------------------
// [ Input: 'INT_MIN' ]
// INT_MIN = -2147483648
// char: impossible
// int: -2147483648
// float: -2.14748e+09.0f
// double: -2147483648.0
// -----------------------------------------
// [ Input: Overflow value ]
// Overflow value for int = 2147483648
// char: impossible
// int: impossible
// float: 2147483648.0f
// double: 2147483648.0
// -----------------------------------------
// [ Input: Underflow value ]
// Underflow value for int = -2147483649
// char: impossible
// int: impossible
// float: -2147483648.0f
// double: -2147483649.0
// -----------------------------------------
// [ Input: '++1234': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '-1234abc': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// [ Input: '+1234a': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Test: string representation for Float ]
// -----------------------------------------
// [ Input: '0.0f' ]
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// -----------------------------------------
// [ Input: '-0.5f' ]
// char: Non displayable
// int: 0
// float: -0.5f
// double: -0.5
// -----------------------------------------
// [ Input: '42.0f' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '1234.5' ]
// char: impossible
// int: 1234
// float: 1234.5f
// double: 1234.5
// -----------------------------------------
// [ Input: '1234.5f' ]
// char: impossible
// int: 1234
// float: 1234.5f
// double: 1234.5
// -----------------------------------------
// [ Input: '-42.42' ]
// char: Non displayable
// int: -42
// float: -42.4f
// double: -42.4
// -----------------------------------------
// [ Input: '-inff' ]
// char: impossible
// int: impossible
// float: -inff
// double: -inf
// -----------------------------------------
// [ Input: '+inff' ]
// char: impossible
// int: impossible
// float: +inff
// double: +inf
// -----------------------------------------
// [ Input: 'nanf' ]
// char: impossible
// int: impossible
// float: nanf
// double: nan
// -----------------------------------------
// [ Input: 'FLT_MAX' ]
// FLT_MAX = 340282346638528859811704183484516925440.0
// char: impossible
// int: impossible
// float: 340282346638528859811704183484516925440.0f
// double: 340282346638528859811704183484516925440.0
// -----------------------------------------
// [ Input: 'FLT_MIN' ]
// FLT_MIN = -340282346638528859811704183484516925440.0
// char: impossible
// int: impossible
// float: -340282346638528859811704183484516925440.0f
// double: -340282346638528859811704183484516925440.0
// -----------------------------------------
// [ Input: Overflow value ]
// Overflow value for float = 1340282346638528859811704183484516925440.0
// char: impossible
// int: impossible
// float: impossible
// double: 1340282346638528799520870555087695511552.0
// -----------------------------------------
// [ Input: Underflow value ]
// Underflow value for float = -1.0e-50f
// char: Non displayable
// int: 0
// float: -0.0f
// double: -0.0
// -----------------------------------------
// [ Input: '1.2.3f': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '100.0ff': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '42.f' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '.42f' ]
// char: Non displayable
// int: 0
// float: 0.4f
// double: 0.4
// -----------------------------------------
// [ Test: string representation for Double ]
// -----------------------------------------
// [ Input: '0.0' ]
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// -----------------------------------------
// [ Input: '9.9' ]
// char: Non displayable
// int: 9
// float: 9.9f
// double: 9.9
// -----------------------------------------
// [ Input: '-0.5' ]
// char: Non displayable
// int: 0
// float: -0.5f
// double: -0.5
// -----------------------------------------
// [ Input: '+42.0' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '1234.5' ]
// char: impossible
// int: 1234
// float: 1234.5f
// double: 1234.5
// -----------------------------------------
// [ Input: '42424242.42' ]
// char: impossible
// int: 42424242
// float: 42424244.0f
// double: 42424242.4
// -----------------------------------------
// [ Input: '-42.42' ]
// char: Non displayable
// int: -42
// float: -42.4f
// double: -42.4
// -----------------------------------------
// [ Input: '-inf' ]
// char: impossible
// int: impossible
// float: -inff
// double: -inf
// -----------------------------------------
// [ Input: '+inf' ]
// char: impossible
// int: impossible
// float: +inff
// double: +inf
// -----------------------------------------
// [ Input: 'nanf' ]
// char: impossible
// int: impossible
// float: nanf
// double: nan
// -----------------------------------------
// [ Input: 'DBL_MAX' ]
// DBL_MAX = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
// char: impossible
// int: impossible
// float: inff
// double: 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
// -----------------------------------------
// [ Input: 'DBL_MIN' ]
// DBL_MIN = -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
// char: impossible
// int: impossible
// float: -inff
// double: -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
// -----------------------------------------
// [ Input: Overflow value ]
// Overflow value for double = inf
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: Underflow value ]
// Underflow value for double = 1e-320
// char impossible
// int impossible
// float impossible
// double impossible
// -----------------------------------------
// [ Input: '1.2.3': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '1..23': Invalid conversion type ]
// char: impossible
// int: impossible
// float: impossible
// double: impossible
// -----------------------------------------
// [ Input: '42.' ]
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// -----------------------------------------
// [ Input: '.42' ]
// char: Non displayable
// int: 0
// float: 0.4f
// double: 0.4
// -----------------------------------------
