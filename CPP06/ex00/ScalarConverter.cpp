#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter() {}

// fonction qui cherche le type de lentree
InputType ScalarConverter::detectType(const std::string& literal) 
{
    bool isInt = true;
    bool isFloat = false;
    bool isDouble = false;
    for (std::string::const_iterator it = literal.begin(); it != literal.end(); ++it)
	{
		char c = *it;
        if (c == '.') {
            isInt = false;
            isFloat = true;
            break;
        }
        if (c == 'f') {
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

    // Renvoie le type detecte
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
    InputType type = detectType(literal);

    // Renvoie la valeur 
    switch (type) {
        case CHAR:
            return literal[0];
        case INT:
            if (std::stoi(literal) > std::numeric_limits<char>::max() || std::stoi(literal) < std::numeric_limits<char>::min()) {
                throw std::out_of_range("Non displayable");
            }
            return static_cast<char>(std::stoi(literal));
        case FLOAT:
            if (std::stof(literal) > std::numeric_limits<char>::max() || std::stof(literal) < std::numeric_limits<char>::min()) {
                throw std::out_of_range("Non displayable");
            }
            return static_cast<char>(std::stof(literal));
        case DOUBLE:
            if (std::stod(literal) > std::numeric_limits<char>::max() || std::stod(literal) < std::numeric_limits<char>::min()) {
                throw std::out_of_range("Non displayable");
            }
            return static_cast<char>(std::stod(literal));
        default:
            throw std::invalid_argument("Non displayable");
    }
}

int ScalarConverter::convertToInt(const std::string& literal) {
    InputType type = detectType(literal);

    // Renvoie la valeur int correspondante
    switch (type) 
	{
        case CHAR:
            return static_cast<int>(literal[0]);
        case INT:
            return std::stoi(literal);
        case FLOAT:
            if (std::stof(literal) > std::numeric_limits<int>::max() || std::stof(literal) < std::numeric_limits<int>::min()) 
			{
                throw std::out_of_range("Non displayable");
            }
            return static_cast<int>(std::stof(literal));
        case DOUBLE:
            if (std::stod(literal) > std::numeric_limits<int>::max() || std::stod(literal) < std::numeric_limits<int>::min()) 
			{
                throw std::out_of_range("Non displayable");
            }
            return static_cast<int>(std::stod(literal));
        default:
            throw std::invalid_argument("Non displayable");
    }
}

float ScalarConverter::convertToFloat(const std::string& literal) 
{
    InputType type = detectType(literal);

    // Renvoie la valeur float correspondante
    switch (type) {
        case CHAR:
            return static_cast<float>(literal[0]);
        case INT:
            return static_cast<float>(std::stoi(literal));
        case FLOAT:
            return std::stof(literal);
        case DOUBLE:
            return static_cast<float>(std::stod(literal));
        default:
            throw std::invalid_argument("Non displayable");
    }
}

double ScalarConverter::convertToDouble(const std::string& literal) {
    InputType type = detectType(literal);

    // Renvoie la valeur double correspondante
    switch (type) {
        case CHAR:
            return static_cast<double>(literal[0]);
        case INT:
            return static_cast<double>(std::stoi(literal));
        case FLOAT:
            return static_cast<double>(std::stof(literal));
        case DOUBLE:
            return std::stod(literal);
        default:
            throw std::invalid_argument("Non displayable");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        char c = convertToChar(literal);
        if (std::iscntrl(c)) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << c << "'" << std::endl;
        }

        int i = convertToInt(literal);
        std::cout << "int: " << i << std::endl;

        float f = convertToFloat(literal);
        std::cout << "float: " << f << "f" << std::endl;

        double d = convertToDouble(literal);
        std::cout << "double: " << d << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
