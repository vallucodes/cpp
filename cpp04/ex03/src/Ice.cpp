#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice& other ) : AMateria(other.getType()) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice&	Ice::operator=( const Ice& other ) {
	std::cout << "Ice copy assignment called" << std::endl;
	if (this != &other)
		type = other.getType();
	return *this;
}

Ice::~Ice( void ) {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone( void ) const {
	AMateria* new_materia = new Ice(*this);
	return new_materia;
}
