#include <iostream>
#include "ScalarConverter.hpp"

void	scalarConverter( const std::string& nb) {

}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error\nUsage: ./convert <convertible>" << std::endl;
		return 1;
	}
	else
		ScalarConverter::convert(std::string(av[1]));
	return 0;
}
