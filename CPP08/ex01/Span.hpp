#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _array;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        virtual ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end);
};

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end) {
    while (begin != end) {
        if (_array.size() >= _n) {
            throw std::out_of_range("Span is already full");
        }
        _array.push_back(*begin);
        ++begin;
    }
}