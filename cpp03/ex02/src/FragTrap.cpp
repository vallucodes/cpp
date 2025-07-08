#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap defaut constructor called, object name: " << _name << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called, object name: " << _name << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& other ) {
	std::cout << "FragTrap copy assignment called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap Destructor called, object name: " << _name << std::endl;
}

void	FragTrap::attack( const std::string& target ) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "FragTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " damage!" <<std::endl;
	}
	else if (_energyPoints == 0)
		std::cout << "FragTrap " << _name << " doesn't have enought energy points to attack!" <<std::endl;
	else
		std::cout << "FragTrap " << _name << " is dead, could not attack!" <<std::endl;
}

void	FragTrap::highFivesGuys( void ) const {
	std::cout << "FragTrap " << _name << " highfived everyone" <<std::endl;
}
