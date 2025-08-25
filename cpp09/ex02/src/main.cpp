#include "PmergeMe.hpp"
#include "print.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <optional>
#include <regex>
#include <sstream>
#include <cstdlib> //rand()

int comparisons = 0;

void	swap_keys( std::vector<int>& keys, int i1, int i2 ) {
	int temp = keys[i1];
	keys[i1] = keys[i2];
	keys[i2] = temp;
}

void	fill_mainchain_new_keys( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs) {

	if (main_chain.size() == 0)
	{
		main_chain.insert(main_chain.begin(), new_pairs[new_keys[0]]);
		for (size_t i = 0; i < new_keys.size(); ++i)
			main_chain.push_back(new_keys[i]);
	}
	else
		main_chain.insert(main_chain.begin(), new_pairs[main_chain[0]]);
}

size_t	related_key( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs ) {
	for (auto& pair : new_pairs)
	{
		if (pair.second == value)
		{
			for (size_t j = 0; j < main_chain.size(); ++j)
			{
				if (main_chain[j] == pair.first)
					return j;
			}
		}
	}
	return main_chain.size();
}

size_t	binary_insert_pos( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs ) {
	size_t left = 0;
	size_t right = related_key(main_chain, value, new_pairs);
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (main_chain[mid] < value)
			left = mid + 1;
		else
			right = mid;
		comparisons++;
	}
	return left;
}

size_t	get_jacobsthal_sequence_rounds( size_t b_values_to_insert ) {
	size_t	k = 2;
	size_t	t = 3;
	while (t < (b_values_to_insert + 1))
	{
		k++;
		t = (pow(2, k + 1) + pow(-1, k)) / 3;
	}
	return (k - 1);
}

size_t get_current( size_t b_values_to_insert, size_t k ) {
	size_t t_curr = (pow(2, k + 1) + pow(-1, k)) / 3;
	if (t_curr > b_values_to_insert + 1)
		return (b_values_to_insert + 1);
	return t_curr;
}

std::vector<int>	fill_full_b_chain( std::vector<int>& main_chain, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder ) {
	size_t k = 2;
	std::vector<int> full_b_chain;
	size_t b_values_to_insert;
	if (remainder.has_value())
		b_values_to_insert = main_chain.size() - 2 + 1;
	else
		b_values_to_insert = main_chain.size() - 2;
	size_t jacobsthal_sequence_rounds = get_jacobsthal_sequence_rounds(b_values_to_insert);
	for (size_t i = 0; i < jacobsthal_sequence_rounds; ++i, ++k)
	{
		size_t t_prev = (pow(2, k) + pow(-1, k - 1)) / 3;
		size_t t_curr = get_current(b_values_to_insert, k );
		size_t new_additions = t_curr - t_prev;
		for (size_t j = 0; j < new_additions; ++j)
		{
			if (j == 0 && (i == jacobsthal_sequence_rounds - 1) && remainder.has_value()) //identify leftover
			{
				full_b_chain.push_back(remainder.value());
				continue ;
			}
			size_t	b_pos = t_curr - j;
			if (b_pos > (main_chain.size() - 1))
				break ;
			size_t	last = new_pairs[main_chain[b_pos]];
			full_b_chain.push_back(last);
		}
	}
	return full_b_chain;
}

void	fill_mainchain( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder) {
	fill_mainchain_new_keys(main_chain, new_keys, new_pairs);
	std::vector<int>	full_b_chain = fill_full_b_chain(main_chain, new_pairs, remainder);
	for (size_t i = 0; i < full_b_chain.size(); ++i)
	{
		size_t value_to_insert = full_b_chain[i];
		size_t new_pos = binary_insert_pos(main_chain, value_to_insert, new_pairs);
		main_chain.insert(main_chain.begin() + new_pos, value_to_insert);
	}
	// print_mainchain(main_chain);
}

std::vector<int>	recursive_splitting( std::vector<int>& keys, int level ) {
	level++;
	std::unordered_map<int, int> new_pairs;
	std::vector<int> new_keys;
	std::optional<int> remainder = std::nullopt;

	if (keys.size() < 2)
		return {};
	if (keys.size() % 2 != 0)
	{
		remainder =	keys.back();
		keys.pop_back();
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
	// print_map(new_keys, new_pairs, level);
	std::vector<int>	main_chain;
	main_chain = recursive_splitting(new_keys, level);
	fill_mainchain(main_chain, new_keys, new_pairs, remainder);
	return (main_chain);
}

void	check_doubles(std::vector<int>& arr) {
	std::unordered_set<int>	present;
	for (int nb : arr)
	{
		if (present.insert(nb).second == false)
			throw std::runtime_error("Error");
	}
}

void	parse_single( std::string input, std::vector<int>& arr) {
	std::istringstream	iss(input);
	std::string			token;
	std::regex valid("^\\d+(, \\d+)*$");

	if (!std::regex_match(input, valid))
		throw std::runtime_error("Error");

	while (std::getline(iss, token, ','))
	{
		size_t pos;
		int nb = std::stoi(token, &pos);
		if (nb < 0)
			throw std::runtime_error("Error");
		if(pos != token.length())
			throw std::runtime_error("Error");
		arr.push_back(nb);
	}
	check_doubles(arr);
}

void	parse_multiple( char** input, std::vector<int>& arr) {
	size_t	i = 1;
	while (input[i])
	{
		std::string token(input[i]);
		size_t pos;
		int nb = std::stoi(token, &pos);
		if (nb < 1)
			throw std::runtime_error("Error");
		if(pos != token.length())
			throw std::runtime_error("Error");
		arr.push_back(nb);
		i++;
	}
	check_doubles(arr);
}

void	print( std::vector<int>& arr, std::string msg ) {
	if (msg == "Before")
		std::cout << msg << ":";
	else
		std::cout << msg << ": ";
	if (arr.size() > 5)
	{
		for (int i = 0; i < 4; ++i)
			std::cout << " " << arr[i];
		std::cout << " [...]" << std::endl;
	}
	if (arr.size() <= 5)
	{
		for (int nb : arr)
			std::cout << " " << nb;
		std::cout << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try {
		std::vector<int> arr_to_sort;
		if (ac == 2)
			parse_single(av[1], arr_to_sort);
		else
			parse_multiple(av, arr_to_sort);
		print(arr_to_sort, "Before");
		std::vector<int> sorted = recursive_splitting(arr_to_sort, 0);
		print(sorted, "After");
		// std::cout << "comparisons: " << comparisons << std::endl;
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
	return 0;
}
