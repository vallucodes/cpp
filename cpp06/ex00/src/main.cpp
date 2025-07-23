#include <iostream>
#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av)
{
	// if (ac != 2)
	// {
	// 	std::cerr << "Error\nUsage: ./convert <convertible>" << std::endl;
	// 	return 1;
	// }
	// else
	ScalarConverter::convert(std::string(av[1]));

	// std::string s = "89";

	// int c = 89;
	// std::cout << "'" << static_cast<char>(c) << "'" << std::endl;

	// float a = std::stof(s);
	// std::cout << a << std::endl;

	// double b = std::stod(s);
	// std::cout << b << std::endl;

	return 0;
}
