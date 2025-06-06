#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
private:
	ScalarConverter();  // privateコンストラクタ
public:
	static void convert(const std::string& literal);
};

#endif
