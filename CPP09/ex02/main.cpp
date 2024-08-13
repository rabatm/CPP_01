#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
   PmergeMe pmergeMe;
   pmergeMe.processArgs(argc, argv);
   pmergeMe.sortAndPrint();
   return 0;
}