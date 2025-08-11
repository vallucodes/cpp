#include "../inc/Array.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0;0m"

template <typename T>
Array<T>::Array( void ) :
	arr(nullptr),
	len(0)
{}

template <typename T>
Array<T>::Array( unsigned int n ) {
	len = n;
	if (n != 0)
		arr = new T[n]();
	else
		arr = nullptr;
}

template <typename T>
Array<T>::Array( const Array &other ) {
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
		else
			arr = nullptr;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] arr;
}

template <typename T>
const T&	Array<T>::operator[]( size_t i ) const {
	if (i >= len)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
T&	Array<T>::operator[]( size_t i ) {
	if (i >= len)
		throw std::out_of_range("Index out of range");
	return arr[i];
}

template <typename T>
size_t	Array<T>::size( void ) const {
	return len;
}

template <typename T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& array ) {
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
