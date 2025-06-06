#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) 
{
	if (literal.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return;
	}
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff") {
		std::string sign = literal[0] == '-' ? "-" : "+";
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sign << "inff" << std::endl;
		std::cout << "double: " << sign << "inf" << std::endl;
		return;
	}
	char* endptr;
	long double value = std::strtold(literal.c_str(), &endptr);
	if (*endptr != '\0') {
		std::cerr << "Error: Invalid input" << std::endl;
		return;
	}
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (value < static_cast<long double>(INT_MIN) || value > static_cast<long double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	std::cout << "float: " << f;
	if (f == static_cast<int>(f)) std::cout << ".0";
		std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (d == static_cast<int>(d)) std::cout << ".0";
		std::cout << std::endl;
}
