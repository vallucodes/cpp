#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: Basic test" << std::endl << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
}

void	test2() {
	int	amount = 10;

	Animal* animals[amount];

	for (int i = 0; i < amount; i++)
	{
		if (i < amount / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < amount / 2; i++)
		delete animals[i];
	

}

void	test3() {
	std::cout << std::endl << "Test 3: Cat pointer" << std::endl << std::endl;

	const Cat* kitty = new Cat();
	const Animal* animal_kitty = new Cat();

	std::cout << std::endl;
	std::cout << "My type is " << kitty->getType() << " " << std::endl;
	std::cout << "My type is " << animal_kitty->getType() << " " << std::endl;
	kitty->makeSound();
	animal_kitty->makeSound();
	std::cout << std::endl;

	delete kitty;
	delete animal_kitty;
}

void	test4() {
	std::cout << std::endl << "Test 4: Multiple Animal pointers" << std::endl << std::endl;

	const Animal* animals[6];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat(*static_cast<const Cat*>(animals[0]));
	animals[3] = new Dog(*static_cast<const Dog*>(animals[1]));
	animals[4] = new Cat();
	animals[5] = new Dog();

	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << i << ": My type is " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
}

void	test5() {
	std::cout << std::endl << "Test 5: operator=" << std::endl << std::endl;

	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();

	std::cout << std::endl;
	*cat1 = *cat2;
	std::cout << std::endl;

	delete cat1;
	delete cat2;
}

int	main() {
	test1();
	// test2();
	// test3();
	// test4();
	// test5();
	return (0);
}
