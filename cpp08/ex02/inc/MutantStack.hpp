#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

	public:
		MutantStack( void ) = default;
		MutantStack( const MutantStack &other ) = default;
		MutantStack &operator=( const MutantStack &other ) = default;
		~MutantStack( void ) = default;

		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;

		iterator		begin( void );
		iterator		end( void );
		const_iterator	begin( void ) const;
		const_iterator	end( void ) const;
};

#include "../src/MutantStack.tpp"
