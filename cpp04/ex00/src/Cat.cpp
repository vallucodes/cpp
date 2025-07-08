#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat defaut constructor called" << std::endl;
	setType("Cat");
}

Cat::Cat( const Cat& other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	setType(other.getType());
}

Cat& Cat::operator=( const Cat& other ) {
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cat making sound" << std::endl;
}
