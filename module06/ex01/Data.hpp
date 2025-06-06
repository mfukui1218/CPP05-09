#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <iomanip>


class Data {
private:
	int         _value;
	std::string _str;
public:
	Data();
	Data(int value);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	int         getValue() const;
	std::string getStr() const;
	void        setValue(int value);
	void        setStr(std::string str);
};

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif
