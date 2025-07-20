#include "PmergeMe.hpp"

std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int>& input) {
	if (input.size() <= 1)
		return input;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> large, small;
	size_t i = 0;
	for (; i + 1 < input.size(); i += 2) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	for (size_t j = 0; j < pairs.size(); ++j) {
		small.push_back(pairs[j].first);
		large.push_back(pairs[j].second);
	}
	if (i < input.size()) {
		small.push_back(input[i]);
	}
	large = fordJohnsonSortVector(large);
	std::vector<int> order = getJacobsthalSequence(small.size());
	for (size_t k = 0; k < order.size(); ++k) {
		if (static_cast<size_t>(order[k]) >= small.size()) continue;
		int val = small[order[k]];
		std::vector<int>::iterator pos = std::lower_bound(large.begin(), large.end(), val);
		large.insert(pos, val);
	}

	return large;
}


std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int>& input) {
	if (input.size() <= 1)
		return input;

	std::vector<std::pair<int, int> > pairs;
	std::deque<int> large, small;

	size_t i = 0;
	while (i + 1 < input.size()) {
		int a = input[i];
		int b = input[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}
	for (size_t j = 0; j < pairs.size(); ++j) {
		large.push_back(pairs[j].second);
		small.push_back(pairs[j].first);
	}
	if (input.size() % 2 != 0)
		small.push_back(input.back());
	large = fordJohnsonSortDeque(large);
	std::vector<int> order = getJacobsthalSequence(small.size());
	for (size_t i = 0; i < order.size(); ++i) {
		if (static_cast<size_t>(order[i]) >= small.size()) continue;
		int val = small[order[i]];

		std::deque<int>::iterator pos = std::lower_bound(large.begin(), large.end(), val);
		large.insert(pos, val);
	}

	return large;
}


void PmergeMe::processInput(const std::vector<std::string>& input) {
	parseInput(input);
	sortVector();
	sortDeque();
}

void PmergeMe::parseInput(const std::vector<std::string>& input) {
	for (std::vector<std::string>::const_iterator it = input.begin(); it != input.end(); ++it) {
		const std::string& str = *it;
		if (isValidNumber(str)) {
			std::stringstream ss(str);
			int number;
			ss >> number;

			sortedVector.push_back(number);
			sortedDeque.push_back(number);
		} else {
			printError("Invalid number: " + str);
		}
	}
}

void PmergeMe::sortVector() {
	std::clock_t start = std::clock();
	sortedVector = fordJohnsonSortVector(sortedVector);
	printTime("Time to process a range with std::vector :", start);
}

void PmergeMe::sortDeque() {
	std::clock_t start = std::clock();
	sortedDeque = fordJohnsonSortDeque(sortedDeque);
	printTime("Time to process a range with std::deque :", start);
}

void PmergeMe::printSortedVector() const {
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = sortedVector.begin(); it != sortedVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printSortedDeque() const {
	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = sortedDeque.begin(); it != sortedDeque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool PmergeMe::isValidNumber(const std::string& str) const {
	if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos) {
		return false;
	}
	std::stringstream ss(str);
	int num;
	ss >> num;
	return !ss.fail() && ss.eof();
}

void PmergeMe::printError(const std::string& message) const {
	std::cerr << "Error: " << message << std::endl;
}

void PmergeMe::printTime(const std::string& message, const std::clock_t& start) const {
	std::clock_t end = std::clock();
	double duration = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << message << " " << duration << " us" << std::endl;
}

std::vector<int> getJacobsthalSequence(size_t n) {
	std::vector<int> sequence;
	if (n == 0) return sequence;

	sequence.push_back(0);
	int j0 = 0, j1 = 1;
	while (sequence.size() < n) {
		int next = j1 + 2 * j0;
		if (static_cast<size_t>(next) >= n)
			break;
		sequence.push_back(next);
		j0 = j1;
		j1 = next;
	}

	for (size_t i = 0; i < n; ++i) {
		if (std::find(sequence.begin(), sequence.end(), static_cast<int>(i)) == sequence.end())
			sequence.push_back(i);
	}

	return sequence;
}
