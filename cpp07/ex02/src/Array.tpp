#include "../inc/Array.hpp"

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

template <typename T>
Array<T>::Array( void ) :
	arr(nullptr),
	len(0)
{
	// std::cout << GREEN << "Call default constructor" << RESET << std::endl << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) {
	// std::cout << GREEN << "Call constructor with n" << RESET << std::endl << std::endl;
	len = n;
	if (n != 0)
		arr = new T[n];
	else
		arr = nullptr;
}

template <typename T>
Array<T>::Array( const Array &other ) {
	// std::cout << GREEN << "Call copy constructor" << RESET << std::endl << std::endl;
	len = other.getArrLen();
	if (len != 0)
	{
		arr = new T[len];
		for (size_t i = 0; i < len; i++)
			this->setValue(i, other.getValue(i));
	}
	else
		arr = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array &other ) {
	// std::cout << GREEN << "Call op=" << RESET << std::endl << std::endl;
	if (this != &other)
	{
		len = other.getArrLen();
		if (len != 0)
		{
			delete[] arr;
			arr = new T[len];
			for (size_t i = 0; i < other.getArrLen(); i++)
				this->setValue(i, other.getValue(i));
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] arr;
}

template <typename T>
const char*	Array<T>::outOfRange::what() const noexcept {
	return ("Index out of bounds of array");
}

template <typename T>
void	Array<T>::setValue( size_t i , T value ) {
	// std::cout << GREEN << "Call setValue" << RESET << std::endl << std::endl;
	if (i < 0 || i >= getArrLen())
		throw outOfRange();
	arr[i] = value;
}

template <typename T>
T	Array<T>::getValue( size_t i ) const {
	// std::cout << GREEN << "Call getValue" << RESET << std::endl << std::endl;
	if (i < 0 || i >= getArrLen())
		throw outOfRange();
	return arr[i];
}

template <typename T>
size_t	Array<T>::getArrLen( void ) const {
	// std::cout << GREEN << "Call getArrLen" << RESET << std::endl << std::endl;
	return len;
}

template <typename T>
const T&	Array<T>::operator[]( size_t i ) const {
	// std::cout << GREEN << "Call operator [] const" << RESET << std::endl << std::endl;
	if (i < 0 || i >= getArrLen())
		throw outOfRange();
	return arr[i];
}

template <typename T>
T&	Array<T>::operator[]( size_t i ) {
	// std::cout << GREEN << "Call operator []" << RESET << std::endl << std::endl;
	if (i < 0 || i >= getArrLen())
		throw outOfRange();
	return arr[i];
}

template <typename T>
size_t	Array<T>::size( void ) {
	// std::cout << GREEN << "Call size" << RESET << std::endl << std::endl;
	return getArrLen();
}

template <typename T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& array) {
	os << "[";
	for (size_t i = 0; i < array.getArrLen(); i++)
	{
		os << array.getValue(i);
		if	((i + 1) != array.getArrLen())
			os << ", ";
	}
	os << "]";
	return os;
}
