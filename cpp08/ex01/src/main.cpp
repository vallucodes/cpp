#include "../inc/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

void	test0() {
	std::cout << std::endl;
	std::cout << RED << "test0: given by subject" << RESET << std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test1() {
	std::cout << std::endl;
	std::cout << RED << "test1: normal test" << RESET << std::endl << std::endl;

	int size = 6;
	Span a(size);

	try {
		a.addNumber(5);
		a.addNumber(9);
		a.addNumber(2);
		a.addNumber(4);
		a.addNumber(5);
		a.addNumber(-2);
		std::cout << "Lon span: " << a.longestSpan() << std::endl;
		std::cout << "Min span: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test2() {
	std::cout << std::endl;
	std::cout << RED << "test2: add too many elements to array" << RESET << std::endl << std::endl;

	int size = 10;
	Span a(size);

	srand(time(0));
	try {
		for (int i = 0; i < 11; i++)
			a.addNumber((rand() % 199) - 99);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test3: not enough element for span calc" << RESET << std::endl << std::endl;

	int size = 1;
	Span a(size);

	try {
		a.addNumber(5);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Min span: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Lon span: " << a.longestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << RED << "test4: copy constuctor and copy assignment" << RESET << std::endl << std::endl;

	int size = 6;
	Span a(size);

	try {
		a.addNumber(5);
		a.addNumber(9);
		a.addNumber(2);
		a.addNumber(4);
		a.addNumber(5);
		a.addNumber(-2);
		std::cout << "Lon span a: " << a.longestSpan() << std::endl;
		std::cout << "Min span a: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	Span b(a);
	try {
		std::cout << "Lon span b: " << b.longestSpan() << std::endl;
		std::cout << "Min span b: " << b.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	Span c(3);
	try {
		c.addNumber(45);
		c.addNumber(90);
		c.addNumber(123243);
		std::cout << "Lon span c: " << c.longestSpan() << std::endl;
		std::cout << "Min span c: " << c.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	c = a;
	try {
		std::cout << "Lon span c after a assigned: " << c.longestSpan() << std::endl;
		std::cout << "Min span c after a assigned: " << c.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test5() {
	std::cout << std::endl;
	std::cout << RED << "test5: 10 000 000 size" << RESET << std::endl << std::endl;

	int size = 10000000;
	Span a(size);

	srand(time(0));
	try {
		for (int i = 0; i < size; i++)
			a.addNumber((rand() %10000));
		std::cout << "Lon span: " << a.longestSpan() << std::endl;
		std::cout << "Min span: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test6() {
	std::cout << std::endl;
	std::cout << RED << "test6: 0 size" << RESET << std::endl << std::endl;

	int size = 0;

	try {
		Span a(size);
		a.addNumber(32);
		std::cout << "Lon span: " << a.longestSpan() << std::endl;
		std::cout << "Min span: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test7() {
	std::cout << std::endl;
	std::cout << RED << "test7: add elements as range of iterator" << RESET << std::endl << std::endl;

	int size = 10;
	Span a(size);

	srand(time(0));
	try {
		for (int i = 0; i < 5; i++)
			a.addNumber((rand() % 199) - 99);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Lon span before adding: " << a.longestSpan() << std::endl;
		std::cout << "Min span before adding: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::vector<int>	arr = {1, 2, 3, 4, 5};

	a.addNumber(arr.begin(), arr.end());

	try {
		std::cout << "Lon span after adding another vector: " << a.longestSpan() << std::endl;
		std::cout << "Min span after adding another vector: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test8() {
	std::cout << std::endl;
	std::cout << RED << "test8: iterator range invalid" << RESET << std::endl << std::endl;

	int size = 10;
	Span a(size);

	srand(time(0));
	try {
		for (int i = 0; i < 5; i++)
			a.addNumber((rand() % 199) - 99);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	arr = {1, 2, 3, 4, 5};

	try {
		a.addNumber(++(arr.begin()), arr.begin());
		std::cout << "Lon span after adding another vector: " << a.longestSpan() << std::endl;
		std::cout << "Min span after adding another vector: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void	test9() {
	std::cout << std::endl;
	std::cout << RED << "test9: iterator range, add too many" << RESET << std::endl << std::endl;

	int size = 6;
	Span a(size);

	srand(time(0));
	try {
		for (int i = 0; i < 5; i++)
			a.addNumber((rand() % 199) - 99);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	arr = {1, 2, 3, 4, 5};

	try {
		a.addNumber(arr.begin(), arr.end());
		std::cout << "Lon span after adding another vector: " << a.longestSpan() << std::endl;
		std::cout << "Min span after adding another vector: " << a.shortestSpan() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}


int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 0;
}
