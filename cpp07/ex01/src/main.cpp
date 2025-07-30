#include "../inc/iter.hpp"

void	print_int(int& elem) {
	std::cout << elem << std::endl;
}

void	print_char(char& elem) {
	std::cout << elem << std::endl;
}

void	print_str(std::string& elem) {
	std::cout << elem << std::endl;
}

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: int array\033[0m" << std::endl << std::endl;

	int arr[] = {1, 2, 3, 5, 6};
	::iter(arr, 5, print_int);
}

void	test2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2: long\033[0m" << std::endl << std::endl;

	char arr[] = {'a', 'h', 't', 'p', 'q'};
	::iter(arr, 5, print_char);
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: string array\033[0m" << std::endl << std::endl;

	std::string arr[] = {"123", "456", "789", "0-="};
	::iter(arr, 4, print_str);
}

void	test4() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: nullptr\033[0m" << std::endl << std::endl;

	std::string *arr = nullptr;
	::iter(arr, 4, print_str);
}

void	test5() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest5: len = 0\033[0m" << std::endl << std::endl;

	int arr[] = {1, 2, 3, 5, 6};
	::iter(arr, 0, print_int);
}

class Awesome {
	public:
		Awesome(void):_n(42) {return;}
		int get(void) const { return this->_n;}
	private:
		int _n;
};
std::ostream &operator<< (std::ostream &o, Awesome const & rhs) {o<<rhs.get(); return o;}

template <typename T>
void print(T const & x ) {std::cout << x << std::endl; return;}

void	test6() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest5: len = 0\033[0m" << std::endl << std::endl;

	int tab[] = {0,1,2,3,4};
	Awesome tab2[5];

	iter(tab, 5UL, print<int>);
	iter(tab2, 5UL, print<Awesome>);
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
