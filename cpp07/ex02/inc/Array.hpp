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
		~Array( void ) = default;

		class outOfRange : public std::exception {
			public:
				const char* what() const noexcept override;
		}
};
