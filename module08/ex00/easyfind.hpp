#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

template <typename T>
class EasyFind
{
public:
	EasyFind(T &container, int value) : _container(container), _value(value) {}
	~EasyFind() {}
	void find()
	{
		typename T::iterator it = std::find(_container.begin(), _container.end(), _value);
		if (it != _container.end())
			std::cout << "Value " << _value << " found at position: " << std::distance(_container.begin(), it) << std::endl;
		else
			throw NotFoundException();
	}
	class NotFoundException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Value not found in the container";
		}
	};
private:
	T &_container;
	int _value;
};

#endif
