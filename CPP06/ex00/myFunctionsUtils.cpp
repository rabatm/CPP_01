#pragma once
#include <iostream>
#include <string>

void printScalarConverterResult(char charResult, int intResult, float floatResult, double doubleResult, std::string stringerror = "")
{
    // Codes d'échappement ANSI pour les couleurs
    const std::string BLUE = "\033[34m";
    const std::string GREEN = "\033[32m";
    const std::string ORANGE = "\033[38;5;214m"; // L'orange n'est pas standard, donc on utilise un code 256 couleurs
    const std::string PURPLE = "\033[35m";
    const std::string RESET = "\033[0m";

	if (stringerror != "")
		std::cout << BLUE << "char: " << stringerror << RESET << std::endl;
	else
    	std::cout << BLUE << "char: " << charResult << RESET << std::endl;
    std::cout << GREEN << "int: " << intResult << RESET << std::endl;
    std::cout << ORANGE << "float: " << floatResult << "f" << RESET << std::endl;
    std::cout << PURPLE << "double: " << doubleResult << RESET << std::endl;
}

void printScalarConverterError() 
{
	printScalarConverterResult('E', 0, 0, 0, "impossible");
}