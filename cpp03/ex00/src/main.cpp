#include <iostream>
#include "ClapTrap.hpp"

int	main() {
	std::cout << std::endl;
	std::cout << "Round 1" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap	a("Clubswinger");
		a.attack("Scout");
		a.takeDamage(6);
		a.beRepaired(89);
	}
	std::cout << std::endl;
	std::cout << "Round 2" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap	a("Catapult");
		ClapTrap	b(a);
		b.attack("Embassy");
		b.takeDamage(6);
		b.beRepaired(2);
		b.takeDamage(6);
		b.takeDamage(6);
		b.attack("Stable");
	}
	std::cout << std::endl;
	std::cout << "Round 3" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap	a;
		a.attack("Ram");
		a.takeDamage(6);
		a.beRepaired(89);
	}
	std::cout << std::endl;
	std::cout << "Round 4" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap a("Legionaire");
		ClapTrap b("Imperian");

		a.attack("Druidier");
		b.takeDamage(3);
		b.takeDamage(3);
		b.takeDamage(3);
		b.takeDamage(3);
		b.beRepaired(2);
		b.beRepaired(2);

		ClapTrap c = b;
		c.attack("Trebuchet");

		ClapTrap d;
		d = a;
		d.beRepaired(5);
	}
	return (0);
}
