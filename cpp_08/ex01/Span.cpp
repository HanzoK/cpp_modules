#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int n) : _maxSize(n), _numbers() 
{
    _numbers.reserve(n);
}

Span::Span(const Span &copy)
: _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span &Span::operator=(const Span &copy) 
{
    if (this != &copy) {
        _maxSize = copy._maxSize;
        _numbers = copy._numbers;
    }
    return *this;
}

Span::~Span() {}

// -------------------------------------------------------------

void Span::addNumber(int value) 
{
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();
    _numbers.push_back(value);
}

unsigned int Span::shortestSpan() const 
{
    if (_numbers.size() < 2)
        throw NotEnoughElementsException();

    std::vector<int> tmp_vec(_numbers);
    std::sort(tmp_vec.begin(), tmp_vec.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::size_type i = 1; i < tmp_vec.size(); ++i) {
        unsigned int diff = static_cast<unsigned int>(static_cast<long>(tmp_vec[i]) - static_cast<long>(tmp_vec[i - 1]));
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const 
{
    if (_numbers.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt));
}

unsigned int Span::size() const 
{
    return static_cast<unsigned int>(_numbers.size());
}

unsigned int Span::capacity() const 
{
    return _maxSize;
}

// -------------------------------------------------------------

const char *Span::FullSpanException::what() const throw() 
{
    return "span is already full: cannot fit any more numbers";
}

const char *Span::NotEnoughElementsException::what() const throw() 
{
    return "span too small to fit all these numbers";
}
