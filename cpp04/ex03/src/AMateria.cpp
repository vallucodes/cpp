#include "AMateria.hpp"

AMateria::AMateria( void ) : type("default") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& other ) : type(other.getType()) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& other ) {
	std::cout << "AMateria copy assignment called" << std::endl;
	(void)other;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use( ICharacter& target ) {
	std::cout << "\033[1;31m" << type << " used on " << target.getName() << "\033[0m" << std::endl;
}
