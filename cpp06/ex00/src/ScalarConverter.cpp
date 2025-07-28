#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <limits>
#include <cmath>

void	printChar( const std::string& nb ) {
	char c = nb[0];

	if (std::isprint(c))
		std::cout << "Char: '" << c << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: "<< static_cast<int>(c) << std::endl;

	std::cout << std::fixed << std::setprecision(1);

	std::cout << "Float: "<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double: "<< static_cast<double>(c) << std::endl;
}

void	handleChar( const std::string& nb ) {

	std::cout << "char: ";
	if (nb.length() == 1 && !std::isdigit(nb[0]))
	{
		char c = nb[0];
		std::cout << "'" << c << "'" << std::endl;
		return ;
	}
	try {
		double res = std::stod(nb);

		if (std::isnan(res))
			throw std::out_of_range("dummy");

		if (res > std::numeric_limits<char>::max() || res < std::numeric_limits<char>::min())
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

void	handleInt( const std::string& nb ) {

	std::cout << "int: ";
	try {
		double tmp = std::stod(nb);

		if (std::isnan(tmp))
			throw std::out_of_range("dummy");

		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
			throw std::out_of_range("dummy");

		int res = static_cast<int>(tmp);
		std::cout << res << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "impossible" << std::endl;
	}
}

void	handleFloat( const std::string& nb, const int precision ) {

	std::cout << "float: ";
	try {
		float res = std::stof(nb);
		std::cout << std::fixed << std::setprecision(precision) << res << "f" << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "impossible" << std::endl;
	}
}

void	handleDouble( const std::string& nb, const int precision ) {

	std::cout << "double: ";
	try {
		double res = std::stod(nb);
		std::cout << std::fixed << std::setprecision(precision) << res << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "impossible" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "impossible" << std::endl;
	}
}

void	handlePseudo( const std::string& nb ) {

	std::string	types[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};

	if (nb == "-inf" || nb == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (nb == "+inf" || nb == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (nb == "nan" || nb == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
		std::cout << "System error: unreachable" << std::endl;
}

void	printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool	checkChar( const std::string& nb ) {
	if (nb.length() == 1 && !std::isdigit(nb[0]))
		return true;
	return false;
}

bool	checkInt( const std::string& nb ) {
	size_t	i = 0;

	if (nb[i] == '+' || nb[i] == '-')
	{
		i++;
		if (i >= nb.length())
			return false;
	}
	while (nb[i] && std::isdigit(nb[i]))
		i++;
	if (nb[i] != '\0' && !std::isdigit(nb[i]))
		return false;
	try {
		std::stoi(nb);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	return true;
}

bool	checkFloat( const std::string& nb ) {
	size_t	i = 0;
	int		dotCount = 0;

	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i] && (std::isdigit(nb[i]) || nb[i] == '.'))
	{
		if (nb[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return false;
		i++;
	}
	if (i != nb.size() - 1 || nb[i] != 'f')
		return false;
	try {
		std::stof(nb);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	return true;
}

bool	checkDouble( const std::string& nb ) {
	size_t	i = 0;
	int		dotCount = 0;

	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i] && (std::isdigit(nb[i]) || nb[i] == '.'))
	{
		if (nb[i] == '.')
			dotCount++;
		if (dotCount > 1)
			return false;
		i++;
	}
	if (i < nb.size())
		return false;
	try {
		std::stod(nb);
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	return true;
}

bool	checkPseudoLiteralsFloat( const std::string& nb ) {
	return (nb == "-inff" || nb =="+inff" || nb =="nanf");
}

bool	checkPseudoLiteralsDouble( const std::string& nb ) {
	return (nb == "-inf" || nb =="+inf" || nb =="nan");
}

int	getPresicion( const std::string& nb ) {

	size_t dotPos = nb.find('.');
	if (dotPos == std::string::npos || dotPos + 1 >= nb.size() || dotPos + 2 >= nb.size())
		return 1;

	size_t i = 0;
	while (nb[dotPos + 1 + i] && nb[dotPos + 1 + i] != '.' && std::isdigit(nb[dotPos + 1 + i]))
		i++;
	return i;
}

int	detectType( const std::string& nb ) {
	if (checkChar(nb))
		return CHAR;
	if (checkInt(nb))
		return INT;
	if (checkFloat(nb))
		return FLOAT;
	if (checkDouble(nb))
		return DOUBLE;
	if (checkPseudoLiteralsFloat(nb))
		return PSEUDOFLOAT;
	if (checkPseudoLiteralsDouble(nb))
		return PSEUDODOUBLE;
	return INVALID;
}

void	ScalarConverter::convert( const std::string& nb ) {
	if(nb.empty())
	{
		printImpossible();
		return ;
	}

	int precision = getPresicion(nb);
	int type = detectType(nb);

	switch (type)
	{
		case 0:
			printChar(nb);
			break ;
		case 1:
			handleChar(nb);
			handleInt(nb);
			handleFloat(nb, precision);
			handleDouble(nb, precision);
			break ;
		case 2:
			handleChar(nb);
			handleInt(nb);
			handleFloat(nb, precision);
			handleDouble(nb, precision);
			break ;
		case 3:
			handleChar(nb);
			handleInt(nb);
			handleFloat(nb, precision);
			handleDouble(nb, precision);
			break ;
		case 4:
			handleChar(nb);
			handleInt(nb);
			handlePseudo(nb);
			break ;
		case 5:
			handleChar(nb);
			handleInt(nb);
			handlePseudo(nb);
			break ;
		case 6:
			printImpossible();
			break ;
		default:
			std::cout << "System error: unreachable" << std::endl;
	}
}

const char*	ScalarConverter::nonDisplayableException::what() const noexcept {
	return ("Non displayable");
}
