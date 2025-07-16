#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {

	private:
		Brain *brain;

	public:
		Dog( void );
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog( void );

		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;
};
