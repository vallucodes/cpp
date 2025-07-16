#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog defaut constructor called" << std::endl;
	setType("Dog");
}

Dog::Dog( const Dog& other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	setType(other.getType());
}

Dog& Dog::operator=( const Dog& other ) {
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dog making sound" << std::endl;
}
