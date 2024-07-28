#include <iostream>
#include "MutantStack.hpp"

void testMutantStack() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl; // Should print 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Should print 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Elements in stack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}

int main() {
    testMutantStack();
    return 0;
}