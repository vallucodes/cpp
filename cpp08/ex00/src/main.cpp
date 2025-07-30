#include "../inc/easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <forward_list>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

void	test1() {
	std::cout << std::endl;
	std::cout << RED << "test1: test vector" << RESET << std::endl << std::endl;

	std::vector<int> vec = {1, 9, 3, 5, 7, 99};

	auto i = easyfind(vec, 7);
	std::cout << *i << std::endl;

	try {
		i = easyfind(vec, 2);
		std::cout << *i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	i = easyfind(vec, 99);
	std::cout << *i << std::endl;
}

void	test2() {
	std::cout << std::endl;
	std::cout << RED << "test2: test deque" << RESET << std::endl << std::endl;

	std::deque<int> deq = {1, 9, 3, 5, 7, 99};

	auto i = easyfind(deq, 7);
	std::cout << *i << std::endl;

	try {
		i = easyfind(deq, 2);
		std::cout << *i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	i = easyfind(deq, 99);
	std::cout << *i << std::endl;
}

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test3: test list" << RESET << std::endl << std::endl;

	std::list<int> list = {1, 9, 3, 5, 7, 99};

	auto i = easyfind(list, 7);
	std::cout << *i << std::endl;

	try {
		i = easyfind(list, 2);
		std::cout << *i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	i = easyfind(list, 99);
	std::cout << *i << std::endl;
}

void	test4() {
	std::cout << std::endl;
	std::cout << RED << "test4: test set" << RESET << std::endl << std::endl;

	std::set<int> set = {1, 9, 3, 5, 7, 99};

	auto i = easyfind(set, 7);
	std::cout << *i << std::endl;

	try {
		i = easyfind(set, 2);
		std::cout << *i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	i = easyfind(set, 99);
	std::cout << *i << std::endl;
}

void	test5() {
	std::cout << std::endl;
	std::cout << RED << "test5: tost const forward list" << RESET << std::endl << std::endl;

	const std::forward_list<int> list = {1, 9, 3, 5, 7, 99};

	auto i = easyfind(list, 7);
	std::cout << *i << std::endl;

	try {
		i = easyfind(list, 2);
		std::cout << *i << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	i = easyfind(list, 99);
	std::cout << *i << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
