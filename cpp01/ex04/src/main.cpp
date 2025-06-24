#include "replace.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Wrong amount of arguments. Usage: ./filehell infile replace replacer" << std::endl;
		return (1);
	}

	std::ifstream infile(av[1]);
	if (!infile.is_open()) {
		std::cerr << "Could not open the file for reading." << std::endl;
		return (1);
	}

	std::string	line;
	std::string	newline;
	std::string	outfile_name = std::string(av[1]) + ".replace";

	std::ofstream outfile(outfile_name);
	if (!outfile.is_open()) {
		std::cerr << "Could not open the file for writing." << std::endl;
		return (1);
	}

	while (std::getline(infile, line)) {
		newline = replace_content(line, std::string(av[2]), std::string(av[3]));
		outfile << newline << std::endl;
	}
	return (0);
}
