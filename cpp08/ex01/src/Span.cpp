#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>

Span::Span( unsigned int N ) {
	size = N;
	arr.reserve(size);
}

Span::Span( const Span &other ) {
	size = other.size;
	arr.reserve(size);
	arr = other.arr;
}

Span& Span::operator=( const Span &other ) {
	if (this != &other)
	{
		size = other.size;
		arr = other.arr;
	}
	return *this;
}

Span::~Span( void ) {}

void	Span::addNumber( int nb ) {
	if (arr.size() >= size)
		throw std::runtime_error("Maximum amount of elements in array, can't add more");
	arr.push_back(nb);
}

int	Span::shortestSpan() {
	if (arr.size() < 2)
		throw std::runtime_error("Not enough elements in array to calculate span");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
	std::vector<int>::iterator it = std::min_element(diffs.begin() + 1, diffs.end());
	return (*it);
}

int	Span::longestSpan() {
	if (arr.size() < 2)
		throw std::runtime_error("Not enough elements in array to calculate span");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}
