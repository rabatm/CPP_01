#pragma once

#include <iostream>
#include <string>

enum Color {
    RED,
    GREEN,
    BLUE,
    DEFAULT
};

template <typename V, typename U, typename T>

void iter(T *array, const U size, const V func)
{
	for (U i = 0; i < size; i++)
	{
		func(array[i]);
	}
}

// fonction pour le printage !!!
template< typename T >

void myPrint(const T& x)
{
  std::cout << x << std::endl;
  return;
}

template< typename T >

void printTitle(const T& text, const Color & color)
{
  switch (color)
  {
	case RED:
	  std::cout << "\033[31m";
	  break;
	case GREEN:
	  std::cout << "\033[33m";
	  break;
	case BLUE:
	  std::cout << "\033[34m";
	  break;
	default:
	  std::cout << "\033[0m";
	  break;
  }
  std::cout << text << std::endl << "\033[0m";
  return;
}
