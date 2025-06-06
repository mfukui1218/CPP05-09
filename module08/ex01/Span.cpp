#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){}

Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers)
{
	*this = src;
}

Span::~Span(){}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_numbers = src._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return max - min;
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to find a span";
}

