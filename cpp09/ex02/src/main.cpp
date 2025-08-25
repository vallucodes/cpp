#include "PmergeMe.hpp"
#include "print.hpp"
#include <chrono>

int	main(int ac, char **av)
{
	auto start = std::chrono::high_resolution_clock::now();
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try {
		auto parsed_data = PmergeMe::parse(ac, av);
		PmergeMe sorter(parsed_data);
		sorter.print("Before");
		sorter.sort();
		sorter.print("After");
		std::cout << sorter.getComparisons() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	// int size = 33;
	// std::vector<int> arr_to_sort = {4, 1, 3, 17, 5, 15, 20, 2, 6, 10, 8, 18, 9, 16, 19, 7};
	// std::vector<int> arr_to_sort = {4, 1, 3, 20, 5, 15, 17, 8, 9, 2, 12, 11};
	// std::vector<int> arr_to_sort = {5, 1, 6, 10, 7, 8, 4, 9, 2};
	// std::vector<int> arr_to_sort = {4, 1, 3, 5, 6, 2, 9, 10};
	// std::vector<int> arr_to_sort = {17, 8, 9, 2, 12, 11, 3, 1};
	// std::vector<int> arr_to_sort = {2, 4, 9, 1, 5, 8, 3};
	// std::vector<int> arr_to_sort = {2, 9, 4, 6, 3, 7};
	// std::vector<int> arr_to_sort = {17, 8, 9, 1, 12};
	// std::vector<int> arr_to_sort;
	// srand(time(0));
	// for (int i = 0; i < size; ++i)
	// {
	// 	arr_to_sort.push_back(rand() % 100000);
	// 	std::cout << arr_to_sort[i] << std::endl;
	// }
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> duration = end - start;
	std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
	return 0;
}
