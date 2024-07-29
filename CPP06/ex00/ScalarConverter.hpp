#pragma once

#include <iostream>
#include <climits>

enum InputType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
	};

class ScalarConverter
{
	private :
		ScalarConverter();
		static InputType detectType(const std::string& literal);
    	static char convertToChar(const std::string& literal);
    	static int convertToInt(const std::string& literal);
		static void convertIn(const std::string& ScalarInput);
		
	public :
		static void convert(const std::string&);
};
