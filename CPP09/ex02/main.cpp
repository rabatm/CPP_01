#include <iostream>
#include <stdexcept>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
   try {
      PmergeMe pmergeMe;
      pmergeMe.processArgs(argc, argv);
      pmergeMe.sortAndPrint();
   } catch (const std::runtime_error& e) {
      std::cerr << e.what() << std::endl;
      return 1;
   } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return 1;
   } catch (...) {
      std::cerr << "😅 Unknown error occurred" << std::endl;
      return 1;
   }
   return 0;
}