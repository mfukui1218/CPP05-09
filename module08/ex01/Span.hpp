#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _numbers;
public:
	Span(unsigned int N);
	Span(const Span &src);
	~Span();
	Span &operator=(const Span &src);

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

	class SpanFullException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif
