#pragma once
#include <iostream>

class Zombie {

	private:
		std::string	_Name;

	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	announce( void );
		void	setName( const std::string name );
};

Zombie*	zombieHorde( int N, std::string name );
