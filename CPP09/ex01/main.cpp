#include <cstdlib>
#include <iostream>
#include <string>
#include "RPNCalculator.hpp"

int main(int argc, char* argv[]) {
   if (argc < 2 || argc > 2) {
      std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
      return 1;
   }

   RPNCalculator calc;
   std::istringstream iss(argv[1]);
   std::string token;
   std::stack<std::string> tempStack;
   try {
      while (iss >> token) {
         tempStack.push(token);
      }
      while (!tempStack.empty()) {
         calc.pushToken(tempStack.top());
         tempStack.pop();
      }
      std::cout << calc.evaluate() << std::endl;
   } catch (const std::invalid_argument& e) {
      std::cerr << "Error: " << e.what() << std::endl;
   } catch (const std::exception& e) {
      std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
   }
   return 0;
}