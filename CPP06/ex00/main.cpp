#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("0");
    ScalarConverter::convert("nan");
	ScalarConverter::convert("Slurp");
    ScalarConverter::convert("42.0f");
    return 0;
}