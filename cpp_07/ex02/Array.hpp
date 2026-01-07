#pragma once

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
public:
	Array() : _array(NULL), _size(0) {}

	Array(unsigned int n) : _array(NULL), _size(n) {
		if (_size > 0)
			_array = new T[_size]();
	}

	Array(int n) : _array(NULL), _size(0) {
		if (n < 0)
			throw std::length_error("negative size");
		_size = static_cast<unsigned int>(n);
		if (_size > 0)
			_array = new T[_size]();
	}

	Array(const Array &copy) : _array(NULL), _size(0) {
		if (copy._size > 0) {
			_array = new T[copy._size];
			_size = copy._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}
	}

	~Array() {
		delete[] _array;
	}

	Array &operator=(const Array &copy) 
	{
		if (this != &copy) 
		{
			unsigned int i = 0;
			T *newArray = NULL;
			if (copy._size > 0) 
			{
				newArray = new T[copy._size];
				for (i = 0; i < copy._size; i++)
					newArray[i] = copy._array[i];
			}
			delete[] _array;
			_array = newArray;
			_size = copy._size;
		}
		return *this;
	}

	T &operator[](unsigned int i) 
	{
		if (i >= _size)
			throw std::out_of_range("index out of bounds");
		return _array[i];
	}

	const T &operator[](unsigned int i) const 
	{
		if (i >= _size)
			throw std::out_of_range("index out of bounds");
		return _array[i];
	}

	unsigned int size() const 
	{
		return _size;
	}

private:
	T*            _array;
	unsigned int  _size;
};
