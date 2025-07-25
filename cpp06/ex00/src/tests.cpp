#include <iostream>
#include <iomanip>
#include <limits>
#include "ScalarConverter.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

void	testChar() {
	std::cout << RED << "Test inputs type of char" << RESET << std::endl << std::endl;

	std::cout << GREEN << "Test input: 'a' " << RESET << std::endl;
	ScalarConverter::convert("a");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'Z' " << RESET << std::endl;
	ScalarConverter::convert("Z");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '5' " << RESET << std::endl;
	ScalarConverter::convert("5");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '*' " << RESET << std::endl;
	ScalarConverter::convert("*");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '@' " << RESET << std::endl;
	ScalarConverter::convert("@");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '+' " << RESET << std::endl;
	ScalarConverter::convert("+");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '/' " << RESET << std::endl;
	ScalarConverter::convert("/");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '?' " << RESET << std::endl;
	ScalarConverter::convert("?");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Space character
	std::cout << GREEN << "Test input: ' ' (space)" << RESET << std::endl;
	ScalarConverter::convert(" ");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Tab character
	std::cout << GREEN << "Test input: '	' (tab)" << RESET << std::endl;
	ScalarConverter::convert("	");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl << std::endl;
}

void	testInt() {
	std::cout << RED << "Test inputs type of int" << RESET << std::endl << std::endl;

	// Positive integers
	std::cout << GREEN << "Test input: '42' " << RESET << std::endl;
	ScalarConverter::convert("42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '0' " << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '1234' " << RESET << std::endl;
	ScalarConverter::convert("1234");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Negative integers
	std::cout << GREEN << "Test input: '-42' " << RESET << std::endl;
	ScalarConverter::convert("-42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-1' " << RESET << std::endl;
	ScalarConverter::convert("-1");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Positive sign
	std::cout << GREEN << "Test input: '+42' " << RESET << std::endl;
	ScalarConverter::convert("+42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Boundary values
	int intMax = std::numeric_limits<int>::max();
	std::string intMax_str = std::to_string(intMax);
	std::cout << GREEN << "Test input: '" << intMax << "', INT_MAX" << RESET << std::endl;
	ScalarConverter::convert(intMax_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	int intMin = std::numeric_limits<int>::min();
	std::string intMin_str = std::to_string(intMin);
	std::cout << GREEN << "Test input: '" << intMin << "', INT_MIN" << RESET << std::endl;
	ScalarConverter::convert(intMin_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Overflow values
	std::cout << GREEN << "Test input: '2147483648' (INT_MAX + 1)" << RESET << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-2147483649' (INT_MIN - 1)" << RESET << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl << std::endl;
}

void	testFloat() {
	std::cout << RED << "Test inputs type of float" << RESET << std::endl << std::endl;

	// Basic floats
	std::cout << GREEN << "Test input: '42.0f' " << RESET << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '0.0f' " << RESET << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '3.14f' " << RESET << std::endl;
	ScalarConverter::convert("3.14f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Negative floats
	std::cout << GREEN << "Test input: '-42.5f' " << RESET << std::endl;
	ScalarConverter::convert("-42.5f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-0.5f' " << RESET << std::endl;
	ScalarConverter::convert("-0.5f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Positive sign
	std::cout << GREEN << "Test input: '+123.45f' " << RESET << std::endl;
	ScalarConverter::convert("+123.45f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Edge cases
	std::cout << GREEN << "Test input: '42.f' (no decimal digits)" << RESET << std::endl;
	ScalarConverter::convert("42.f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '.42f' (no integer part)" << RESET << std::endl;
	ScalarConverter::convert(".42f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Boundary values
	float floatMax = std::numeric_limits<float>::max();
	std::string floatMax_str = std::to_string(floatMax);
	std::cout << GREEN << "Test input: '" << floatMax_str << "', FLOAT_MAX" << RESET << std::endl;
	ScalarConverter::convert(floatMax_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	float floatMin = std::numeric_limits<float>::lowest();
	std::string floatMin_str = std::to_string(floatMin);
	std::cout << GREEN << "Test input: '" << floatMin_str << "', FLOAT_MIN" << RESET << std::endl;
	ScalarConverter::convert(floatMin_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '3402823466385288598117041834845169254400.0f'" << "', FLOAT_MAX * 10" << RESET << std::endl;
	ScalarConverter::convert("3402823466385288598117041834845169254400.0f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-3402823466385288598117041834845169254400.0f'" << "', FLOAT_MIN * 10" << RESET << std::endl;
	ScalarConverter::convert("-3402823466385288598117041834845169254400.0f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Special float values
	std::cout << GREEN << "Test input: '-inff' " << RESET << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '+inff' " << RESET << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'nanf' " << RESET << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl << std::endl;
}

void	testDouble() {
	std::cout << RED << "Test inputs type of double" << RESET << std::endl << std::endl;

	// Basic doubles
	std::cout << GREEN << "Test input: '42.0' " << RESET << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '0.0' " << RESET << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '3.14159' " << RESET << std::endl;
	ScalarConverter::convert("3.14159");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Negative doubles
	std::cout << GREEN << "Test input: '-42.5' " << RESET << std::endl;
	ScalarConverter::convert("-42.5");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-0.5' " << RESET << std::endl;
	ScalarConverter::convert("-0.5");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Positive sign
	std::cout << GREEN << "Test input: '+123.456789' " << RESET << std::endl;
	ScalarConverter::convert("+123.456789");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Edge cases
	std::cout << GREEN << "Test input: '42.' (no decimal digits)" << RESET << std::endl;
	ScalarConverter::convert("42.");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '.42' (no integer part)" << RESET << std::endl;
	ScalarConverter::convert(".42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	double doubleMax = std::numeric_limits<double>::max();
	std::string doubleMax_str = std::to_string(doubleMax);
	std::cout << GREEN << "Test input: '" << doubleMax_str << "', DOUBLE_MAX" << RESET << std::endl;
	ScalarConverter::convert(doubleMax_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	double doubleMin = std::numeric_limits<double>::lowest();
	std::string doubleMin_str = std::to_string(doubleMin);
	std::cout << GREEN << "Test input: '" << doubleMin_str << "', DOUBLE_MIN (lowest)" << RESET << std::endl;
	ScalarConverter::convert(doubleMin_str);
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;


	std::cout << GREEN << "Test input: '1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0'" << "', DOUBLE_MAX * 10" << RESET << std::endl;
	ScalarConverter::convert("1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0'" << "', DOUBLE_MIN * 10" << RESET << std::endl;
	ScalarConverter::convert("-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583680.0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Special double values
	std::cout << GREEN << "Test input: '-inf' " << RESET << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '+inf' " << RESET << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'nan' " << RESET << std::endl;
	ScalarConverter::convert("nan");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl << std::endl;
}

void	testInvalid() {
	std::cout << RED << "Test invalid inputs" << RESET << std::endl << std::endl;

	// Multiple characters (not single char)
	std::cout << GREEN << "Test input: 'abc' " << RESET << std::endl;
	ScalarConverter::convert("abc");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'hello' " << RESET << std::endl;
	ScalarConverter::convert("hello");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Invalid number formats
	std::cout << GREEN << "Test input: '++42' " << RESET << std::endl;
	ScalarConverter::convert("++42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '--42' " << RESET << std::endl;
	ScalarConverter::convert("--42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '42abc' " << RESET << std::endl;
	ScalarConverter::convert("42abc");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'abc42' " << RESET << std::endl;
	ScalarConverter::convert("abc42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Invalid float formats
	std::cout << GREEN << "Test input: '42.0.0f' " << RESET << std::endl;
	ScalarConverter::convert("42.0.0f");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '42ff' " << RESET << std::endl;
	ScalarConverter::convert("42ff");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: 'f42' " << RESET << std::endl;
	ScalarConverter::convert("f42");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Invalid double formats
	std::cout << GREEN << "Test input: '42.0.0' " << RESET << std::endl;
	ScalarConverter::convert("42.0.0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '42..0' " << RESET << std::endl;
	ScalarConverter::convert("42..0");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Empty or whitespace
	std::cout << GREEN << "Test input: '' (empty string)" << RESET << std::endl;
	ScalarConverter::convert("");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '   ' (spaces)" << RESET << std::endl;
	ScalarConverter::convert("   ");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	// Unicode/special characters
	std::cout << GREEN << "Test input: '❤' (unicode)" << RESET << std::endl;
	ScalarConverter::convert("❤");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl;

	std::cout << GREEN << "Test input: '€' (euro symbol)" << RESET << std::endl;
	ScalarConverter::convert("€");
	std::cout << CYAN << std::string(50, '-') << RESET << std::endl << std::endl;
}

void	tests() {
	testChar();
	testInt();
	testFloat();
	testDouble();
	testInvalid();
}
