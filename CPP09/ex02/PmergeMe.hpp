#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
  public:
   PmergeMe();
   ~PmergeMe();
   PmergeMe(const PmergeMe& other);
   PmergeMe& operator=(const PmergeMe& other);

   void processArgs(int argc, char* argv[]);
   void sortAndPrint();

  private:
   template <typename Container>
   void mergeInsertSort(Container& container);

   std::vector<int> intVector;
   std::deque<int> intDeque;

   template <typename Container>
   void printContainer(const Container& container,
                       const std::string& message) const;

   template <typename Container>
   double timeMergeInsertSort(Container& container);
   template <typename Container>
   void insertionSort(Container& container);
};