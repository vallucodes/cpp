#pragma once
#include "../inc/Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point( void );
		Point( const float nb1, const float nb2 );
		Point( const Point& point );
		~Point();
		Point&	operator=( const Point& other ) = delete;
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};
