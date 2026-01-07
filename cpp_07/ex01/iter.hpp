#pragma once

template <typename T, typename F>
void iter(T* array, const int length, F func)
{
	for (int i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T, typename F>
void iter(T const* array, const int length, F func)
{
	for (int i = 0; i < length; ++i)
		func(array[i]);
}
