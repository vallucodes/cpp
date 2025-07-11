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
	std::cout << "FragTrap destructor called, object name: " << _name << std::endl;
}

void	FragTrap::highFivesGuys( void ) const {
	std::cout << "FragTrap " << _name << " highfived everyone" <<std::endl;
}
