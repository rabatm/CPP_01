#include "PmergeMe.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <sstream>

// Constructeur par défaut
PmergeMe::PmergeMe() {}

// Destructeur
PmergeMe::~PmergeMe() {}

// Constructeur de copie
PmergeMe::PmergeMe(const PmergeMe& other)
    : intVector(other.intVector), intDeque(other.intDeque) {}

// Opérateur d'assignation
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
   if (this != &other) {
      intVector = other.intVector;
      intDeque = other.intDeque;
   }
   return *this;
}

void PmergeMe::processArgs(int argc, char* argv[]) {
   for (int i = 1; i < argc; ++i) {
      int value;
      std::stringstream ss(argv[i]);
      ss >> value;
      if (ss.fail() || value <= 0) {
         std::cerr << "Error" << std::endl;
         exit(1);
      }
      intVector.push_back(value);
      if (!this->checkDoublons()) {
         throw std::runtime_error("😿 Error: duplicate value");
         return;
      }
      intDeque.push_back(value);
   }
}

template <typename Container>
void PmergeMe::insertionSort(Container& container) {
   for (typename Container::iterator it = container.begin();
        it != container.end(); ++it) {
      typename Container::iterator j = it;
      while (j > container.begin() && *j < *(j - 1)) {
         std::swap(*j, *(j - 1));
         --j;
      }
   }
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
   if (container.size() < 2) {
      return;
   }
   if (container.size() == 2) {
      if (container[0] > container[1]) {
         std::swap(container[0], container[1]);
      }
      return;
   }
   if (container.size() <= 10) {
      insertionSort(container);
   } else {
      Container left(container.begin(),
                     container.begin() + container.size() / 2);
      Container right(container.begin() + container.size() / 2,
                      container.end());
      mergeInsertSort(left);
      mergeInsertSort(right);
      std::merge(left.begin(), left.end(), right.begin(), right.end(),
                 container.begin());
   }
}

template <typename Container>
void PmergeMe::printContainer(const Container& container,
                              const std::string& message) const {
   std::cout << message;
   for (typename Container::const_iterator it = container.begin();
        it != container.end(); ++it) {
      std::cout << *it << " ";
   }
   std::cout << std::endl;
}

template <typename Container>
double PmergeMe::timeMergeInsertSort(Container& container) {
   struct timeval start, end;
   gettimeofday(&start, NULL);
   mergeInsertSort(container);
   gettimeofday(&end, NULL);
   double startTime = start.tv_sec + (start.tv_usec / 1000000.0);
   double endTime = end.tv_sec + (end.tv_usec / 1000000.0);
   double duration = (endTime - startTime) * 1000000.0;

   return duration;
}

void PmergeMe::sortAndPrint() {
   printContainer(intVector, "before : ");
   double timeVector = timeMergeInsertSort(intVector);
   double timeDeque = timeMergeInsertSort(intDeque);
   printContainer(intDeque, "After : ");
   std::cout << "Time to process a range of " << intDeque.size()
             << " elements with std::deque  : " << timeDeque << " us"
             << std::endl;
   std::cout << "Time to process a range of " << intVector.size()
             << " elements with std::vector : " << timeVector << " us"
             << std::endl;
}

bool PmergeMe::checkDoublons() {
   std::set<int> seen;
   for (std::vector<int>::const_iterator it = intVector.begin();
        it != intVector.end(); ++it) {
      if (seen.find(*it) != seen.end()) {
         return true;  // Doublon trouvé
      }
      seen.insert(*it);
   }
   return false;  // Aucun doublon trouvé
}