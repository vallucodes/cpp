#include <iostream>
#include "../inc/Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: Basic test" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
}

void	test2() {
	std::cout << std::endl << "Test 2: WrongAnimal and WrongCat" << std::endl << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete i;
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
	std::cout << std::endl << "Test 4: Dog pointer" << std::endl << std::endl;

	const Dog* puppy = new Dog();
	const Animal* animal_puppy = new Dog();

	std::cout << std::endl;
	std::cout << "My type is " << puppy->getType() << " " << std::endl;
	std::cout << "My type is " << animal_puppy->getType() << " " << std::endl;
	puppy->makeSound();
	animal_puppy->makeSound();
	std::cout << std::endl;

	delete puppy;
	delete animal_puppy;
}

void	test5() {
	std::cout << std::endl << "Test 5: Multiple Animal pointers" << std::endl << std::endl;

	const int amount = 8;
	Animal* animals[amount];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat(*static_cast<const Cat*>(animals[0]));
	animals[3] = new Dog(*static_cast<const Dog*>(animals[1]));
	animals[4] = new Cat();
	animals[5] = new Dog();
	animals[6] = new Animal();
	animals[7] = new Animal(*animals[6]);

	*animals[4] = *animals[0];
	*animals[5] = *animals[1];

	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << i << ": My type is " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < amount; i++)
		delete animals[i];
}

void	test6() {
	std::cout << std::endl << "Test 6: operator=" << std::endl << std::endl;
	{
		Cat *cat1 = new Cat();
		Cat *cat2 = new Cat();

		std::cout << std::endl;
		*cat1 = *cat2;
		std::cout << std::endl;

		delete cat1;
		delete cat2;
	}

	{
		Dog *Dog1 = new Dog();
		Dog *Dog2 = new Dog();

		std::cout << std::endl;
		*Dog1 = *Dog2;
		std::cout << std::endl;

		delete Dog1;
		delete Dog2;
	}
}

// test with virtual and without virtual in animal class: look at destructors
void	test7() {
	std::cout << std::endl << "Test 7: virtual destructor" << std::endl << std::endl;

	Animal* animal = new Cat();

	delete animal;
}

int	main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return (0);
}
