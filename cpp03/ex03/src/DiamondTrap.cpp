#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap( "Noname_clap_name" ) {
	_name = "Noname";
	_hitPoints = FRAG_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = FRAG_AD;
	std::cout << "DiamondTrap defaut constructor called, object name: " << _name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ) {
	_name = name;
	_hitPoints = FRAG_HP;
	_energyPoints = SCAV_EP;
	_attackDamage = FRAG_AD;
	std::cout << "DiamondTrap constructor called, object name: " << _name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap( other._name + "_clap_name" ) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other ) {
	ClapTrap::operator=(other);
	if (this != &other)
		_name = other._name;
	std::cout << "DiamondTrap copy assignment called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap Destructor called, object name: " << _name << std::endl;
}

void	DiamondTrap::whoAmI() const {
	std::cout << "My DiamondTrap name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
