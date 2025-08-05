#include "../inc/MutantStack.hpp"
// #include <cstdlib>
// #include <ctime>
// #include <algorithm>
#include <list>
#include <stack>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

void	test1() {
	std::cout << std::endl;
	std::cout << RED << "test1: given by subject" << RESET << std::endl << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "stack back: " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate through: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void	test2() {
	std::cout << std::endl;
	std::cout << RED << "test2: given by subject" << RESET << std::endl << std::endl;

	std::stack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack back: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	std::cout << "iterate through: " << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	std::stack<int> s(mstack);
}

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test2: given by subject" << RESET << std::endl << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.asd();
	std::cout << "stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	// std::list<int>::iterator it = mstack.begin();
	// std::list<int>::iterator ite = mstack.end();
	std::cout << "iterate through: " << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	std::stack<int> s(mstack);
}

int main() {
	test1();
	test2();
	test3();
	// test4();
	// test5();
	// test6();
	// test7();
	// test8();
	// test9();
	return 0;
}
