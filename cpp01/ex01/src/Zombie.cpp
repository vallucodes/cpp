#include "./../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
	_Name = name;
}

Zombie::Zombie() {}

Zombie::~Zombie(void) {
	std::cout << _Name << " left us forever" << std::endl;
}

void	Zombie::setName( std::string name ) {
	_Name = name;
}

void	Zombie::announce(void) {
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
