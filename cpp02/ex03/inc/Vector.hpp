#pragma once
#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

class Vector {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Vector( void );
		Vector( const Point& a, const Point& b );
		Vector( const Vector& other );
		~Vector();
		Vector&	operator=( const Vector& other ) = delete;
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};
