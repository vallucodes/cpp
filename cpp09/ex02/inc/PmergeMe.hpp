#pragma once
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

class PmergeMe {

	private:
		size_t				comparisons;
		std::vector<int>	arr;
		// std::deque<int>		stack;

	public:
		PmergeMe( void ) = delete;
		PmergeMe( std::vector<int>& arr );
		PmergeMe( const PmergeMe& other ) = delete;
		PmergeMe& operator=( const PmergeMe& other ) = delete;
		~PmergeMe( void ) = default;

		static std::vector<int>	parse( int ac, char **av );
		void				sort( void );
		void				print( std::string msg ) const;

		const	std::vector<int>&	getData() const;
		size_t	getComparisons( void ) const;
};

