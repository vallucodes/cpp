#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: create DiamondTrap" << std::endl << std::endl;

	DiamondTrap	b("Teuton knight");
	b.attack("Phalanx");
	b.takeDamage(6);
	b.beRepaired(10);
	b.whoAmI();
}

void	test2() {
	std::cout << std::endl << "Test 2: DiamondTrap exhausts energypoints by repairs" << std::endl << std::endl;

	DiamondTrap	a("Haeduan");
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.highFivesGuys();
	a.guardGate();
	for (int i = 0; i < 55; i++)
		a.beRepaired(1);
	a.whoAmI();
}

void	test3() {
	std::cout << std::endl << "Test 3: default DiamondTrap interacts with world" << std::endl << std::endl;

	DiamondTrap	a;
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.highFivesGuys();
	a.whoAmI();
}

void	test4() {
	std::cout << std::endl << "Test 4: DiamondTrap exhausts energypoints by attacks and then takes damage to under 0" << std::endl << std::endl;

	DiamondTrap	a("Phalanx");
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

	DiamondTrap	a("Equites Imperatoris");
	DiamondTrap	b(a);
	a.attack("Theutates Thunder");
	b.attack("Theutates Thunder");
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Spearman");
	a.takeDamage(25);
	a.whoAmI();
	b.whoAmI();
}

void	test6() {
	std::cout << std::endl << "Test 6: copy assignment" << std::endl << std::endl;

	DiamondTrap	a("Druidrider");
	DiamondTrap	b;

	b = a;
	b.attack("Equites Caesaris");
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Praetorian");
	a.takeDamage(25);
	a.whoAmI();
	b.whoAmI();
}

int	main() {
	test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	return (0);
}
