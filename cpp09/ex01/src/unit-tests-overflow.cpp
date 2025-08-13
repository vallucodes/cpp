#include "../inc/testing.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RESET "\033[0;0m"

// void checkMultiplicationOverflow(int nb1, int nb2) {
// 	if (nb1 == 0 || nb2 == 0)
// 		return;
// 	if (nb1 == -1 && nb2 == std::numeric_limits<int>::lowest())
// 		throw std::runtime_error("Error: overflow");
// 	if (nb1 != 0 && nb1 < 0 && (nb2 < std::numeric_limits<int>::max() / nb1))
// 		throw std::runtime_error("Error: overflow");
// 	if (nb1 != 0 && nb1 < 0 && (nb2 > std::numeric_limits<int>::min() / nb1))
// 		throw std::runtime_error("Error: overflow");
// 	if (nb1 != 0 && nb1 > 0 && (nb2 > std::numeric_limits<int>::max() / nb1))
// 		throw std::runtime_error("Error: overflow");
// 	if (nb1 != 0 && nb1 > 0 && (nb2 < std::numeric_limits<int>::min() / nb1))
// 		throw std::runtime_error("Error: overflow");
// }

void	test2() {
	std::cout << std::endl;
	std::cout << RED << "test2: addition overflow" << RESET << std::endl << std::endl;

	const int INT_MIN = std::numeric_limits<int>::min();
	const int INT_MAX = std::numeric_limits<int>::max();

	int tests[][2] = {
		{0, 0},
		{INT_MAX, 0},				// Max * Zero (safe)
		{0, INT_MIN},				// Zero * Min (safe)
		{1, INT_MAX},				// Overflow
		{-1, INT_MIN},				// Overflow
		{INT_MAX, INT_MAX},			// Overflow
		{INT_MIN, INT_MIN},			// Overflow
		{INT_MIN, 1},				// Safe
		{INT_MIN, -1},				// Overflow
		{1073741824, 1073741824},	// Overflow
		{1073741824, 1073741823},	// Safe
		{-1073741825, -1073741824},	// Overflow
		{-1073741824, -1073741824},	// Safe
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < num_tests; ++i) {
		int nb1 = tests[i][0];
		int nb2 = tests[i][1];

		bool overflow = false;
		try {
			checkAdditionOverflow(nb1, nb2);
		} catch (const std::runtime_error&) {
			overflow = true;
		}

		std::cout << "Test " << i + 1 << ": "
				<< nb1 << " * " << nb2
				<< " -> " << (overflow ? "Overflow" : "Safe")
				<< std::endl;
	}
}

void	test3() {
	std::cout << std::endl;
	std::cout << RED << "test3: multiplication overflow" << RESET << std::endl << std::endl;

	const int INT_MIN = std::numeric_limits<int>::min();
	const int INT_MAX = std::numeric_limits<int>::max();

	int tests[][2] = {
		{0, 0},
		{INT_MAX, 0},			// Max * Zero (safe)
		{0, INT_MIN},			// Zero * Min (safe)
		{1, INT_MAX},			// Safe: 1 * Max
		{-1, INT_MIN},			// Overflow (special case)
		{2, INT_MAX / 2},		// Safe (exact fit)
		{2, INT_MAX / 2 + 1},	// Overflow
		{-2, INT_MIN / 2},		// Safe (exact limit)
		{-2, INT_MIN / 2 - 1},	// Overflow
		{INT_MAX, INT_MAX},		// Overflow (positive * positive)
		{INT_MIN, 1},			// Safe (times 1)
		{INT_MIN, -1},			// Overflow
		{46341, 46341},			// Overflow (sqrt(INT_MAX) + 1)
		{46340, 46340},			// Safe
		{-46341, 46341},		// Overflow (neg * pos)
		{-46341, -46341},		// Overflow (neg * neg)
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);

	for (int i = 0; i < num_tests; ++i) {
		int nb1 = tests[i][0];
		int nb2 = tests[i][1];

		bool overflow = false;
		try {
			checkMultiplicationOverflow(nb1, nb2);
		} catch (const std::runtime_error&) {
			overflow = true;
		}

		std::cout << "Test " << i + 1 << ": "
				<< nb1 << " * " << nb2
				<< " -> " << (overflow ? "Overflow" : "Safe")
				<< std::endl;
	}
}
