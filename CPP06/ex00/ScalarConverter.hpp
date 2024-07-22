#pragma once

#include <iostream>

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
    	static float convertToFloat(const std::string& literal);
    	static double convertToDouble(const std::string& literal);
		
	public :
		static void convert(const std::string&);
};
