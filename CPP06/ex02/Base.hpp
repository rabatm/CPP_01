#pragma once

#include <stdlib.h>
#include <iostream>
#include <ctime> 
#include <string>

class Base
{
private:
	/* data */
	public:
		virtual ~Base() {};
public:
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);