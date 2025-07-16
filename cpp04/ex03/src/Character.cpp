#include "Character.hpp"

Character::Character( void ) : name("Default_name") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = nullptr;
}

Character::Character( std::string name ) : name(name) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
		inventory[i] = nullptr;
}

Character::Character( const Character& other ) {
	std::cout << "Character copy constructor called" << std::endl;
	name = other.getName();
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (other.inventory[i] != nullptr)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

Character&	Character::operator=( const Character& other ) {
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &other)
	{
		name = other.getName();
		for (int i = 0; i < INV_SIZE; i++)
		{
			if (inventory[i] != nullptr)
				delete inventory[i];
			if (other.inventory[i] != nullptr)
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character( void ) {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] != nullptr)
			std::cout << "Deleting " << inventory[i]->getType() << std::endl;
		delete inventory[i];
		inventory[i] = nullptr;
	}
}

std::string const &	Character::getName() const {
	return name;
}

void	Character::equip( AMateria* m ) {
	if (m == nullptr)
	{
		std::cout << "\033[1;31mCouldn't equip the item\033[0m" << std::endl;
		return ;
	}
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] == nullptr)
		{
			std::cout << "\033[1;31mCharacter " << this->getName() << " equipped " << m->getType() << "\033[0m" << std::endl;
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "\033[1;31mCharacter " << this->getName() << " can't carry more than 4 items\033[0m" << std::endl;
}

void	Character::unequip( int idx ) {
	if (inventory[idx] != nullptr)
		std::cout << "\033[1;31mCharacter " << this->getName() << " dropped " << inventory[idx]->getType() << "\033[0m" << std::endl;
	inventory[idx] = nullptr;
}

void	Character::use( int idx, ICharacter& target ) {
	if (idx >= 0 && idx < 4 && inventory[idx] != nullptr)
		inventory[idx]->use(target);
}
