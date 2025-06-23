#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon( std::string type ) {
	_Type = type;
}

Weapon::~Weapon() {}

const std::string	&Weapon::getType() const {
	return(_Type);
}

void		Weapon::setType( std::string type ) {
	_Type = type;
}
