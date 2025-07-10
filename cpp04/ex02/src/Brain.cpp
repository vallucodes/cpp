#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "---No neural activity in this braincell---";
}

Brain::Brain( const Brain& other ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=( const Brain& other ) {
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea( int i, const std::string &idea ) {
	ideas[i] = idea;
}

const std::string&	Brain::getIdea( int i ) const {
	return ideas[i];
}
