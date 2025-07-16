#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	test1() {
	std::cout << std::endl << "Test 1: Basic test" << std::endl << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
}

void	test2() {
	std::cout << std::endl << "Test 2: Multiple test" << std::endl << std::endl;

	const int	amount = 10;

	Animal* animals[amount];

	for (int i = 0; i < amount; i++)
	{
		std::cout << std::endl;
		if (i < amount / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < amount; i++)
	{
		std::cout << std::endl;
		delete animals[i];
	}
}

void	test3() {
	std::cout << std::endl << "Test 3: Test deepcopy cat, copy constructor" << std::endl << std::endl;

	Cat* kitty = new Cat();

	std::cout << std::endl;
	kitty->getBrain()->setIdea(0, "Food!");
	std::cout << "kittys brains first idea: " << kitty->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	Cat* cat = new Cat(*kitty);
	std::cout << std::endl;

	std::cout << "cat brains first idea: " << cat->getBrain()->getIdea(0) << std::endl;

	kitty->getBrain()->setIdea(0, "I'm chasing laser!");
	cat->getBrain()->setIdea(0, "I just want some peace! 𓃠");
	cat->getBrain()->setIdea(1, "I want to set world on fire ₍^. .^₎⟆");

	std::cout << "kittys brains first idea after some time: " << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << "kittys brains next idea: " << kitty->getBrain()->getIdea(1) << std::endl;
	std::cout << "cat brains first idea after some time: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat brains second idea: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	delete kitty;
	delete cat;
}

void	test4() {
	std::cout << std::endl << "Test 4: Test deepcopy cat, copy assignment constructor" << std::endl << std::endl;

	Cat* kitty = new Cat();
	Cat* cat = new Cat();

	std::cout << std::endl;
	kitty->getBrain()->setIdea(0, "Sleepy!");

	*cat = *kitty;
	std::cout << std::endl;
	std::cout << "kittys brains first idea: " << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat brains first idea: " << cat->getBrain()->getIdea(0) << std::endl;

	kitty->getBrain()->setIdea(0, "I'm chasing laser!");
	cat->getBrain()->setIdea(0, "I just want some peace! 🐈‍");

	std::cout << "kittys brains first idea after some time: " << kitty->getBrain()->getIdea(0) << std::endl;
	std::cout << "cat brains first idea after some time: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "kittys brains next idea: " << kitty->getBrain()->getIdea(1) << std::endl;
	std::cout << "cat brains next idea: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	delete kitty;
	delete cat;
}

void	test5() {
	std::cout << std::endl << "Test 5: Test deepcopy dog, copy constructor" << std::endl << std::endl;

	Dog* puppy = new Dog();

	std::cout << std::endl;
	puppy->getBrain()->setIdea(0, "Food!");
	std::cout << "puppys brains first idea: " << puppy->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	Dog* dog = new Dog(*puppy);
	std::cout << std::endl;

	std::cout << "dog brains first idea: " << dog->getBrain()->getIdea(0) << std::endl;

	puppy->getBrain()->setIdea(0, "I'm chasing other dogs!");
	dog->getBrain()->setIdea(0, "I just want some peace...");

	std::cout << "puppys brains first idea after some time: " << puppy->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog brains first idea after some time: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	delete puppy;
	delete dog;
}

void	test6() {
	std::cout << std::endl << "Test 6: Test deepcopy Dog, copy assignment constructor" << std::endl << std::endl;

	Dog* puppy = new Dog();
	Dog* dog = new Dog();

	std::cout << std::endl;
	puppy->getBrain()->setIdea(0, "Sleepy!");

	*dog = *puppy;
	std::cout << std::endl;
	std::cout << "puppys brains first idea: " << puppy->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog brains first idea: " << dog->getBrain()->getIdea(0) << std::endl;

	puppy->getBrain()->setIdea(0, "I'm chasing other dogs!");
	dog->getBrain()->setIdea(0, "I just want some peace...");

	std::cout << "puppys brains first idea after some time: " << puppy->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog brains first idea after some time: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "puppys brains next idea: " << puppy->getBrain()->getIdea(1) << std::endl;
	std::cout << "dog brains next idea: " << dog->getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	delete puppy;
	delete dog;
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
