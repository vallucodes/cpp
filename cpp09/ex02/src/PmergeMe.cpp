#include "PmergeMe.hpp"
// #include "print.hpp"

namespace parsing_utils_vector {
	void				checkDoubles( std::vector<int>& arr );
	std::vector<int>	parseSingle( std::string input );
	std::vector<int>	parseMultiple( char** input );
}

namespace algo_utils {
	void				fillMainchainNewKeys( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs );
	size_t				relatedKey( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs );
	size_t				binaryInsertPos( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs, size_t& comparisons );
	size_t				getJacobsthalSequenceRounds( size_t b_values_to_insert );
	size_t				get_current( size_t b_values_to_insert, size_t k );
	std::vector<int>	fillFullBChain( std::vector<int>& main_chain, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder );
	void				fillMainchain( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder, size_t& comparisons );
	std::vector<int>	recursiveSplitting( std::vector<int>& keys, size_t& comparisons);
}

namespace parsing_utils_vector {
	void	checkDoubles( std::vector<int>& arr ) {
		std::unordered_set<int>	present;
		for (int nb : arr)
		{
			if (present.insert(nb).second == false)
				throw std::runtime_error("Error");
		}
	}

	std::vector<int>	parseSingle( std::string input ) {
		std::istringstream	iss(input);
		std::string			token;
		std::vector<int>	arr;
		std::regex valid("^\\d+(, \\d+)*$");

		if (!std::regex_match(input, valid))
			throw std::runtime_error("Error");

		while (std::getline(iss, token, ','))
		{
			size_t pos;
			int nb = std::stoi(token, &pos);
			if (nb < 1 || pos != token.length())
				throw std::runtime_error("Error");
			arr.push_back(nb);
		}
		checkDoubles(arr);
		return arr;
	}

	std::vector<int>	parseMultiple( char** input ) {
		size_t				i = 1;
		std::vector<int>	arr;
		while (input[i])
		{
			std::string token(input[i]);
			size_t pos;
			int nb = std::stoi(token, &pos);
			if (nb < 1 || pos != token.length())
				throw std::runtime_error("Error");
			arr.push_back(nb);
			i++;
		}
		checkDoubles(arr);
		return arr;
	}
}

namespace algo_utils {
	void	fillMainchainNewKeys( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs ) {

		if (main_chain.size() == 0)
		{
			main_chain.insert(main_chain.begin(), new_pairs[new_keys[0]]);
			for (size_t i = 0; i < new_keys.size(); ++i)
				main_chain.push_back(new_keys[i]);
		}
		else
			main_chain.insert(main_chain.begin(), new_pairs[main_chain[0]]);
	}

	size_t	relatedKey( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs ) {
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
	size_t	binaryInsertPos( std::vector<int>& main_chain, int value, std::unordered_map<int, int>& new_pairs, size_t& comparisons ) {
		size_t left = 0;
		size_t right = relatedKey(main_chain, value, new_pairs);
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

	size_t	getJacobsthalSequenceRounds( size_t b_values_to_insert ) {
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

	std::vector<int>	fillFullBChain( std::vector<int>& main_chain, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder ) {
		size_t k = 2;
		std::vector<int> full_b_chain;
		size_t b_values_to_insert;
		if (remainder.has_value())
			b_values_to_insert = main_chain.size() - 2 + 1;
		else
			b_values_to_insert = main_chain.size() - 2;
		size_t jacobsthal_sequence_rounds = getJacobsthalSequenceRounds(b_values_to_insert);
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

	void	fillMainchain( std::vector<int>& main_chain, std::vector<int>& new_keys, std::unordered_map<int, int>& new_pairs, std::optional<int> remainder, size_t& comparisons ) {
		fillMainchainNewKeys(main_chain, new_keys, new_pairs);
		std::vector<int>	full_b_chain = fillFullBChain(main_chain, new_pairs, remainder);
		for (size_t i = 0; i < full_b_chain.size(); ++i)
		{
			size_t value_to_insert = full_b_chain[i];
			size_t new_pos = binaryInsertPos(main_chain, value_to_insert, new_pairs, comparisons);
			main_chain.insert(main_chain.begin() + new_pos, value_to_insert);
		}
	}

	std::vector<int>	recursiveSplitting( std::vector<int>& keys, size_t& comparisons) {
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
		std::vector<int>	main_chain;
		main_chain = recursiveSplitting(new_keys, comparisons);
		fillMainchain(main_chain, new_keys, new_pairs, remainder, comparisons);
		return (main_chain);
	}
}


PmergeMe::PmergeMe( std::vector<int>& arr ) : comparisons(0) {
	this->arr = std::move(arr);
};

void	PmergeMe::sort( void ) {
	std::vector<int> sorted = algo_utils::recursiveSplitting(this->arr, this->comparisons);
	this->arr = std::move(sorted);
}

std::vector<int>	PmergeMe::parse( int ac, char **av ) {
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	try {
		if (ac == 2)
			return (parsing_utils_vector::parseSingle(av[1]));
		else
			return (parsing_utils_vector::parseMultiple(av));
	} catch (std::exception& e) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
}

void	PmergeMe::print( std::string msg ) const {
	if (msg == "Before")
		std::cout << msg << ":";
	else
		std::cout << msg << ": ";
	if (getData().size() > 5)
	{
		for (int i = 0; i < 4; ++i)
			std::cout << " " << getData()[i];
		std::cout << " [...]" << std::endl;
	}
	if (getData().size() <= 5)
	{
		for (int nb : getData())
			std::cout << " " << nb;
		std::cout << std::endl;
	}
}

const	std::vector<int>&	PmergeMe::getData() const {
	return arr;
}

size_t	PmergeMe::getComparisons( void ) const {
	return comparisons;
}
