#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include "limits.h"

#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
private:
    unsigned int _N;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);
    int shortestSpan() const;
    int longestSpan() const;
    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class SpanException : public std::exception {
    public:
        const char *what() const throw();
    };

    class SpanFullException : public SpanException {
    public:
        const char *what() const throw();
    };
};

#endif // SPAN_HPP