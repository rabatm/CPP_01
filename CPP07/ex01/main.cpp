#include <iostream>
#include "iter.cpp"

int main() {
    int intArray[] = {42, 69, 1337, 8008, 9001};
    std::string strArray[] = {"Pikachu", "Charmander", "Squirtle", "Bulbasaur", "Eevee"};

    printTitle("Des numeroooo : ", RED);
    iter(intArray, 5, myPrint<int>);
    std::cout << std::endl;

	printTitle("Des pokemons : ", GREEN);
    iter(strArray, 5, myPrint<std::string>);
    std::cout << std::endl;

    return 0;
}
