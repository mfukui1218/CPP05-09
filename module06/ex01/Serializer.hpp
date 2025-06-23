#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <iomanip>
#include <stdint.h> 

class Data;

class Serializer {
private:
	Serializer();  // privateコンストラクタ
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
