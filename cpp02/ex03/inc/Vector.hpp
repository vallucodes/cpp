#pragma once
#include "../inc/Fixed.hpp"

class Vector {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point( void );
		Point( const float nb1, const float nb2 );
		~Point();
};
