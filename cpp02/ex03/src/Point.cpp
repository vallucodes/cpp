#include "../inc/Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point( const Point& other ) : _x(other._x), _y(other._y) {}

Point::~Point() {};

Fixed	Point::getX( void ) const {
	return(_x);
}

Fixed	Point::getY( void ) const {
	return(_y);
}
