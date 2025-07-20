#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
		return 1;
	}

	std::vector<std::string> input;
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i) {
		std::cout << argv[i] << " ";
		input.push_back(argv[i]);
	}
	std::cout << std::endl;

	PmergeMe pmerge;
	pmerge.processInput(input);
	pmerge.printSortedVector();
	pmerge.printSortedDeque();

	return 0;
}
