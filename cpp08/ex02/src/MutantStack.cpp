#include "../inc/MutantStack.hpp"
#include <stdexcept>
#include <algorithm>


MutantStack::MutantStack( const MutantStack &other ) {

}

MutantStack::MutantStack( const MutantStack &other ) {}

MutantStack& MutantStack::operator=( const MutantStack &other ) {
	if (this != &other)
		this->operator=(other);
	return *this;
}

MutantStack::~MutantStack( void ) {}

MutantStack	MutantStack::operator++( void ) {
	this->c.push_front(10);
}

void	MutantStack::asd( void ) {
	this->c.push_front(10);
	this->c.begin();
}
