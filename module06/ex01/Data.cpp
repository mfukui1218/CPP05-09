#include "Data.hpp"

Data::Data() : _value(0), _str("") {}

Data::Data(int value) : _value(value), _str("") {}

Data::Data(const Data& other) : _value(other._value), _str(other._str) {}

Data::~Data() {}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		_value = other._value;
		_str = other._str;
	}
	return *this;
}

int Data::getValue() const {
	return _value;
}

std::string Data::getStr() const {
	return _str;
}

void Data::setValue(int value) {
	_value = value;
}

void Data::setStr(std::string str) {
	_str = str;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
	os << "Data value: " << data.getValue() << ", Data string: " << data.getStr();
	return os;
}
