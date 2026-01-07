#include "PmergeMe.hpp"

/**
 * PmergeMe
 */

PmergeMe::PmergeMe() : _vectorComparisons(0), _dequeComparisons(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
    : _vectorComparisons(copy._vectorComparisons),
      _dequeComparisons(copy._dequeComparisons)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        _vectorComparisons = copy._vectorComparisons;
        _dequeComparisons  = copy._dequeComparisons;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

long PmergeMe::getVectorComparisons() const
{
    return _vectorComparisons;
}

long PmergeMe::getDequeComparisons() const
{
    return _dequeComparisons;
}

void PmergeMe::sortVector(std::vector<int> &values)
{
    _vectorComparisons = 0;
    mergeInsertSort(values, 1, _vectorComparisons);
}

void PmergeMe::sortDeque(std::deque<int> &values)
{
    _dequeComparisons = 0;
    mergeInsertSort(values, 1, _dequeComparisons);
}

/**
 * Jacobsthal numbers:
 * J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2)
 */
long jacobsthal(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    long j0 = 0;
    long j1 = 1;
    for (int i = 2; i <= n; ++i)
    {
        long j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    return j1;
}
