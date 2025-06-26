#include <iostream>
#include "../inc/Fixed.hpp"
#include "../inc/bsp.hpp"

void test1() {
	Point a(0, 0), b(3, 0), c(0, 3), point(1, 1);
	bool inside = bsp(a, b, c, point);
	std::cout << "Test 1: point(1,1) in triangle((0,0), (3,0), (0,3)) is "
			<< (inside ? "inside" : "outside") << std::endl;
}

void test2() {
	Point a(0, 0), b(3, 0), c(0, 3), point(4, 4);
	bool inside = bsp(a, b, c, point);
	std::cout << "Test 2: point(4,4) in triangle((0,0), (3,0), (0,3)) is "
			<< (inside ? "inside" : "outside") << std::endl;
}

void test3() {
	Point a(1, 1), b(4, 1), c(2, 3), point(2, 2);
	bool inside = bsp(a, b, c, point);
	std::cout << "Test 3: point(2,2) in triangle((1,1), (4,1), (2,3)) is "
			<< (inside ? "inside" : "outside") << std::endl;
}

void test4() {
	Point a(0, 0), b(3, 0), c(0, 3), point(0, 2.5);
	bool inside = bsp(a, b, c, point);
	std::cout << "Test 4: point(0,2.5) in triangle((0,0), (3,0), (0,3)) is "
			<< (inside ? "inside" : "outside") << std::endl;
}

int main(void) {
	test1();
	test2();
	test3();
	test4();
	return 0;
}
