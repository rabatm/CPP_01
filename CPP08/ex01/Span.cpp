#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &other) : _n(other._n), _array(other._array) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _array = other._array;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_array.size() >= _n) {
        throw std::out_of_range("Span is already full");
    }
    _array.push_back(n);
}

int Span::shortestSpan() {
    if (_array.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }
    std::vector<int> sorted = _array;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < sorted.size(); ++i) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_array.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }
    int minElement = *std::min_element(_array.begin(), _array.end());
    int maxElement = *std::max_element(_array.begin(), _array.end());
    return maxElement - minElement;
}