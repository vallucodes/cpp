#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
	brain = new Brain();
}

Cat::Cat( const Cat& other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	setType(other.getType());
	brain = new Brain(*other.getBrain());
}

Cat&	Cat::operator=( const Cat& other ) {
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other)
	{
		setType(other.getType());
		*brain = *(other.getBrain());
	}
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "Cat making sound" << std::endl;
}

Brain*	Cat::getBrain( void ) const {
	return brain;
}
