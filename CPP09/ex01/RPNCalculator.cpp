// RPNCalculator.cpp

#include "RPNCalculator.hpp"
#include <iostream>

RPNCalculator::RPNCalculator() {}

RPNCalculator::~RPNCalculator() {
   while (!tokens.empty()) {
      delete tokens.top();
      tokens.pop();
   }
}

RPNCalculator& RPNCalculator::operator=(const RPNCalculator& other) {
   if (this != &other) {
      // Supprimer les tokens existants
      while (!tokens.empty()) {
         delete tokens.top();
         tokens.pop();
      }

      // Copier les tokens depuis 'other'
      std::stack<Token*> temp;
      std::stack<Token*> otherTokens = other.tokens;
      while (!otherTokens.empty()) {
         temp.push(new Token(*otherTokens.top()));
         otherTokens.pop();
      }
      while (!temp.empty()) {
         tokens.push(temp.top());
         temp.pop();
      }
   }
   return *this;
}

void RPNCalculator::pushToken(const std::string& value) {
   tokens.push(new Token(value));
}

int RPNCalculator::evaluate() {
   std::stack<int> stack;
   std::stack<Token*> tempTokens = tokens;
   int stackSize = 0;  // Initialiser à 0

   while (!tempTokens.empty()) {
      Token* token = tempTokens.top();
      tempTokens.pop();

      if (token->getTokenType() == NUMBER) {
         stack.push(token->getNumber());
         stackSize++;
      } else if (token->getTokenType() == OPERATOR) {
         if (stackSize < 2) {
            throw std::runtime_error("❌ Opération invalide RTFM 😿");
         }
         int b = stack.top();
         stack.pop();
         stackSize--;
         int a = stack.top();
         stack.pop();
         stackSize--;

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
         stack.push(result);
         stackSize++;
      } else {
         throw std::runtime_error("❌ Token non valide");
      }
   }

   if (stack.size() != 1) {
      throw std::runtime_error(
          "❌ Expression RPN invalide : la pile ne contient pas un seul "
          "résultat");
   }

   return stack.top();
}
