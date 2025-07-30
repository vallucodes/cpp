#pragma once
#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int		size;
		std::vector<int>	arr;

	public:
		Span( void ) = delete;
		Span( unsigned int N );
		Span( const Span &other );
		Span &operator=( const Span &other );
		~Span( void );

		void	addNumber( int nb );
		size_t	shortestSpan();
		int		longestSpan();

		template <typename InputIt>
		void	addNumber( InputIt begin, InputIt end ) {
			auto dist = std::distance(begin, end);
			if (dist <= 0)
				throw std::runtime_error("Invalid iterator range");
			if (arr.size() + dist > size)
				throw std::overflow_error("Maximum amount of elements in array, can't add more");
			arr.insert(arr.end(), begin, end);
		};
};
