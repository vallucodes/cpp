#include "Zombie.hpp"
#include <iostream>

int	main() {
	std::string	name1 = "Unelma Sirpa-Leena";
	std::string	name2 = "Turo";
	Zombie* zombie1;

	try {
		zombie1 = newZombie(name1);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return (1);
	}
	randomChump(name2);
	delete zombie1;
	return (0);
}
