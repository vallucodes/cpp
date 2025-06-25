#include <iostream>
#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed ( 2 ) );
	Fixed const c( Fixed( 30.5f ) / Fixed ( 2 ) );
	Fixed const d( Fixed( 5.05f ) + Fixed ( 2 ) );
	Fixed const e( Fixed( 5.05f ) - Fixed ( 2 ) );
	Fixed const f( Fixed( 5.05f ) - Fixed ( 2 ) );

	std::cout << "a: " << a << std::endl;
	// std::cout << ++a << std::endl;
	std::cout << "b: " << b << std::endl;
	// std::cout << a++ << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	if (b > c)
		std::cout << "b > c: true" << std::endl;
	else
		std::cout << "b > c: false" << std::endl;

	if (b < c)
		std::cout << "b < c: true" << std::endl;
	else
		std::cout << "b < c: false" << std::endl;

	if (b >= c)
		std::cout << "b >= c: true" << std::endl;
	else
		std::cout << "b >= c: false" << std::endl;

	if (f >= e)
		std::cout << "f >= e: true" << std::endl;
	else
		std::cout << "f >= e: false" << std::endl;

	if (b <= c)
		std::cout << "b <= c: true" << std::endl;
	else
		std::cout << "b <= c: false" << std::endl;

	if (f <= e)
		std::cout << "f <= e: true" << std::endl;
	else
		std::cout << "f <= e: false" << std::endl;

	if (a == d)
		std::cout << "a == d: true" << std::endl;
	else
		std::cout << "a == d: false" << std::endl;

	if (e == f)
		std::cout << "e == f: true" << std::endl;
	else
		std::cout << "e == f: false" << std::endl;

	if (a != d)
		std::cout << "a != d: true" << std::endl;
	else
		std::cout << "a != d: false" << std::endl;

	if (e != f)
		std::cout << "e != f: true" << std::endl;
	else
		std::cout << "e != f: false" << std::endl;

	return 0;
}
