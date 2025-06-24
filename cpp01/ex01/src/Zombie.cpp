#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << _name << " left us forever" << std::endl;
}

void	Zombie::setName( std::string name ) {
	_name = name;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
