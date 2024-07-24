#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

class Complex {
public:
    int a;
    std::string b;
    Complex() : a(0), b("default") {}
    Complex(int a, std::string b) : a(a), b(b) {}
    bool operator==(const Complex &other) const {
        return (a == other.a && b == other.b);
    }
    bool operator!=(const Complex &other) const {
        return !(*this == other);
    }
};

void testIntArray() {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror;
}

void testComplexArray() {
    Array<Complex> complexArray(5);
    Complex c1(1, "one");
    Complex c2(2, "two");
    Complex c3(3, "three");

    complexArray[0] = c1;
    complexArray[1] = c2;
    complexArray[2] = c3;

    std::cout << "Complex array values:" << std::endl;
    for (unsigned int i = 0; i < complexArray.size(); ++i) {
        std::cout << "complexArray[" << i << "] = (" << complexArray[i].a << ", " << complexArray[i].b << ")" << std::endl;
    }

    // Testing copy and assignment
    Array<Complex> copiedArray = complexArray;
    if (copiedArray[0] != c1 || copiedArray[1] != c2 || copiedArray[2] != c3) {
        std::cerr << "Copy assignment failed for complex array!" << std::endl;
        return;
    }

    try {
        complexArray[10] = Complex(10, "ten");
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

int main(int, char**) {
    std::cout << "Testing int array..." << std::endl;
    testIntArray();

    std::cout << "Testing complex array..." << std::endl;
    testComplexArray();

    std::cout << "All tests completed." << std::endl;
    return 0;
}
