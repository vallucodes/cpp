#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: create ClapTrap and and FragTrap" << std::endl << std::endl;

	ClapTrap	a("Settler");
	std::cout << std::endl;

	a.attack("Praetorian");
	a.takeDamage(6);
	a.beRepaired(10);

	std::cout << std::endl;
	FragTrap	b("Teuton knight");
	std::cout << std::endl;

	b.attack("Phalanx");
	b.takeDamage(6);
	b.beRepaired(10);
	std::cout << std::endl;
}

void	test2() {
	std::cout << std::endl << "Test 2: FragTrap exhausts energypoints by repairs" << std::endl << std::endl;

	FragTrap	a("Haeduan");
	std::cout << std::endl;

	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	a.highFivesGuys();
	for (int i = 0; i < 105; i++)
		a.beRepaired(1);
	a.highFivesGuys();
	std::cout << std::endl;
}

void	test3() {
	std::cout << std::endl << "Test 3: default FragTrap interacts with world" << std::endl << std::endl;

	FragTrap	a;
	std::cout << std::endl;

	a.attack("Axeman");
	a.takeDamage(15);
	a.beRepaired(1);
	std::cout << std::endl;
}

void	test4() {
	std::cout << std::endl << "Test 4: FragTrap exhausts energypoints by attacks and then takes damage to under 0" << std::endl << std::endl;

	FragTrap	a("Phalanx");
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
	a.highFivesGuys();
	std::cout << std::endl;
}

void	test5() {
	std::cout << std::endl << "Test 5: copy constructor" << std::endl << std::endl;

	FragTrap	a("Equites Imperatoris");
	FragTrap	b(a);
	std::cout << std::endl;

	b.attack("Theutates Thunder");
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Spearman");
	a.takeDamage(25);
	std::cout << std::endl;
}

void	test6() {
	std::cout << std::endl << "Test 6: copy assignment" << std::endl << std::endl;

	FragTrap	a("Equites Imperatoris");
	FragTrap	b;
	std::cout << std::endl;

	b = a;
	std::cout << std::endl;

	b.attack("Theutates Thunder");
	b.takeDamage(25);
	b.takeDamage(25);
	b.attack("Spearman");
	a.takeDamage(25);
	std::cout << std::endl;
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
