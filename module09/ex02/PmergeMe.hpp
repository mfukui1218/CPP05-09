#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <sstream>
# include <ctime>

std::vector<int> getJacobsthalSequence(size_t n);

class PmergeMe {
private:
	std::vector<int> sortedVector;
	std::deque<int> sortedDeque; 
public:
	PmergeMe() {};
	~PmergeMe() {};
	void processInput(const std::vector<std::string>& input);
	void sortVector();
	void sortDeque();
	void printSortedVector() const;
	void printSortedDeque() const;
	void parseInput(const std::vector<std::string>& input);
	bool isValidNumber(const std::string& str) const;
	void printError(const std::string& message) const;
	void printTime(const std::string& message, const std::clock_t& start) const;
	std::vector<int> fordJohnsonSortVector(std::vector<int>& input);
	std::deque<int> fordJohnsonSortDeque(std::deque<int>& input);
};



#endif
