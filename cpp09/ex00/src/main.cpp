#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}

	std::ifstream infile(av[1]);
	if (!infile.is_open()) {
		std::cout << "Error: could not open the file for reading" << std::endl;
		return 1;
	}

	setup_database();
	std::ifstream data("data/data.csv");
	if (!data.is_open()) {
		std::cout << "Error: could not open database for reading" << std::endl;
		return 1;
	}

	std::string line;
	while (1)
	{
		if(!std::getline(infile, line))
			break ;
		parse_line(line);
	}
}
