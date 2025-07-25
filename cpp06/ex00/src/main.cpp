#include <iostream>
#include "ScalarConverter.hpp"

void	tests();

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./ScalarConverter <convertible>" << std::endl;
		std::string	input;
		std::cout << "Do you want to launch automated tests? (y/n) ";
		std::cin >> input;
		if (input == "y") {
			std::cout << std::endl;
			tests();
			return (0);
		}
		return (1);
		return 1;
	}
	else
		ScalarConverter::convert(std::string(av[1]));

	return 0;
}
