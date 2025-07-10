#include "Character.hpp"

Character::Character( void ) : name("Default_name") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = nullptr;
}

Character::Character( const Character& other ) {
	std::cout << "Character copy constructor called" << std::endl;
	name = other.getName();
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = other.inventory[i];
}

Character&	Character::operator=( const Character& other ) {
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other)
	{
		name = other.getName();
		for (int i = 0; i < INV_SIZE; i++)
			inventory[i] = other.inventory[i];
	}
	return *this;
}

Character::~Character( void ) {
	std::cout << "Character destructor called" << std::endl;
}


std::string const &	Character::getName() const {
	return name;
}

void	Character::equip( AMateria* m ) {
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] == nullptr)
			inventory[i] = m;
	}
}

void	Character::unequip( int idx ) {
	inventory[idx] = nullptr;
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
		inventory[idx]->use(target);
}
