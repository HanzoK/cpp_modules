#pragma once

#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

/*
    PmergeMe – Ford–Johnson Merge-Insert Sort
    -----------------------------------------
    - Recursive merge-insert structure, groupSize doubles each recursion
    - Uses Jacobsthal sequence to reduce comparisons
    - bigNumbers: iterators to "large" group maxima (main group)
    - smallNumbers: iterators to "small" group maxima waiting to be inserted
    - moveIterator: helper to move iterators
*/

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    ~PmergeMe();

    void sortVector(std::vector<int> &values);
    void sortDeque(std::deque<int> &values);

    long getVectorComparisons() const;
    long getDequeComparisons() const;

private:
    long _vectorComparisons;
    long _dequeComparisons;

    // main Ford–Johnson sort
    template <typename Container>
    void mergeInsertSort(Container &data, int groupSize, long &comparisonCounter);

    template <typename Iterator>
    void swapGroup(Iterator it, int groupSize);
};

/* ============================== HELPERS ============================== */

// Jacobsthal index (1-based): J(n) = J(n-1) + 2*J(n-2)
long jacobsthal(int n);

template <typename Iterator>
Iterator moveIterator(Iterator it, int steps)
{
    std::advance(it, steps);
    return it;
}

/*
    binaryInsertWithCounter (Binary Search Insertion)
    -----------------------
    - Performs a binary search on [first, last).
    - Elements in [first, last) are iterators (DataIter) pointing into the
      underlying container that holds the actual int values.
    - 'value' is also a DataIter, pointing to the int we are inserting.
    - Comparisons are done on *value and **mid (int vs int).
    - Each comparison increments comparisonCounter.
*/
template <typename VecIter, typename DataIter>
VecIter binaryInsertWithCounter(VecIter first, VecIter last, DataIter value, long &comparisonCounter)
{
    while (first < last)
    {
        VecIter mid = first;
        std::advance(mid, (last - first) / 2);

        ++comparisonCounter;
        if (*value < **mid)
            last = mid;
        else
            first = mid + 1;
    }
    return first;
}

/* ============================== TEMPLATES ============================== */

template <typename Iterator>
void PmergeMe::swapGroup(Iterator it, int groupSize)
{
    Iterator begin = moveIterator(it, -groupSize + 1);
    Iterator end   = moveIterator(begin, groupSize);

    while (begin != end)
    {
        std::iter_swap(begin, moveIterator(begin, groupSize));
        ++begin;
    }
}

/*
    mergeInsertSort
    -----------------------------------------------------
    Steps:
    1. Pair groups of size groupSize, compare their maxima, and
       swap entire groups if out of order.
    2. Recursively sort with doubled groupSize.
    3. Build bigNumbers (main group of "big" group maxima).
    4. Build smallNumbers (remaining "small" maxima).
    5. Insert smallNumbers in Jacobsthal sequence via binaryInsertWithCounter.
    6. Insert remaining smallNumbers from right to left.
    7. Flatten groups back into the underlying container.
*/
template <typename Container>
void PmergeMe::mergeInsertSort(Container &data, int groupSize, long &comparisonCounter)
{
    typedef typename Container::iterator Iterator;
	typedef std::vector<Iterator> IteratorVector;
	typedef typename IteratorVector::iterator IteratorVectorIter;

    int groupCount = static_cast<int>(data.size()) / groupSize;
    if (groupCount < 2)
        return;

    bool hasStragglerGroup = (groupCount % 2 == 1);

    Iterator begin = data.begin();
    Iterator last  = moveIterator(begin, groupSize * groupCount);
    Iterator limit = last;
    if (hasStragglerGroup)
        limit = moveIterator(last, -groupSize);

    /* ===================== Step 1: compare & swap adjacent groups ============ */

    int step = 2 * groupSize; //pairwise-step for Ford-Johnson
    for (Iterator it = begin; it != limit; std::advance(it, step))
    {
        Iterator currentMax = moveIterator(it, groupSize - 1);
        Iterator nextMax    = moveIterator(it, groupSize * 2 - 1);

        ++comparisonCounter;
        if (*nextMax < *currentMax)
            swapGroup(currentMax, groupSize);
    }

    /* ===================== Step 2: recursively sort groups =================== */

    mergeInsertSort(data, groupSize * 2, comparisonCounter);

    /* ===================== Step 3: make bigNumbers and smallNumbers ========== */

    IteratorVector bigNumbers;
    IteratorVector smallNumbers;

    //start with b1 and a1
    bigNumbers.push_back(moveIterator(data.begin(), groupSize - 1));// b1
    bigNumbers.push_back(moveIterator(data.begin(), groupSize * 2 - 1)); // a1

    //fill groups: bigNumbers gets ai, smallNumbers gets bi
    for (int i = 4; i <= groupCount; i += 2)
    {
        smallNumbers.push_back(moveIterator(data.begin(), groupSize * (i - 1) - 1));//bi
        bigNumbers.push_back(moveIterator(data.begin(), groupSize * i - 1)); // a_i
    }

    //straggler group (unpaired/lonely last group)
    if (hasStragglerGroup)
    {
        Iterator lastGroupStart = moveIterator(data.begin(), groupSize * (groupCount - 1));
        smallNumbers.push_back(moveIterator(lastGroupStart, groupSize - 1));
    }

    /* Step 4: Insert smallNumbers via Jacobsthal Sequence into bigNumbers */

    if (!smallNumbers.empty())
    {
        int prevJacob  = jacobsthal(1);
        int insertedCount  = 0;

        for (int k = 2; ; ++k)
        {
            int currJacob   = jacobsthal(k);
            int insertionCount = currJacob - prevJacob;

            if (insertionCount <= 0)
            {
                prevJacob = currJacob;
                continue;
            }

            if (insertionCount > static_cast<int>(smallNumbers.size()))
                break;

            IteratorVectorIter smallIt = smallNumbers.begin();
            std::advance(smallIt, insertionCount - 1);

            IteratorVectorIter bigIt = bigNumbers.begin();
            std::advance(bigIt, currJacob + insertedCount);

            int limitShift = 0;
            int toInsert   = insertionCount;

            while (toInsert > 0)
            {
                Iterator insertionValue = *smallIt;

                IteratorVectorIter insertPos = binaryInsertWithCounter(bigNumbers.begin(), bigIt, insertionValue, comparisonCounter);

                IteratorVectorIter inserted = bigNumbers.insert(insertPos, *smallIt);

                smallIt = smallNumbers.erase(smallIt);
                if (smallIt != smallNumbers.begin())
                    std::advance(smallIt, -1);

                if (inserted - bigNumbers.begin() == currJacob + insertedCount)
                    ++limitShift;

                bigIt = bigNumbers.begin();
                std::advance(bigIt, currJacob + insertedCount - limitShift);

                --toInsert;
            }
            prevJacob = currJacob;
            insertedCount += insertionCount;
        }
    }

    /* == Step 5: Insert remaining smallNumbers not in Jacobsthal sequence == */

    int stragglerOffset = 0;
    if (hasStragglerGroup)
        stragglerOffset = 1;

    for (int i = static_cast<int>(smallNumbers.size()) - 1; i >= 0; --i)
    {
        IteratorVectorIter smallIt = smallNumbers.begin();
		std::advance(smallIt, i);

        int insertionLimit = static_cast<int>(bigNumbers.size()) - static_cast<int>(smallNumbers.size()) + i + stragglerOffset;

        IteratorVectorIter bigIt = bigNumbers.begin();
		std::advance(bigIt, insertionLimit);

        Iterator insertionValue = *smallIt;

        IteratorVectorIter insertPos = binaryInsertWithCounter(bigNumbers.begin(), bigIt, insertionValue, comparisonCounter);

        bigNumbers.insert(insertPos, *smallIt);
    }

    /* ================== Step 6–7: Copy sorted sequence  ====================== */

    Container copy;

    IteratorVectorIter groupMaxIt = bigNumbers.begin();
    while (groupMaxIt != bigNumbers.end())
    {
        for (int i = 0; i < groupSize; ++i)
        {
            Iterator groupStart = *groupMaxIt;
            std::advance(groupStart, -groupSize + i + 1);
            copy.push_back(*groupStart);
        }
        ++groupMaxIt;
    }

	typename Container::iterator dataIt = data.begin();
	typename Container::const_iterator copyIt = copy.begin();
    while (copyIt != copy.end() && dataIt != data.end())
    {
        *dataIt = *copyIt;
        ++dataIt;
        ++copyIt;
    }
}
