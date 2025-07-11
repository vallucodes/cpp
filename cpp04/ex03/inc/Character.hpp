#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define INV_SIZE 4

class Character : public ICharacter {

	private:
		std::string	name;
		AMateria	*inventory[INV_SIZE];

	public:
		Character( void );
		Character( std::string name );
		Character( const Character& other );
		Character& operator=( const Character& other );
		~Character();

		std::string const & getName() const;
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
};
