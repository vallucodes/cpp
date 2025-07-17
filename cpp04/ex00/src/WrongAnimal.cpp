#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type = "DefaultAnimalName";
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	type = other.type;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other ) {
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::setType( std::string type ) {
	this->type = type;
}

std::string	WrongAnimal::getType( void ) const {
	return this->type;
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal makes sound: Wroooom!" << std::endl;
}
