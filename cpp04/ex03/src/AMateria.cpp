#include "AMateria.hpp"

AMateria::AMateria( void ) : type("default") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : type(type) {
	std::cout << "AMateria custom constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& other ) : type(other.type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& other ) {
	std::cout << "AMateria copy assignment called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use( ICharacter& target ) {
	std::cout << type << " used on " << target.getName() << std::endl;
}
