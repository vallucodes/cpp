#pragma once
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {

	public:
		Ice( void );
		Ice( const Ice& other );
		Ice& operator=( const Ice& other );
		~Ice( void );
		AMateria* clone( void ) const;
};
