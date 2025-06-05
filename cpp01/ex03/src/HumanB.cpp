#include "HumanB.hpp"

HumanB::HumanB(std::string name): _Weapon(nullptr) {
	_Name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack(void) {
	if (_Weapon == nullptr)
		std::cout << _Name << " attacks with their bare hands" << std::endl;
	else
		std::cout << _Name << " attacks with their " << _Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_Weapon = &weapon;
}
