#include "Base.hpp"


std::string generate_random_name_from_array() {
    const std::string names[] = {
        "Douglas", // Adams, l'auteur de "The Hitchhiker's Guide to the Galaxy"
        "Marvin",  // Le robot paranoïaque dans "The Hitchhiker's Guide to the Galaxy"
        "Zaphod",  // Zaphod Beeblebrox, un personnage de "The Hitchhiker's Guide to the Galaxy"
        "Arthur",  // Arthur Dent, le protagoniste de "The Hitchhiker's Guide to the Galaxy"
        "Ford",    // Ford Prefect, un personnage de "The Hitchhiker's Guide to the Galaxy"
        "Trillian",// Tricia McMillan, un personnage de "The Hitchhiker's Guide to the Galaxy"
        "Answer",
		"DeepThought", // L'ordinateur qui calcule la réponse à la grande question
    	"Answer", // La réponse à la grande question sur la vie, l'univers et tout le reste (42)
    	"Earth", // L'ordinateur conçu pour trouver la question ultime, dont la réponse est 42
    	"Slartibartfast", // Le concepteur des fjords sur Terre dans "The Hitchhiker's Guide to the Galaxy"
    	"Magrathea", // La planète où les ordinateurs comme la Terre sont conçus
    	"LifeUniverseEverything"    // Référence à "la réponse à la grande question sur la vie, l'univers et tout le reste"
    };
    const int namesCount = sizeof(names) / sizeof(names[0]); // Calculer le nombre d'éléments dans le tableau
    int randomIndex = rand() % namesCount;
    return names[randomIndex];
}

Base* generate_and_display() {
    std::string gene_name = generate_random_name_from_array();
    Base *current_base = generate();
    std::cout << "Identify de " << gene_name << ": " << std::endl;
    identify(current_base);
    identify(*current_base);

    return current_base;
}

int main() {
	srand(time(NULL)); 
    
	Base *la_base = generate_and_display();
    Base *pas_la_base = generate_and_display();
    Base *pas_la_base_mais = generate_and_display();

    delete la_base;
    delete pas_la_base;
    delete pas_la_base_mais;
    return 0;
}