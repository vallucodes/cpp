#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span( unsigned int N ) {
	size = N;
	arr.reserve(N);
}

Span::Span( const Span &other ) {
	size = other.size;
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
		throw std::overflow_error("Maximum amount of elements in array, can't add more");
	arr.push_back(nb);
}

size_t	Span::shortestSpan() {
	if (arr.size() < 2)
		throw std::overflow_error("Not enough elements in array to calculate span");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int	Span::longestSpan() {
	if (arr.size() < 2)
		throw std::runtime_error("Not enough elements in array to calculate span");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}
