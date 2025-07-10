#pragma once
#include "Animal.hpp"
#include <iostream>

class Brain {

	private:
		std::string	ideas[100];

	public:
		Brain( void );
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		~Brain( void );
		void				setIdea( int i, const std::string &idea );
		const std::string&	getIdea( int i ) const;
};
