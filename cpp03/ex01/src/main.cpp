#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: create ClapTrap and and ScavTrap" << std::endl << std::endl;
	ClapTrap	a("Settler");
	a.attack("Praetorian");
	a.takeDamage(6);
	a.beRepaired(10);

	ScavTrap	b("Teuton knight");
	b.attack("Phalanx");
	b.takeDamage(6);
	b.beRepaired(10);
}

void	test2() {
	std::cout << std::endl << "Test 2: ScavTrap exhausts energypoints by repairs" << std::endl << std::endl;

	ScavTrap	a("Haeduan");
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.guardGate();
	for (int i = 0; i < 55; i++)
		a.beRepaired(1);
}

void	test3() {
	std::cout << std::endl << "Test 3: default ScavTrap interacts with world" << std::endl << std::endl;

	ScavTrap	a;
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.guardGate();
}

void	test4() {
	std::cout << std::endl << "Test 4: ScavTrap exhausts energypoints by attacks and then takes damage to under 0" << std::endl << std::endl;

	ScavTrap	a("Phalanx");
	a.attack("Equites Imperatoris");
	a.takeDamage(15);
	a.beRepaired(1);
	for (int i = 0; i < 55; i++)
		a.attack("Spearman");
	a.beRepaired(1);
	for (int i = 0; i < 7; i++)
		a.takeDamage(25);
	a.beRepaired(1);
}

void	test5() {
	std::cout << std::endl << "Test 5: copy constructor" << std::endl << std::endl;

	ScavTrap	a("Equites Imperatoris");
	ScavTrap	b(a);
	b.attack("Theutates Thunder");
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Spearman");
	a.takeDamage(25);
}

void	test6() {
	std::cout << std::endl << "Test 6: copy assignment" << std::endl << std::endl;

	ScavTrap	a("Equites Imperatoris");
	ScavTrap	b;

	b = a;
	b.attack("Theutates Thunder");
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Spearman");
	a.takeDamage(25);
}

int	main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return (0);
}
