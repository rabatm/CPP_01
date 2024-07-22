#pragma once
#include <stdint.h>
#include "data.hpp"

class Serializer
{
private:
	/* data */
public:
	Serializer(/* args */);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

