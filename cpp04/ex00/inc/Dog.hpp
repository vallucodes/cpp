#pragma once
#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {

	public:
		Dog( void );
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog( void );
		void	makeSound( void ) const;
};


