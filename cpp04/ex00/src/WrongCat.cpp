#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	std::cout << "WrongCat default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat( const WrongCat& other ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	setType(other.getType());
}

WrongCat& WrongCat::operator=( const WrongCat& other ) {
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &other)
		setType(other.getType());
	return *this;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const {
	std::cout << "WrongCat making sound: kwaak! kwaak!" << std::endl;
}
