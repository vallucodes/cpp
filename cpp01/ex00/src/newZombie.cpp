#include "Zombie.hpp"

Zombie*	newZombie( std:: string name) {
	Zombie* new_zombie;

	new_zombie = new Zombie(name);
	new_zombie->announce();
	return (new_zombie);
}
