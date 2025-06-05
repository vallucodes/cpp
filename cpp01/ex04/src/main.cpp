#include <iostream>
#include <fstream>

std::string	replace_content(std::string line, std::string replace, std::string replacer) {
	if (replace.empty())
		return (line);

	size_t	pos = 0;
	while (1)
	{
		pos = line.find(replace, pos);
		if (pos == std::string::npos)
			break ;
		line.erase(pos, replace.length());
		line.insert(pos, replacer);
		pos += replacer.length();
	}
	return (line);
}

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
