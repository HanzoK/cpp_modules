#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("no such value in this container");
    return it;
}
