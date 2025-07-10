#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: AMateria basic test" << std::endl << std::endl;

	const AMateria *ice = new Ice();
	const AMateria *cure = new Cure();

	std::cout << std::endl;
	std::cout << "Type of Ice object just created: " << ice->getType() << std::endl;
	std::cout << "Type of Cure object just created: " << cure->getType() << std::endl;

	delete ice;
	delete cure;
}

void	test2() {
	std::cout << std::endl << "Test 2: ice basic test" << std::endl << std::endl;

	AMateria *ice = new Ice();
	AMateria *ice2 = new Ice();

	*ice2 = *ice;
	std::cout << std::endl;
	std::cout << "Type of ice2 object just created: " << ice2->getType() << std::endl;

	delete ice;
	delete ice2;
}

void	test3() {
	std::cout << std::endl << "Test 3: cure basic test" << std::endl << std::endl;

	AMateria *cure = new Cure();
	AMateria *cure2 = new Cure();

	*cure2 = *cure;
	std::cout << std::endl;
	std::cout << "Type of cure2 object just created: " << cure2->getType() << std::endl;

	delete cure;
	delete cure2;
}

int	main() {
	test1();
	test2();
	test3();
	// test4();
	// test5();
	// test6();
	return (0);
}
