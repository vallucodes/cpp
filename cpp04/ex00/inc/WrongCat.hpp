#pragma once
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {

	public:
		WrongCat( void );
		WrongCat( const WrongCat& other );
		WrongCat& operator=( const WrongCat& other );
		~WrongCat( void );

		void	makeSound( void ) const;
};
