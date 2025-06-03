#include "Zombie.hpp"
#include <iostream>

int	main() {
	std::string	z1 = "Turo";
	std::string	z2 = "Jukka";

	Zombie* zombie1 = newZombie(z1);
	if (zombie1 == nullptr)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return (1);
	}
	randomChump(z2);
	delete zombie1;
	return (0);
}
