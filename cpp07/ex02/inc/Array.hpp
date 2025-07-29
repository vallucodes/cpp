#pragma once
#include <iostream>
#include <exception>

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

		class outOfRange : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		void		setValue( size_t i , T value );
		T			getValue( size_t i ) const;
		size_t		getArrLen( void ) const;
		const T&	operator[]( size_t i ) const;
		T&			operator[]( size_t i );
		size_t		size( void );
};

template <typename T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& arr);

#include "../src/Array.tpp"
