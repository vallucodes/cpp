#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = SCAV_AD;
	std::cout << "ScavTrap defaut constructor called, object name: " << _name << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_hitPoints = SCAV_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = SCAV_AD;
	std::cout << "ScavTrap constructor called, object name: " << _name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {
	std::cout << "ScavTrap copy assignment called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called, object name: " << _name << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " damage!" <<std::endl;
	}
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " doesn't have enought energy points to attack!" <<std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead, could not attack!" <<std::endl;
}

void	ScavTrap::guardGate() const {
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is already dead" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " doesn't have enought energy points!" <<std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now in a Gate keeper mode" <<std::endl;
}
