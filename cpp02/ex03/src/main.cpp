#include <iostream>
#include "../inc/Fixed.hpp"
#include "../inc/bsp.hpp"

int main( void ) {
	Point a;
	Point b(3, 0);
	Point c(0, 3);
	Point point(1, 1);
	bsp(a, b, c, point);
	return 0;
}
