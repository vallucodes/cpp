#include "PmergeMe.hpp"
#include "print.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

int comparisons = 0;

void	swap_keys( std::vector<int>& keys, int i1, int i2 ) {
	int temp = keys[i1];
	keys[i1] = keys[i2];
	keys[i2] = temp;
}

void	fill_mainchain_new_keys( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs) {

	main_chain.insert(main_chain.begin(), new_pairs[new_keys[0]]);
	if (main_chain.size() == 1)
	{
		for (size_t i = 0; i < new_keys.size(); ++i)
			main_chain.push_back(new_keys[i]);
	}
}

size_t	binary_insert_pos( std::vector<int>& main_chain, int value) {
	int left = 0;
	int right = main_chain.size();
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (main_chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
		comparisons++;
	}
	return left;
}

void	fill_mainchain( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs) {
	fill_mainchain_new_keys(main_chain, new_keys, new_pairs);
	// int k = 2;
	// int t = (pow(2, k + 1) + pow(-1, k)) / 3;
	// std::cout << "t: " << t << std::endl;
	size_t new_additions = main_chain.size() - 2;							//calculate this based on current t
	for (size_t i = 0; i < new_additions; ++i)								//loop over all new b's
	{
		int last = new_pairs[main_chain[main_chain.size() - 1 - i]];		//calculate this based on current t
		int new_pos = binary_insert_pos(main_chain, last);
		main_chain.insert(main_chain.begin() + new_pos, last);
	}
	print_mainchain(main_chain);
}

std::vector<int>	recursive_splitting( std::vector<int>& keys, int level ) {
	level++;
	std::unordered_map<int, int> new_pairs;
	std::vector<int> new_keys;
	if (keys.size() < 3)
		return {};
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
	std::vector<int>	main_chain;
	main_chain = recursive_splitting(new_keys, level);
	// std::cout << "new_keys size: " << new_keys.size() << std::endl;
	if (new_keys.size() == 2)
	{
		// std::cout << "new_keys[0] = " << new_keys[0] << " new_keys[1] = " << new_keys[1] << std::endl;
		if (new_keys[0] > new_keys[1])
			swap_keys(new_keys, 1, 0);
		comparisons++;
	}
	fill_mainchain(main_chain, new_keys, new_pairs);
	// print_map(new_keys, new_pairs, level);
	return (main_chain);
}

int	main()
{
	// int size = 20;
	std::vector<int> arr_to_sort = {3, 0, 2, 17, 4, 15, 20, 1, 5, 9, 7, 18, 8, 16, 19, 6};
	// std::vector<int> arr_to_sort = {3, 0, 2, 20, 4, 15, 17, 1};
	recursive_splitting(arr_to_sort, 0);

	// srand(time(0));
	// for (int i = 0; i < size; ++i)
	// {
	// 	std::cout << arr[i] << std::endl;
	// }
	std::cout << "comparisons: " << comparisons << std::endl;
	return 0;
}
