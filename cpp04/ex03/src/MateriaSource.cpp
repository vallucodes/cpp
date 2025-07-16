#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAT_INV_SIZE; i++)
		inventory[i] = nullptr;
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAT_INV_SIZE; i++)
	{
		if (other.inventory[i] != nullptr)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {
	std::cout << "MateriaSource copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAT_INV_SIZE; i++)
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

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAT_INV_SIZE; i++)
		delete inventory[i];
}

void	MateriaSource::learnMateria( AMateria* m ) {
	for (int i = 0; i < MAT_INV_SIZE; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const& type ) {
	for (int i = 0; i < MAT_INV_SIZE; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return 0;
}
