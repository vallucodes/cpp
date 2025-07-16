#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {

	private:
		Brain *brain;

	public:
		Cat( void );
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );
		~Cat( void );

		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;
};
