#include "./../inc/Zombie.hpp"
#include <iostream>

int	main() {
	std::string	zombie_horde_names = "Amy Stake";
	int			amount = 6;

	Zombie* zombie_horde = zombieHorde(amount, zombie_horde_names);
	delete[] zombie_horde;
	return (0);
}
