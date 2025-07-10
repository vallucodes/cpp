#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure& other ) : AMateria(other.getType()) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=( const Cure& other ) {
	std::cout << "Cure copy assignment called" << std::endl;
	if (this != &other)
		type = other.getType();
	return *this;
}

Cure::~Cure( void ) {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone( void ) const {
	AMateria* new_materia = new Cure(*this);
	return new_materia;
}
