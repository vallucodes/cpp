#pragma once
#include "Fixed.hpp"
#include <iostream>

class Fixed {
	private:
		int					nb;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed&	operator=( const Fixed& other );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();
};



