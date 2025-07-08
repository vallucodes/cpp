#pragma once
#include "ClapTrap.hpp"
#include <iostream>

#define SCAV_HP 100
#define SCAV_EP 50
#define SCAV_AD 20

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& other );
		ScavTrap& operator=( const ScavTrap& other );
		~ScavTrap( void );
		void	attack( const std::string& target );
		void	guardGate( void ) const;
};
