#include "RPNCalculator.hpp"
#include <stdexcept>

RPNCalculator::RPNCalculator() {}

RPNCalculator::~RPNCalculator() {
   for (std::vector<Token*>::iterator it = tokens.begin(); it != tokens.end();
        ++it) {
      delete *it;
   }
}

RPNCalculator& RPNCalculator::operator=(const RPNCalculator& other) {
   if (this != &other) {
      // Delete existing tokens
      for (std::vector<Token*>::iterator it = tokens.begin();
           it != tokens.end(); ++it) {
         delete *it;
      }
      tokens.clear();

      // Copy tokens from other
      for (std::vector<Token*>::const_iterator it = other.tokens.begin();
           it != other.tokens.end(); ++it) {
         tokens.push_back(
             new Token(**it));  // Dereference twice to get the Token object
      }
   }
   return *this;
}

void RPNCalculator::pushToken(std::string value) {
   tokens.push_back(new Token(value));
}

int RPNCalculator::evaluate() {
   std::vector<int> stack;

   for (std::vector<Token*>::iterator it = tokens.begin(); it != tokens.end();
        ++it) {
      Token* token = *it;
      if (token->getTokenType() == NUMBER) {
         stack.push_back(token->getNumber());
      } else if (token->getTokenType() == OPERATOR) {
         if (stack.size() < 2) {
            throw std::runtime_error(
                "❌ Opération invalide RTFM "
                "😿");
         }
         int b = stack.back();
         stack.pop_back();
         int a = stack.back();
         stack.pop_back();
         char op = token->getOp();
         int result;
         switch (op) {
            case '+':
               result = a + b;
               break;
            case '-':
               result = a - b;
               break;
            case '*':
               result = a * b;
               break;
            case '/':
               if (b == 0) {
                  throw std::runtime_error("❌ Division par zéro 😅");
               }
               result = a / b;
               break;
            default:
               throw std::runtime_error("❌ Opérateur non reconnu");
         }
         stack.push_back(result);
      } else {
         throw std::runtime_error("❌ Token non valide");
      }
   }

   if (stack.size() != 1) {
      throw std::runtime_error(
          "❌ Expression RPN invalide : la pile ne contient pas un seul "
          "résultat");
   }

   return stack.back();
}