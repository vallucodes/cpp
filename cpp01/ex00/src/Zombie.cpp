#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_Name = name;
}

Zombie::~Zombie() {
	std::cout << _Name << " left us forever" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



