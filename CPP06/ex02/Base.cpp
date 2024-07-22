#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate(void)
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(NULL)); // Initialise la graine une seule fois
        initialized = true;
    }

    int i = rand() % 3;
    
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        throw std::bad_cast();
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    throw std::bad_cast();
}