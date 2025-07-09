#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: create ScavTrap and DiamondTrap" << std::endl << std::endl;

	ClapTrap	a("Teuton knight");

	std::cout << std::endl;
	a.attack("Phalanx");
	std::cout << std::endl;

	DiamondTrap	b("Imperian");

	std::cout << std::endl;
	b.attack("Phalanx");
	b.takeDamage(6);
	b.beRepaired(10);
	b.whoAmI();
	std::cout << std::endl;
}

void	test2() {
	std::cout << std::endl << "Test 2: DiamondTrap exhausts energypoints by repairs" << std::endl << std::endl;

	DiamondTrap	a("Haeduan");

	std::cout << std::endl;
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.highFivesGuys();
	a.guardGate();
	for (int i = 0; i < 55; i++)
		a.beRepaired(1);
	a.whoAmI();
	std::cout << std::endl;
}

void	test3() {
	std::cout << std::endl << "Test 3: default DiamondTrap interacts with world" << std::endl << std::endl;

	DiamondTrap	a;

	std::cout << std::endl;
	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.highFivesGuys();
	a.whoAmI();
	std::cout << std::endl;
}

void	test4() {
	std::cout << std::endl << "Test 4: DiamondTrap exhausts energypoints by attacks and then takes damage to under 0" << std::endl << std::endl;

	DiamondTrap	a("Phalanx");

	std::cout << std::endl;
	a.attack("Equites Imperatoris");
	a.takeDamage(15);
	a.beRepaired(1);
	for (int i = 0; i < 55; i++)
		a.attack("Spearman");
	a.beRepaired(1);
	for (int i = 0; i < 7; i++)
		a.takeDamage(25);
	a.beRepaired(1);
	std::cout << std::endl;
}

void	test5() {
	std::cout << std::endl << "Test 5: copy constructor" << std::endl << std::endl;

	DiamondTrap	a("Equites Imperatoris");
	DiamondTrap	b(a);

	std::cout << std::endl;
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
	std::cout << std::endl;
}

void	test6() {
	std::cout << std::endl << "Test 6: copy assignment" << std::endl << std::endl;

	DiamondTrap	a("Druidrider");
	DiamondTrap	b;

	std::cout << std::endl;
	b = a;
	b.attack("Equites Caesaris");
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Praetorian");
	a.takeDamage(25);
	a.whoAmI();
	b.whoAmI();
	std::cout << std::endl;
}

void	test7() {
	std::cout << std::endl << "Test 7: upcasting. Access all of the parent objects" << std::endl << std::endl;

	DiamondTrap	a("Equites legati");
	ScavTrap&	b = a;
	FragTrap&	c = a;
	ClapTrap&	d = a;

	std::cout << std::endl;
	a.attack("Chieftain");
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();
	b.attack("Pathfinder");
	// b.whoAmI();
	b.guardGate();
	// b.highFivesGuys();
	c.attack("Scout");
	// c.whoAmI();
	// c.guardGate();
	c.highFivesGuys();
	d.attack("Settler");
	// d.whoAmI();
	// d.guardGate();
	// d.highFivesGuys();
	std::cout << std::endl;
}

void	test8() {
	std::cout << std::endl << "Test 8: no polymorphism" << std::endl << std::endl;

	ScavTrap	scav("Warelephant");
	ClapTrap*	clap = &scav;

	std::cout << std::endl;
	clap->attack("Phalanx");
	std::cout << std::endl;
}

int	main() {
	test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	// test7();
	// test8();
	return (0);
}
