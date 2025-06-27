#include "../inc/Vector.hpp"

Vector::Vector( void ) : _x(Fixed()), _y(Fixed()) {}

Vector::Vector( const Point& a, const Point& b ) :
	_x( b.getX() - a.getX()),
	_y( b.getY() - a.getY())
{}

Vector::Vector( const Vector& other ) : _x(other._x), _y(other._y) {}

Vector::~Vector() {}

Fixed	Vector::getX( void ) const {
	return (_x);
}

Fixed	Vector::getY( void ) const {
	return (_y);
}
