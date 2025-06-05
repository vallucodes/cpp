#include "Harl.hpp"
#include <iostream>
#include <iomanip>

int	main(int ac, char **av) {
	if (ac != 2)
	{
		std::string	input;
		std::cout << "Incorrect amount of arguments. Do you want to launch automated tests? (y/n) ";
		std::cin >> input;
		if (input == "y") {
			std::cout << std::endl;
			tests();
		}
		return (0);
	}
	Harl	harl;
	harl.complain( std::string(av[1]) );
	return (0);
}
