#include "../inc/Zombie.hpp"
#include <iostream>

void	test1() {
	std::cout << "Testing valid case\n";
	std::cout << std::string(35, '-') << std::endl;
	std::string	zombie_horde_names = "Amy Stake";
	int			amount = 6;
	Zombie*		zombie_horde;

	try {
		zombie_horde = zombieHorde(amount, zombie_horde_names);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return ;
	}
	delete[] zombie_horde;
	std::cout << std::string(35, '-') << std::endl;
}

void	test2() {
	std::cout << "Testing 0 amount\n";
	std::cout << std::string(35, '-') << std::endl;
	std::string	zombie_horde_names = "Amy Stake";
	int			amount = 0;
	Zombie*		zombie_horde;

	try {
		zombie_horde = zombieHorde(amount, zombie_horde_names);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return ;
	}
	delete[] zombie_horde;
	std::cout << std::string(35, '-') << std::endl;
}

void	test3() {
	std::cout << "Testing -1 amount \n";
	std::cout << std::string(35, '-') << std::endl;
	std::string	zombie_horde_names = "Amy Stake";
	int			amount = -1;
	Zombie*		zombie_horde;

	try {
		zombie_horde = zombieHorde(amount, zombie_horde_names);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return ;
	}
	delete[] zombie_horde;
	std::cout << std::string(35, '-') << std::endl;
}

void	test4() {
	std::cout << "Testing empty name\n";
	std::cout << std::string(35, '-') << std::endl;
	std::string	zombie_horde_names = "";
	int			amount = 2;
	Zombie*		zombie_horde;

	try {
		zombie_horde = zombieHorde(amount, zombie_horde_names);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return ;
	}
	delete[] zombie_horde;
	std::cout << std::string(35, '-') << std::endl;
}

void	test5() {
	std::cout << "Testing memory allocation fail\n";
	std::cout << std::string(35, '-') << std::endl;
	std::string			zombie_horde_names = "";
	unsigned long long	amount = 100000000000;
	Zombie*				zombie_horde;

	try {
		zombie_horde = zombieHorde(amount, zombie_horde_names);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return ;
	}
	delete[] zombie_horde;
	std::cout << std::string(35, '-') << std::endl;
}

int	main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return (0);
}
