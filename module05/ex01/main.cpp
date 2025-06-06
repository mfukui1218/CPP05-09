#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat alice("Alice", 42);
	Form taxForm("TaxForm", 40, 10);

	std::cout << alice << std::endl;
	std::cout << taxForm << std::endl;

	alice.signForm(taxForm); // 失敗する
	std::cout << taxForm << std::endl;

	Bureaucrat boss("Boss", 1);
	boss.signForm(taxForm); // 成功する
	std::cout << taxForm << std::endl;

	return 0;
}
