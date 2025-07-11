#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		~FragTrap( void );
		void	highFivesGuys( void ) const;
};
