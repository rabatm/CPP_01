#include "ScalarConverter.hpp"

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a value to convert (or 'kisskiss' to quit): ";
        std::getline(std::cin, input);  // Lire l'entrée utilisateur

        if (input == "kisskiss") {
            break;  // Sortir de la boucle si l'utilisateur entre "byebye"
        }

        ScalarConverter::convert(input);  // Appeler la méthode convert avec l'entrée utilisateur
    }

    return 0;
}