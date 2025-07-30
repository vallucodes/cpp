#include "../inc/Array.hpp"

#define GREEN "\033[0;32m"
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
		arr = new T[n]();
	else
		arr = nullptr;
}

template <typename T>
Array<T>::Array( const Array &other ) {
	// std::cout << GREEN << "Call copy constructor" << RESET << std::endl << std::endl;
	len = other.len;
	if (len != 0)
	{
		arr = new T[len];
		for (size_t i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	else
		arr = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array &other ) {
	// std::cout << GREEN << "Call op=" << RESET << std::endl << std::endl;
	if (this != &other)
	{
		len = other.len;
		if (len != 0)
		{
			delete[] arr;
			arr = new T[len];
			for (size_t i = 0; i < other.len; i++)
				arr[i] = other.arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void ) {
	// std::cout << GREEN << "Call destructor" << RESET << std::endl << std::endl;
	delete[] arr;
}

template <typename T>
const T&	Array<T>::operator[]( size_t i ) const {
	// std::cout << GREEN << "Call operator [] const" << RESET << std::endl << std::endl;
	if (i >= len)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
T&	Array<T>::operator[]( size_t i ) {
	// std::cout << GREEN << "Call operator []" << RESET << std::endl << std::endl;
	if (i >= len)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
size_t	Array<T>::size( void ) const {
	// std::cout << GREEN << "Call size" << RESET << std::endl << std::endl;
	return len;
}

template <typename T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& array) {
	os << "[";
	for (size_t i = 0; i < array.size(); i++)
	{
		os << array[i];
		if	((i + 1) != array.size())
			os << ", ";
	}
	os << "]";
	return os;
}
