#include "iter.hpp"
#include <iostream>

template <typename T>
void printIndex(T const& x)
{
	std::cout << x << " ";
}

int main()
{
	int nums1[] = {1, 2, 3, 4};
	::iter(nums1, 4, printIndex<int>);
	std::cout << std::endl;

	std::string words1[] = {"alpha", "beta", "gamma"};
	::iter(words1, 3, printIndex<std::string>);
	std::cout << std::endl;

	const int nums2[] = {10, 20, 30, 40};
	::iter(nums2, 4, printIndex<int>);
	std::cout << std::endl;

	const std::string words2[] = {"one", "two"};
	::iter(words2, 2, printIndex<std::string>);
	std::cout << std::endl;

	return 0;
}

