#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
	brain = new Brain();
}

Dog::Dog( const Dog& other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	setType(other.getType());
	brain = new Brain(*other.getBrain());
}

Dog&	Dog::operator=( const Dog& other ) {
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
	{
		setType(other.getType());
		*brain = *(other.getBrain());
	}
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound( void ) const {
	std::cout << "Dog making sound" << std::endl;
}

Brain*	Dog::getBrain( void ) const {
	return brain;
}
