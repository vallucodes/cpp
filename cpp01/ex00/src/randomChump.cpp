#include "Zombie.hpp"

void	randomChump( std::string name ) {
	Zombie new_random_zombie(name);
	new_random_zombie.announce();
}
