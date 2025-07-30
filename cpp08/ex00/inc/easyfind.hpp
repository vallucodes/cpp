#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
auto	easyfind(const T& container, int n) {
	auto i = std::find(container.begin(), container.end() , n);
	if (i == container.end())
		throw std::runtime_error("Value not found");
	return i;
}
