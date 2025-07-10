#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define INV_SIZE 4

class Character {

	private:
		std::string	name;
		AMateria	*inventory[INV_SIZE];

	public:
		~Character() {}
		std::string const & getName() const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
};
