#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data originalData = {1, "superMega Test", 3.314f};

    // Sérialiser l'adresse de l'objet originalData
    uintptr_t raw = Serializer::serialize(&originalData);

    // Désérialiser la valeur brute pour obtenir un pointeur vers Data
    Data* deserializedData = Serializer::deserialize(raw);

    // Vérifier que le pointeur désérialisé est égal au pointeur original
    if (deserializedData == &originalData) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    // Afficher les valeurs pour vérification visuelle
    std::cout << "Original Data: " << originalData.id << ", " << originalData.name << ", " << originalData.value << std::endl;
    std::cout << "Deserialized Data: " << deserializedData->id << ", " << deserializedData->name << ", " << deserializedData->value << std::endl;

    return 0;
}