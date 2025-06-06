#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <exception>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack() {}
	MutantStack(const MutantStack &src) : std::stack<T>(src) {}
	~MutantStack() {}

	MutantStack &operator=(const MutantStack &src)
	{
		if (this != &src)
		{
			std::stack<T>::operator=(src);
		}
		return *this;
	}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
};

#endif
