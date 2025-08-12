
#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _N) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanException();
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw SpanException();
    }
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    return *maxIt - *minIt;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

const char* Span::SpanException::what() const throw() {
    return "Span exception occurred";
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full";
}