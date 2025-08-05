#pragma once
#include <iostream>
#include <stack>

class MutantStack : public std::stack<int> {

	public:
		MutantStack( void );
		MutantStack( const MutantStack &other );
		MutantStack &operator=( const MutantStack &other );
		~MutantStack( void );

		void			begin( void );
		MutantStack		operator++( void );
		MutantStack&	operator++( int );
		void			asd( void );
};

// #include "../src/MutantStack.tpp"
