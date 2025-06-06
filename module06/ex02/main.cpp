#include <iostream>
#include "Base.hpp"
#include "generate.hpp"

void identify(Base* p);
void identify(Base& p);

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; ++i) {
		std::cout << "---- Test #" << i + 1 << " ----" << std::endl;

		Base* ptr = generate();

		std::cout << "[Pointer version] ";
		identify(ptr);

		std::cout << "[Reference version] ";
		identify(*ptr);

		delete ptr;
		std::cout << std::endl;
	}

	return 0;
}
