#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		MutantStack( void ) = default;
		MutantStack( const MutantStack &other ) = default;
		MutantStack &operator=( const MutantStack &other ) = default;
		~MutantStack( void ) = default;

		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;

		iterator		begin( void );
		iterator		end( void );
		const_iterator	begin( void ) const;
		const_iterator	end( void ) const;
};

#include "../src/MutantStack.tpp"
