#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <stdexcept>
#include <time.h>   // clock_gettime()

// ====== VISUAL SHOWCASE OF FORD–JOHNSON IDEA ======

// static void printVectorInline(const std::vector<int> &v)
// {
//     std::cout << "[ ";
//     for (std::size_t i = 0; i < v.size(); ++i)
//     {
//         std::cout << v[i];
//         if (i + 1 < v.size())
//             std::cout << " ";
//     }
//     std::cout << " ]";
// }
//
// static void visualShowcaseFordJohnson()
// {
//     std::cout << "\n===== Ford–Johnson visual showcase (as a concept) =====\n";
//
//     // Example sequence (even length for simple pairing)
//     std::vector<int> input;
//     input.push_back(9);
//     input.push_back(3);
//     input.push_back(7);
//     input.push_back(1);
//     input.push_back(8);
//     input.push_back(2);
//     input.push_back(6);
//     input.push_back(4);
//
//     std::cout << "Initial sequence:\n    ";
//     printVectorInline(input);
//     std::cout << "\n\n";
//
//     // Step 1: Pair elements and sort inside each pair
//     std::vector< std::pair<int,int> > pairs;
//     for (std::size_t i = 0; i < input.size(); i += 2)
//     {
//         int x = input[i];
//         int y = input[i + 1];
//
//         int a = x;
//         int b = y;
//         if (b > a)
//             std::swap(a, b);
//
//         pairs.push_back(std::make_pair(a, b));
//     }
//
//     std::cout << "Step 1: Pair and compare elements (aᵢ = max, bᵢ = min):\n";
//     for (std::size_t i = 0; i < pairs.size(); ++i)
//     {
//         std::cout << "    Pair " << (i + 1) << ": (a" << (i + 1) 
//                   << " = " << pairs[i].first 
//                   << ", b" << (i + 1) 
//                   << " = " << pairs[i].second << ")\n";
//     }
//     std::cout << "\n";
//
//     // Step 2: Build main chain from aᵢ (the maxima), and list pending bᵢ
//     std::vector<int> mainChain;
//     std::vector<int> pending;
//
//     for (std::size_t i = 0; i < pairs.size(); ++i)
//     {
//         mainChain.push_back(pairs[i].first); // aᵢ
//         pending.push_back(pairs[i].second);  // bᵢ
//     }
//
//     std::cout << "Step 2: Build main chain from all aᵢ (pair maxima):\n    ";
//     printVectorInline(mainChain);
//     std::cout << "\n";
//
//     std::cout << "Pending elements (all bᵢ to be inserted later):\n    ";
//     printVectorInline(pending);
//     std::cout << "\n\n";
//
//     // Step 3: Sort the main chain (this stands in for the recursive part)
//     std::cout << "Step 3: Sort main chain (this represents the recursive sorting of group maxima):\n";
//     std::sort(mainChain.begin(), mainChain.end());
//     std::cout << "    Sorted main chain: ";
//     printVectorInline(mainChain);
//     std::cout << "\n\n";
//
//     // Step 4: Insert each bᵢ into the main chain using binary search
//     std::cout << "Step 4: Insert each pending bᵢ into the main chain using binary search:\n";
//
//     for (std::size_t i = 0; i < pending.size(); ++i)
//     {
//         int value = pending[i];
//
//         std::cout << "  - Insert b" << (i + 1) << " = " << value << " into ";
//         printVectorInline(mainChain);
//         std::cout << "\n";
//
//         std::vector<int>::iterator pos =
//             std::lower_bound(mainChain.begin(), mainChain.end(), value);
//
//         if (pos == mainChain.begin())
//             std::cout << "    -> goes at the FRONT (no element smaller than it)\n";
//         else if (pos == mainChain.end())
//             std::cout << "    -> goes at the BACK (larger than all elements)\n";
//         else
//             std::cout << "    -> goes BETWEEN " << *(pos - 1) << " and " << *pos << "\n";
//
//         mainChain.insert(pos, value);
//
//         std::cout << "    Chain after insertion: ";
//         printVectorInline(mainChain);
//         std::cout << "\n\n";
//     }
//
//     std::cout << "Final fully sorted sequence (from this simplified Ford–Johnson view):\n    ";
//     printVectorInline(mainChain);
//     std::cout << "\n\n";
// }

// ========================================================= //
// ====== ACTUAL CODEBASE FOR THIS PROJECT ================= // 
// ========================================================= //

static long getTime()
{
    struct timespec ts;

    // use CLOCK_MONOTONIC for more precise interval measurements
    clock_gettime(CLOCK_MONOTONIC, &ts);

    long micros = ts.tv_sec * 1000000L;
    micros += ts.tv_nsec / 1000L;

    return micros;
}

/* ====== INPUT PARSING ====== */

static bool isValidNumber(const std::string &input)
{
	if (input.empty())
		return false;

	std::size_t i = 0;

    if (input[0] == '+')
    {
        if (input.size() == 1)
            return false;
        i = 1;
    }
    
    // for (; i < input.size(); ++i)
    // {
    //     if (!std::isdigit(static_cast<unsigned char>(input[i])))
    //         return false;
    // }

    for (; i < input.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(input[i])))
            return false;

    std::stringstream buffer(input);
    long value = 0;
    buffer >> value;

    if (buffer.fail() || !buffer.eof())
        return false;

    if (value < 0 || value > INT_MAX)
        return false;

    // if (value < static_cast<long>(INT_MIN) || value > static_cast<long>(INT_MAX))
    //     return false;

    return true;
}

static void parseInput(int argc, char **argv, std::vector<int> &vec, std::deque<int>  &deq)
{
    if (argc < 2)
        throw std::runtime_error("Error: not enough arguments");

    for (int i = 1; i < argc; ++i)
    {
        std::string token = argv[i];
        if (!isValidNumber(token))
            throw std::runtime_error("Error: not a valid number UwU");

        int value = std::atoi(token.c_str());
        vec.push_back(value);
        deq.push_back(value);
    }
}

/* ====== PRINT NUMBERS ====== */

static void printNumbersBefore(int argc, char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i];
        if (i + 1 < argc)
            std::cout << " ";
    }
    std::cout << std::endl;
}

static void printNumbersAfter(const std::vector<int> &vec)
{
    std::cout << "After:  ";
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

static void printTimingAndComparisons(const char *label, std::size_t count, double timeMicrosec, long comparisons)
{
	(void)comparisons;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);

    std::cout << "Time to process " << count << " elements with " << label << " : " << timeMicrosec << " us" << std::endl;
    std::cout << "Comparisons with " << label << " : " << comparisons << std::endl;
}

/* ====== MAIN ====== */

int main(int argc, char **argv)
{
    std::vector<int> vec;
    std::deque<int>  deq;

    try
    {
        parseInput(argc, argv, vec, deq);
    }
    catch (const std::exception &)
    {
        std::cerr << "Error in input detected." << std::endl;
        return 1;
    }

    PmergeMe sorter;

    printNumbersBefore(argc, argv);

    std::vector<int> vecSorted = vec;
    std::deque<int>  deqSorted = deq;

    /* ====== VECTOR TIMING ====== */

    long vecStart = getTime();
    sorter.sortVector(vecSorted);
    long vecEnd = getTime();

    /* ====== DEQUE TIMING ====== */

    long deqStart = getTime();
    sorter.sortDeque(deqSorted);
    long deqEnd = getTime();

    /* ====== RESULTS COMPARISON ====== */

	printNumbersAfter(vecSorted);

    double vecTime = static_cast<double>(vecEnd - vecStart);
    double deqTime = static_cast<double>(deqEnd - deqStart);

    printTimingAndComparisons("vector", vecSorted.size(), vecTime, sorter.getVectorComparisons());
    printTimingAndComparisons("deque", deqSorted.size(), deqTime, sorter.getDequeComparisons());

	// visualShowcaseFordJohnson();

    return 0;
}
