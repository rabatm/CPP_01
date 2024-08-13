#pragma once

#include <vector>
#include "Token.hpp"

class RPNCalculator {
  public:
   RPNCalculator();
   ~RPNCalculator();
   RPNCalculator(const RPNCalculator& other);
   RPNCalculator& operator=(const RPNCalculator& other);

   void pushToken(std::string value);
   int evaluate();

  private:
   std::vector<Token*> tokens;
};