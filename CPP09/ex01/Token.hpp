#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include "TokenType.hpp"

class Token {
  public:
   Token(const std::string& value);
   Token(TokenType type, int value);
   Token(TokenType type, char value);
   Token(const Token& other);             // Copy constructor
   Token& operator=(const Token& other);  // Copy assignment operator
   ~Token();

   std::string toString() const;
   char getOp() const;
   int getNumber() const;
   TokenType getTokenType() const;

  private:
   TokenType type;
   union {
      int number;
      char op;
   } value;
};