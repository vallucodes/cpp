#include "PmergeMe.hpp"
#include "print.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

int comparisons = 0;

void	swap_keys( std::vector<int>& keys, int i1, int i2 ) {
	int temp = keys[i1];
	keys[i1] = keys[i2];
	keys[i2] = temp;
}

void	fill_mainchain( std::vector<int>& main_chain, std::vector<int>& new_keys) {
	
}

std::vector<int>&	recursive_splitting( std::vector<int>& keys, int level) {
	level++;
	std::unordered_map<int, int> new_pairs;
	std::vector<int> new_keys;
	if (keys.size() < 3)
	{
		return ;
	}
	for (size_t i = 0; i < keys.size(); i += 2)
	{
		if (keys[i] > keys[i + 1])
		{
			new_keys.push_back(keys[i]);
			new_pairs[keys[i]] = keys[i + 1];
		}
		else
		{
			new_keys.push_back(keys[i + 1]);
			new_pairs[keys[i + 1]] = keys[i];
		}
		comparisons++;
	}
	print_map(new_keys, new_pairs, level);
	recursive_splitting(new_keys, level);
	std::vector<int>	main_chain;
	// std::cout << "new_keys size: " << new_keys.size() << std::endl;
	if (new_keys.size() == 2)
	{
		// std::cout << "new_keys[0] = " << new_keys[0] << " new_keys[1] = " << new_keys[1] << std::endl;
		if (new_keys[0] > new_keys[1])
		{
			// std::cout << "yes" << std::endl;
			swap_keys(new_keys, 1, 0);
		}
		comparisons++;
	}
	fill_mainchain(main_chain, new_keys);
	print_map(new_keys, new_pairs, level);
	return (main_chain);
}

// std::vector<int, int> create_first_map( std::vector<int> arr_to_sort, std::vector<int> keys ) {
// 	std::unordered_map<int, int> pairs;

// 	for (size_t i = 0; i < arr_to_sort.size(); i += 2)
// 	{
// 		keys.push_back(arr_to_sort[i]);
// 		pairs[arr_to_sort[i]] = arr_to_sort[i + 1];
// 	}
// 	print_map(keys, pairs);
// 	return keys;
// }

int	main()
{
	// int size = 20;
	// std::vector<int> arr_to_sort = {3, 0, 2, 17, 4, 15, 20, 1, 5, 9, 7, 18, 8, 16, 19, 6};
	std::vector<int> arr_to_sort = {3, 0, 2, 20, 4, 15, 17, 1};
	recursive_splitting(arr_to_sort, 0);

	// srand(time(0));
	// for (int i = 0; i < size; ++i)
	// {
	// 	std::cout << arr[i] << std::endl;
	// }
	std::cout << "comparisons: " << comparisons << std::endl;
	return 0;
}
