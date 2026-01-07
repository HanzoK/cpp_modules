#pragma once

#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <limits>
#include <vector>
#include <iostream>

class Span {
public:
    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();

    void addNumber(int value);

    template <typename InputIt>
    void addNumber(InputIt first, InputIt last) 
	{
        unsigned int count = 0;
        for (InputIt it = first; it != last; it++)
            count++;

        if (_numbers.size() + count > _maxSize)
            throw FullSpanException();

        _numbers.insert(_numbers.end(), first, last);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;

    class FullSpanException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    unsigned int       _maxSize;
    std::vector<int>   _numbers;
};
