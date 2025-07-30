#include "../inc/Array.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"
#define MAX_VAL 750

void	test1() {
	std::cout << std::endl;
	std::cout << RED << "test1: test out of bounds set values" << RESET << std::endl << std::endl;

	Array<int> a(2);

	try {
		a[0] = 777;
		a[1] = 999;
		a[2] = 998;
	}
	catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}

	try {
		a[-1] = 998;
	}
	catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}

	std::cout << "Array: "<< a << std::endl << "len: " << a.size() << std::endl;
}

void	test2() {
	std::cout << std::endl;
	std::cout << RED << "test2: test [] operator" << RESET << std::endl << std::endl;

	Array<int> a(5);
	a[0] = 42;
	int x = a[0];
	std::cout << x << std::endl;

	Array<char> b(5);

	b[0] = 'a';
	b[1] = 'b';
	b[2] = 'c';
	b[3] = 'd';
	b[4] = 'e';
	const Array<char> c(b);
	char y = c[4];
	std::cout << y << std::endl;
	std::cout << b[4] << std::endl;
}

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test3: string array" << RESET << std::endl << std::endl;

	try {
		Array<std::string> a(1);
		a[0] = "Hello Mars!";
		std::cout << a[0] << std::endl;

	} catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}
}

void	test4() {
	std::cout << std::endl;
	std::cout << RED << "test4: copy constructor" << RESET << std::endl << std::endl;

	try {
		Array<int> a;
		Array<int> b(a);
		std::cout << "a array length: " << a.size() << std::endl;
		std::cout << "b array length: " << b.size() << std::endl;
		std::cout << "a[0]: " << a[0] << std::endl;
		std::cout << "b[0]: " << b[0] << std::endl;

	} catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}

	try {
		Array<int> a(1);
		Array<int> b(a);
		std::cout << "a array length: " << a.size() << std::endl;
		std::cout << "b array length: " << b.size() << std::endl;
		std::cout << "a[0]: " << a[0] << std::endl;
		std::cout << "b[0]: " << b[0] << std::endl;

		a[0] = 99;
		std::cout << "a[0] after setting value for a[0]: " << a[0] << std::endl;
		std::cout << "b[0] after setting value for a[0]: " << b[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}
}

void	test5() {
	std::cout << std::endl;
	std::cout << RED << "test5: copy assignment" << RESET << std::endl << std::endl;

	try {
		Array<int> a;
		Array<int> b;
		b = a;
		std::cout << "a array length: " << a.size() << std::endl;
		std::cout << "b array length: " << b.size() << std::endl;
		std::cout << "a[0]: " << a[0] << std::endl;
		std::cout << "b[0]: " << b[0] << std::endl;

	} catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}

	try {
		Array<int> a(1);
		Array<int> b;
		b = a;
		std::cout << "a array length: " << a.size() << std::endl;
		std::cout << "b array length: " << b.size() << std::endl;
		std::cout << "a[0]: " << a[0] << std::endl;
		std::cout << "b[0]: " << b[0] << std::endl;

		a[0] = 99;
		std::cout << "a[0] after setting value for a[0]: " << a[0] << std::endl;
		std::cout << "b[0] after setting value for a[0]: " << b[0] << std::endl;
	} catch (std::exception& e) {
		std::cout << CYAN << e.what() << RESET << std::endl;
	}
}

void test6() {
	std::cout << std::endl;
	std::cout << RED << "test6: provided tests by subject" << RESET << std::endl << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	// test operator[]
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// test copy constructor
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (test[i] != numbers[i])
			std::cerr << "didn't save the same value!!" << std::endl;
		}
	}

	// test deep copy
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		std::cerr << "didn't save the same value!!" << std::endl;
	}

	// test out of bounds under
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << CYAN << e.what() << RESET << '\n';
	}

	//test out of bounds over
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << CYAN << e.what() << RESET << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
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
