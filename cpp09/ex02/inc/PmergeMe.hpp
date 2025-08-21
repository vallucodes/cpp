#pragma once
#include <iostream>
#include <stack>

class RPN {

	private:
		std::stack<int>	stack;

	public:
		RPN( void ) = default;
		RPN( const RPN& other ) = delete;
		RPN& operator=( const RPN& other ) = delete;
		~RPN( void ) = default;

		std::stack<int>& getStack( void );
};

