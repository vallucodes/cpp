// #include <iostream>
// #include <limits>

// int main() {
// 	int res;
// 	int nb1 = -1;
// 	int nb2 = -2147483648;

// 	if (nb1 == -1 && nb2 == std::numeric_limits<int>::lowest())
// 		std::cout << "Overflow" << std::endl;

// 	std::cout << "past 0" << std::endl;
// 	// std::cout << res << std::endl;
// 	if (nb1 != 0 && nb1 < 0 && (nb2 < std::numeric_limits<int>::max() / nb1))
// 	{
// 		std::cout << "Overflow" << std::endl;
// 	}
// 	std::cout << "past 1" << std::endl;
// 	if (nb1 != 0 && nb1 < 0 && (nb2 > std::numeric_limits<int>::lowest() / nb1))
// 	{
// 		std::cout << "Overflow2" << std::endl;
// 	}
// 	std::cout << "past 2" << std::endl;
// 	if (nb1 != 0 && nb1 > 0 && (nb2 > std::numeric_limits<int>::max() / nb1))
// 	{
// 		std::cout << "Overflow" << std::endl;
// 	}
// 	std::cout << "past 3" << std::endl;
// 	if (nb1 != 0 && nb1 > 0 && (nb2 < std::numeric_limits<int>::lowest() / nb1))
// 	{
// 		std::cout << "Overflow2" << std::endl;
// 	}
// 	res = nb1 * nb2;
// 	std::cout << res << std::endl;
// }


#include <iostream>
#include <limits>
#include <stdexcept>

void checkMultiplicationOverflow(int nb1, int nb2) {
	if (nb1 == 0 || nb2 == 0)
		return;
	if (nb1 == -1 && nb2 == std::numeric_limits<int>::lowest())
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 < 0 && (nb2 < std::numeric_limits<int>::max() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 < 0 && (nb2 > std::numeric_limits<int>::lowest() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 > 0 && (nb2 > std::numeric_limits<int>::max() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 > 0 && (nb2 < std::numeric_limits<int>::lowest() / nb1))
		throw std::runtime_error("Error: overflow");
}

void	test3() {
	std::cout << std::endl;
	std::cout << "\033[1;31mtest3: multiplication overflow\033[0m" << std::endl << std::endl;

	const int MIN = std::numeric_limits<int>::min();
	const int MAX = std::numeric_limits<int>::max();

	int tests[][2] = {
		{0, 0},                     // Zero × Zero (safe)
		{MAX, 0},                   // Max × Zero (safe)
		{0, MIN},                   // Zero × Min (safe)
		{1, MAX},                   // Safe: 1 × Max
		{-1, MIN},                  // Overflow (special case)
		{2, MAX / 2},               // Safe (exact fit)
		{2, MAX / 2 + 1},           // Overflow
		{-2, MIN / 2},              // Safe (exact limit)
		{-2, MIN / 2 - 1},          // Overflow
		{MAX, MAX},                 // Overflow (positive × positive)
		{MIN, 1},                   // Safe (times 1)
		{MIN, -1},                  // Overflow
		{46341, 46341},             // Overflow (sqrt(MAX) + 1)
		{46340, 46340},             // Safe
		{-46341, 46341},            // Overflow (neg × pos)
		{-46341, -46341},           // Overflow (neg × neg)
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

int main() {
	test1();
	test2();
	test3();
	return 0;
}
