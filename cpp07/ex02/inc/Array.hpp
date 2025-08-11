#pragma once
#include <iostream>

template <typename T>
class Array {

	private:
		T		*arr;
		size_t	len;

	public:
		Array( void );
		Array( unsigned int n );
		Array( const Array &other );
		Array &operator=( const Array &other );
		~Array( void );

		const T&	operator[]( size_t i ) const;
		T&			operator[]( size_t i );
		size_t		size( void ) const;
};

template <typename T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& arr);

#include "../src/Array.tpp"
