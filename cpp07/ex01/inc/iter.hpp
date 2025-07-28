#pragma once
#include <iostream>
#include <cstdint>

template <typename T, typename F>
void	iter(T* arr, size_t len, F func) {
	if (!arr || len == 0)
		return ;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}
