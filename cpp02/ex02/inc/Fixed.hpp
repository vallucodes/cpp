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
		~Fixed();
		Fixed&	operator=( const Fixed& other );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		bool	operator>( const Fixed& other ) const;
		bool	operator<( const Fixed& other ) const;
		bool	operator>=( const Fixed& other ) const;
		bool	operator<=( const Fixed& other ) const;
		bool	operator==( const Fixed& other ) const;
		bool	operator!=( const Fixed& other ) const;

		Fixed	operator+( const Fixed& other ) const;
		Fixed	operator-( const Fixed& other ) const;
		Fixed	operator*( const Fixed& other ) const;
		Fixed	operator/( const Fixed& other ) const;

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		static Fixed&		min( Fixed& nb1, Fixed& nb2);
		static const Fixed&	min( const Fixed& nb1, const Fixed& nb2);
		static Fixed&		max( Fixed& nb1, Fixed& nb2);
		static const Fixed&	max( const Fixed& nb1, const Fixed& nb2);
};

std::ostream&	operator<<( std::ostream& out, const Fixed& value );
