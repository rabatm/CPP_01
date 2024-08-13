#include "Token.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Token::Token(const std::string& value) {
   if (!value.empty() && std::isdigit(value[0])) {
      type = NUMBER;
      std::stringstream ss(value);
      ss >> this->value.number;
      if (ss.fail()) {
         throw std::invalid_argument("❌ Invalid number format 😿");
      }
   } else if (value.length() == 1 && !std::isdigit(value[0])) {
      std::string validOperators = "+-*/";
      if (validOperators.find(value) == std::string::npos) {
         throw std::invalid_argument("❌ Invalid operator 😿");
      }
      type = OPERATOR;
      this->value.op = value[0];
   } else {
      throw std::invalid_argument("❌ Invalid token value 😿");
   }
}

Token::Token(TokenType type, int value) : type(type) {
   if (type == NUMBER) {
      this->value.number = value;
   } else {
      throw std::invalid_argument("❌ Invalid token type 😿");
   }
}

Token::Token(TokenType type, char value) : type(type) {
   if (type == OPERATOR) {
      this->value.op = value;
   } else {
      throw std::invalid_argument("❌ Invalid token type 😿");
   }
}

Token::Token(const Token& other) : type(other.type) {
   if (type == NUMBER) {
      value.number = other.value.number;
   } else {
      value.op = other.value.op;
   }
}

Token& Token::operator=(const Token& other) {
   if (this != &other) {
      type = other.type;
      if (type == NUMBER) {
         value.number = other.value.number;
      } else {
         value.op = other.value.op;
      }
   }
   return *this;
}

TokenType Token::getTokenType() const { return type; }
char Token::getOp() const { return value.op; }
int Token::getNumber() const { return value.number; }
Token::~Token() {}