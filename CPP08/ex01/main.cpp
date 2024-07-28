#include "Span.hpp"

void addNumbersWithAddnumbers()
{
    std::cout << "🧪 Test avec addNumbers" << std::endl;
    Span sp = Span(6);
    int arr[] = {6, 3, 17, 9, 11, 42};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    sp.addNumbers(v.begin(), v.end());
    std::cout << "🔖 Plus petite distance: " << sp.shortestSpan() << std::endl;
    std::cout << "🚛 Plus grande distance: " << sp.longestSpan() << std::endl;
}

void addNumbersWithAddnumber()
{
	std::cout << "🧪 Test avec addNumber" << std::endl;
	Span sp = Span(6);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(42);
	std::cout << "🔖 Plus petite distance" << sp.shortestSpan() << std::endl;
	std::cout << "🚛 Plus grande distance" << sp.longestSpan() << std::endl;
}


int main()
{	
	addNumbersWithAddnumbers();
	addNumbersWithAddnumber();
	return 0;
}