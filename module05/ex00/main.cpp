#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("Alice", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade(); // ここで例外が出る
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat c("Bob", 151);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
