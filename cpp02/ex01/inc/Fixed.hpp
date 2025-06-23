#pragma once
#include <iostream>

class Fixed {
	private:
		int					nb;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed( const int nb );
		Fixed( const float nb);
		Fixed&	operator=( const Fixed& other );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();
};

std::ostream&	operator<<( std::ostream& out, const Fixed& value );



