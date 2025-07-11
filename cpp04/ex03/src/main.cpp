#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: AMateria basic test" << std::endl << std::endl;

	const AMateria *ice = new Ice();
	const AMateria *cure = new Cure();
	Ice ice2;
	Ice copy(ice2);
	Ice ice3;

	ice3 = copy;

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

	Cure cure3;
	Cure copy(cure3);
	Cure cure4;

	cure4 = copy;

	std::cout << std::endl;
	std::cout << "Type of cure2 object just created: " << cure2->getType() << std::endl;

	delete cure;
	delete cure2;
}

void	test4() {
	std::cout << std::endl << "Test 4: Character tests" << std::endl << std::endl;

	Character bob;
	std::cout << "\033[1;31mChar created: " << bob.getName() << "\033[0m" << std::endl;

	Character* bob2 = new Character("bob2");
	std::cout << "\033[1;31mChar created: " << bob2->getName() << "\033[0m" << std::endl;

	Character bob3("bob3");
	std::cout << "\033[1;31mChar created: " << bob3.getName() << "\033[0m" << std::endl;

	bob = bob3;
	std::cout << "\033[1;31mBob got new name: " << bob.getName() << "\033[0m" << std::endl;

	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	bob.equip(ice);
	bob2->equip(cure);

	bob.use(0, *bob2);
	bob2->use(0, bob);

	bob.use(1, *bob2); //empty slot test
	bob2->use(1, bob); //empty slot test

	bob.unequip(0); //this leads now to leak because item is just dropped to floor and not deleted when destructor comes
	bob.unequip(1); //empty slot test

	AMateria *ice1 = new Ice();
	AMateria *cure1 = new Cure();
	AMateria *ice2 = new Ice();
	AMateria *cure2 = new Cure();
	AMateria *cure3 = new Cure();

	bob.equip(ice1);
	bob.equip(cure1);
	bob.equip(ice2);
	bob.equip(cure2);
	bob.equip(cure3);

	bob2->unequip(0);
	bob2->unequip(1); //empty slot test
	delete bob2;
}

int	main() {
	// test1();
	// test2();
	// test3();
	test4();
	// test5();
	// test6();
	return (0);
}
