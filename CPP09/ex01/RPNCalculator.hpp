#pragma once
#include <stack>
#include <stdexcept>
#include <string>
#include "Token.hpp"

class RPNCalculator {
  public:
   RPNCalculator();
   ~RPNCalculator();
   RPNCalculator& operator=(const RPNCalculator& other);
   void pushToken(const std::string& value);
   int evaluate();

  private:
   std::stack<Token*> tokens;
};