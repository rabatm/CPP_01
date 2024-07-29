#include "ScalarConverter.hpp"
#include "myFunctionsUtils.cpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <limits>

    ScalarConverter::ScalarConverter() {}

    InputType ScalarConverter::detectType(const std::string& literal) {
        bool isInt = true;
        bool isFloat = false;
        bool isDouble = false;

        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            return CHAR;
        }

        for (std::string::const_iterator it = literal.begin(); it != literal.end(); ++it) {
            char c = *it;
            if (c == '.') {
                isInt = false;
                isFloat = true;
                break;
            }
            if (c == 'f' && it + 1 == literal.end()) {
                isInt = false;
                isFloat = true;
                break;
            }
            if (c == 'd') {
                isInt = false;
                isDouble = true;
                break;
            }
            if (!std::isdigit(c) && c != '-' && c != '+') {
                return INVALID;
            }
        }
        

        if (isInt) {
            return INT;
        } else if (isFloat) {
            return FLOAT;
        } else if (isDouble) {
            return DOUBLE;
        } else {
            return INVALID;
        }
    }

    char ScalarConverter::convertToChar(const std::string& literal) {
        if (literal.length() == 1) {
            return literal[0];
        }
        if (literal == "0") {
            return '\0';
        }
        throw std::invalid_argument("Error: cannot convert to char");
    }

    int ScalarConverter::convertToInt(const std::string& literal) {
        long unsigned int i;
        std::istringstream iss(literal);
        iss >> i;
        if (iss.fail() || !iss.eof()) {
            throw std::invalid_argument("Error: cannot convert to int");
        }
        return i;
    }

template <typename T>
bool isWithinLimits(const std::string& value) {
    std::stringstream ss(value);
    T result;
    ss >> result;
    return !ss.fail() && ss.eof() && result >= std::numeric_limits<T>::min() && result <= std::numeric_limits<T>::max();
}

void ScalarConverter::convertIn(const std::string& ScalarInput) {
    int type = detectType(ScalarInput);

    try {
        switch (type)
        {
        case CHAR: {
            char c = convertToChar(ScalarInput);
            printScalarConverterResult(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
            break;
        }
        case INT: {
            if (!isWithinLimits<int>(ScalarInput)) {
                throw std::out_of_range("Error: value out of range for int");
            }
            int i = convertToInt(ScalarInput);
            printScalarConverterResult(static_cast<int>(i), i, static_cast<float>(i), static_cast<double>(i));
            break;
        }
        case FLOAT: {
            if (!isWithinLimits<float>(ScalarInput)) {
                throw std::out_of_range("Error: value out of range for float");
            }
            float f;
            std::stringstream ss(ScalarInput);
            if (!(ss >> f)) {
                throw std::invalid_argument("Error: cannot convert to float");
            }
            printScalarConverterResult(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
            break;
        }
        case DOUBLE: {
            if (!isWithinLimits<double>(ScalarInput)) {
                throw std::out_of_range("Error: value out of range for double");
            }
            double d;
            std::stringstream ss(ScalarInput);
            if (!(ss >> d)) {
                throw std::invalid_argument("Error: cannot convert to double");
            }
            printScalarConverterResult(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
            break;
        }
        default:
            printScalarConverterError();
            break;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
    }
}



    void ScalarConverter::convert(const std::string& ScalarInput) {
        if (ScalarInput == "-inf" || ScalarInput == "-inff")
            printScalarConverterResult('E', INT_MIN, __FLT_MIN__, __DBL_MIN__, "impossible");
        else if (ScalarInput == "+inf" || ScalarInput == "+inff")
            printScalarConverterResult('E', INT_MAX, __FLT_MAX__, __DBL_MAX__, "impossible");
        else if (ScalarInput == "nan" || ScalarInput == "nanf")
            printScalarConverterResult('E', 0, 0, 0, "impossible");
        else
            convertIn(ScalarInput);
       
    }
