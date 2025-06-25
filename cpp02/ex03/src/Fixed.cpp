#include "../inc/Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : nb(0) {}

Fixed::Fixed( const Fixed& other ) {
	nb = other.getRawBits();
}

Fixed::Fixed( const int nb ) {
	this->nb = nb * 256;
}

Fixed::Fixed( const float nb ) {
	this->nb = roundf(nb * 256);
}

Fixed::~Fixed( void ) {}

float	Fixed::toFloat( void ) const {
	float	res;

	res = nb / 256.0;
	return (res);
}

int		Fixed::toInt( void ) const {
	int	res;

	res = nb >> fractional_bits;
	return (res);
}

int	Fixed::getRawBits( void ) const {
	return (this->nb);
}

void	Fixed::setRawBits( int const raw ) {
	this->nb = raw;
}

Fixed&	Fixed::operator=( const Fixed& other ) {
	setRawBits(other.getRawBits());
	return *this;
}

std::ostream& operator<<( std::ostream& out, const Fixed& value ) {
	out << value.toFloat();
	return out;
}

bool	Fixed::operator>( const Fixed& other ) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<( const Fixed& other ) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==( const Fixed& other ) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return (this->getRawBits() != other.getRawBits());
}


Fixed	Fixed::operator+( const Fixed& other ) const {
	Fixed		result;
	long long	raw_result;

	raw_result = this->getRawBits() + other.getRawBits();
	result.setRawBits(raw_result);
	return (result);
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	Fixed		result;
	long long	raw_result;

	raw_result = this->getRawBits() - other.getRawBits();
	result.setRawBits(raw_result);
	return (result);
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	Fixed		result;
	long long	raw_result;

	raw_result = this->getRawBits() * other.getRawBits();
	raw_result = raw_result >> fractional_bits;

	result.setRawBits(raw_result);
	return (result);
}

Fixed	Fixed::operator/( const Fixed& other ) const {
	Fixed		result;
	long long	first_term;
	long long	raw_result;

	first_term = this->getRawBits() << fractional_bits;
	raw_result = first_term / other.getRawBits();

	result.setRawBits(raw_result);
	return (result);
}

Fixed&	Fixed::operator++( void ) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	old;

	old = *this;
	++(*this);
	return (old);
}

Fixed&	Fixed::operator--( void ) {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	old;

	old = *this;
	--(*this);
	return (old);
}

Fixed&	Fixed::min( Fixed& nb1, Fixed& nb2) {
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::min( const Fixed& nb1, const Fixed& nb2) {
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

Fixed&	Fixed::max( Fixed& nb1, Fixed& nb2) {
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

const Fixed&	Fixed::max( const Fixed& nb1, const Fixed& nb2) {
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

