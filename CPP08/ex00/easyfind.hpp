#pragma once
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

template <typename T>
int easyfind(T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return *it;
}