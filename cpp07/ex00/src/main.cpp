#include "whatever.hpp"

void	test1() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest1: int: swap, min, max. Normal case\033[0m" << std::endl << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	test2() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest2: long\033[0m" << std::endl << std::endl;

	long a = 10, b = 5;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: numbers are equal\033[0m" << std::endl << std::endl;

	long a = 66, b = 66;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

class Awesome {
	public:
		Awesome(void): _n(0) {}
		Awesome(int n): _n(n) {}
		// Awesome(const Awesome& a) : _n(a._n) {}
		// Awesome & operator=(Awesome & a) {_n=a._n; return *this; }
		bool operator==(Awesome const& rhs) const { return(this->_n == rhs._n); }
		bool operator!=(Awesome const& rhs) const { return(this->_n != rhs._n); }
		bool operator>(Awesome const& rhs) const { return(this->_n > rhs._n); }
		bool operator<(Awesome const& rhs) const { return(this->_n < rhs._n); }
		bool operator>=(Awesome const& rhs) const { return(this->_n >= rhs._n); }
		bool operator<=(Awesome const& rhs) const { return(this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o<<a.get_n(); return o; }

void	test4() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest4: eval sheet\033[0m" << std::endl << std::endl;

	Awesome a(2), b(4);
	swap(a,b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a,b) << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	return 0;
}
