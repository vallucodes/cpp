#include "../inc/MutantStack.hpp"
#include <list>
#include <stack>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

void	test1() {
	std::cout << std::endl;
	std::cout << RED << "test1: given by subject: list" << RESET << std::endl << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "stack back: " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
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
	std::cout << RED << "test2: given by subject: stack" << RESET << std::endl << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "stack back: " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
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

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test3: given by subject: MutantStack" << RESET << std::endl << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate through: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	test4() {
	std::cout << std::endl;
	std::cout << RED << "test4: given by subject: const MutantStack" << RESET << std::endl << std::endl;

	MutantStack<int> mstack1;
	mstack1.push(5);
	mstack1.push(17);
	std::cout << "stack top: " << mstack1.top() << std::endl;
	mstack1.pop();
	std::cout << "stack size: "<< mstack1.size() << std::endl;
	mstack1.push(3);
	mstack1.push(5);
	mstack1.push(737);
	mstack1.push(0);

	const MutantStack<int> mstack(mstack1);
	std::cout << "stack top: " << mstack.top() << std::endl;
	std::cout << "stack size: "<< mstack.size() << std::endl;
	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate through: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	test5() {
	std::cout << std::endl;
	std::cout << RED << "test5: other member functions" << RESET << std::endl << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "is stack empty?: " << mstack.empty() << std::endl;
	std::stack<int> s(mstack);
}

void	test6() {
	std::cout << std::endl;
	std::cout << RED << "test6: MutantStack type string" << RESET << std::endl << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("abc");
	mstack.push("def");
	std::cout << "stack top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: "<< mstack.size() << std::endl;
	mstack.push("ghi");
	mstack.push("jkl");
	mstack.push("mno");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate through: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<std::string> s(mstack);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}
