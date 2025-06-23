#include "../inc/Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : nb(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	nb = other.getRawBits();
}

Fixed::Fixed( const int nb ) {
	std::cout << "Int constructor called" << std::endl;
	this->nb = nb * 256;
}

Fixed::Fixed( const float nb ) {
	std::cout << "Float constructor called" << std::endl;
	this->nb = roundf(nb * 256);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	nb = other.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& out, const Fixed& value ) {
	out << value.toFloat();
	return out;
}

float	Fixed::toFloat( void ) const {
	float	res;

	res = nb / 256.0;
	return (res);
}

int		Fixed::toInt( void ) const {
	int	res;

	res = nb >> 8;
	return (res);
}

int Fixed::getRawBits( void ) const {
	return (nb);
}

void	Fixed::setRawBits( int const raw ) {
	this->nb = raw;
}
