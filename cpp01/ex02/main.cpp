#include <iostream>
#include <iomanip>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << std::left << std::setw(32) << "Memory adress of a string: " << &str << std::endl;
	std::cout << std::left << std::setw(32) << "Memory adress of a stringPTR: " << &stringPTR << std::endl;
	std::cout << std::left << std::setw(32) << "Memory adress of a stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << std::left << std::setw(32) << "Value of a string: " << str << std::endl;
	std::cout << std::left << std::setw(32) << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << std::left << std::setw(32) << "Value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
