#include "easyfind.hpp"

void testEasyFindInt(const std::vector<int> &hector, const int toFind)
{
	try
	{
		std::cout << easyfind(hector, toFind) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
}

int main()
{
	std::vector<int> vec;

	for (int i = 0; i < 42; i++)
		vec.push_back(i);
	testEasyFindInt(vec, 5);
	testEasyFindInt(vec, 41);
	testEasyFindInt(vec, -41);
	testEasyFindInt(vec, -51);
	return 0;
}