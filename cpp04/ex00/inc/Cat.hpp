#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {

	public:
		Cat( void );
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );
		~Cat( void );

		void	makeSound( void ) const;
};
