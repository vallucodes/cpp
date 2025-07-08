#pragma once
#include "ClapTrap.hpp"
#include <iostream>

#define FRAG_HP 100
#define FRAG_EP 100
#define FRAG_AD 30

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& other );
		FragTrap& operator=( const FragTrap& other );
		~FragTrap( void );
		void	highFivesGuys( void ) const;
};
