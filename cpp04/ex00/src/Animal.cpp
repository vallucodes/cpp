#include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << "Animal defaut constructor called" << std::endl;
	type = "DefaultAnimalName";
}

Animal::Animal( const Animal& other ) {
	std::cout << "Animal copy constructor called" << std::endl;
	type = other.type;
}

Animal& Animal::operator=( const Animal& other ) {
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::setType( std::string type ) {
	this->type = type;
}

std::string	Animal::getType( void ) const {
	return this->type;
}

void	Animal::makeSound( void ) const {
	std::cout << "Animal makes sound" << std::endl;
}
