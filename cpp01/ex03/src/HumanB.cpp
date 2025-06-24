#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _weapon(nullptr) {
	_name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack( void ) {
	if (_weapon == nullptr)
		std::cout << _name << " attacks with their bare hands" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}
