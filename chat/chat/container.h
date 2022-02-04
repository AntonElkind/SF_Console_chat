#pragma once
#include <iostream>
#include <exception>

template <typename T>
class Container
{
private:
	int _length;
	T* _data;

public:
	Container();
	Container(const Container& other);
	~Container();
	Container& operator=(const Container& other);
	T& operator[](int index);

	int getLength();
	void add(const T& element);
};

class BadRange : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Invalid array index!";
	}
};

class BadSize : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Not enough space!";
	}
};

/**
* Template class implementation
*/
template <typename T>
Container<T>::Container() : _length(0), _data(nullptr)
{
}

template <typename T>
Container<T>::Container(const Container& other) : Container()
{
	if (other._length)
	{
		_length = other._length;
		_data = new T[this->_length];
		for (int i = 0; i < this->_length; ++i)
		{
			_data[i] = other._data[i];
		}
	}
}

template <typename T>
Container<T>::~Container()
{
	delete[] _data;
}

template <typename T>
Container<T>& Container<T>::operator=(const Container& other)
{
	if (_length == 0)
	{
		if (other._length)
		{
			_length = other._length;
			_data = new T[_length];
			for (int i = 0; i < _length; ++i)
			{
				_data[i] = other._data[i];
			}
		}
	}
	else
	{
		if (_length < other._length)
		{
			throw BadSize();
		}
		for (int i = 0; i < other._length; ++i)
		{
			_data[i] = other._data[i];
		}
	}
	return *this;
}

template<typename T>
T& Container<T>::operator[](int index)
{
	if (index < 0 || index > _length - 1)
	{
		throw BadRange();
	}
	return _data[index];
}

template <typename T>
int Container<T>::getLength()
{
	return _length;
}

template <typename T>
void  Container<T>::add(const T& element)
{
	T* dataTemp(nullptr);
	try
	{
		dataTemp = new T[_length + 1];
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << "bad_alloc caught!" << std::endl;
		std::cout << ba.what() << std::endl;
	}
	if (dataTemp == nullptr)
	{
		return;
	}
	int i;
	for (i = 0; i < _length; ++i)
	{
		dataTemp[i] = _data[i];
	}
	dataTemp[i] = element;
	delete[] _data;
	_data = dataTemp;
	++_length;
}