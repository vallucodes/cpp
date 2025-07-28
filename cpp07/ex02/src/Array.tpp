#include "../inc/Array.hpp"

template <class T>
Array<T>::Array( void ) {

}

template <class T>
Array<T>::Array( unsigned int n ) {

}

template <class T>
Array<T>::Array( const Array &other ) {

}

template <class T>
Array<T>& Array<T>::operator=( const Array &other ) {

}
// ~Array( void );

template <class T>
const char*	Array<T>::outOfRange::what() const noexcept {
	return ("Index out of bounds of array");
}
