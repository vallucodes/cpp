#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon( std::string type ) {
	_Type = type;
}

Weapon::~Weapon() {}

std::string	Weapon::getType() {
	return(_Type);
}

void		Weapon::setType( std::string type ) {
	_Type = type;
}
