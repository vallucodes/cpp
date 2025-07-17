#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_name("Noname"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
}

ClapTrap::ClapTrap( const ClapTrap& other ) {
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
	std::cout << "Copy assignment called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target ) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " damage!" <<std::endl;
	}
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " doesn't have enought energy points to attack!" <<std::endl;
	else
		std::cout << "ClapTrap " << _name << " is dead, could not attack!" <<std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is getting attacked, takes " << amount << " damage" << std::endl;
		std::cout << "New health: " << _hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " doesn't have enought energy points to repair!" <<std::endl;
	else if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else
	{
		_energyPoints -= 1;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is getting repaired by " << amount << " points of health" <<std::endl;
		std::cout << "New health: " << _hitPoints << std::endl;
	}
}
