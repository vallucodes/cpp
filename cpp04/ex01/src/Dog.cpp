#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog defaut constructor called" << std::endl;
	setType("Dog");
	brain = new Brain();
}

Dog::Dog( const Dog& other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog&	Dog::operator=( const Dog& other ) {
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
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
