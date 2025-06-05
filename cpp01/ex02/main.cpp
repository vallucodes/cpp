#include <iostream>
#include <iomanip>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << std::left << std::setw(44) << "The memory adress of the string variable: " << &str << std::endl;
	std::cout << std::left << std::setw(44) << "The memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << std::left << std::setw(44) << "The memory adress held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << std::left << std::setw(44) << "The value of the string variable: " << str << std::endl;
	std::cout << std::left << std::setw(44) << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << std::left << std::setw(44) << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
