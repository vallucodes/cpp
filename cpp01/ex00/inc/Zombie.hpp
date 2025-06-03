#pragma once
#include <iostream>

class Zombie {

	private:
		std::string	_Name;

	public:
		Zombie(std::string name);
		~Zombie();
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
