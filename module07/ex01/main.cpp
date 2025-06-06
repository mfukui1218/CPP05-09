#include "iter.hpp"

void printInt(int const &x) {
	std::cout << x << std::endl;
}

int main() {
	int arr[] = {1, 2, 3, 4};
	::iter(arr, 4, printInt);
	return 0;
}
