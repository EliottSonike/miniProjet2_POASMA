#include "Moteur.hpp"
#include "Strategies.hpp"
#include <iostream>
#include <string>

// Affiche la liste des tournois disponibles
void afficherUsage() {
    std::cout << "Usage : tournoi.exe <mode>" << std::endl;
    std::cout << "  diapo    : test du CM page 68 (TFT, TFT, ALL-D), 1 partie de 10 tours" << std::endl;
    std::cout << "  etape1   : tournoi d'Axelrod, 5 strategies du cours, 5 parties de 200 tours" << std::endl;
    std::cout << "  etape2   : 7 strategies (+ GRUDGER et WSLS), 5 parties de 200 tours" << std::endl;
    std::cout << "  bruit    : etape2 avec bruit de 5 %" << std::endl;
    std::cout << "  horizon  : etape2 avec horizon inconnu (w = 0,995)" << std::endl;
    std::cout << "  combine  : bonus, etape2 avec bruit 5 % + horizon inconnu" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        afficherUsage();
        return 1;
    }
    std::string mode = argv[1];

    // Une seule graine, et un seul tournoi par execution :
    // chaque tournoi redonne toujours le meme resultat, quel que soit l'ordre des lancements
    std::mt19937 rng(2052004);
    Gains gains{5, 3, 2, 0};
    Options options; // par defaut : pas de bruit, horizon connu

    // Strategies sans etat interne : un meme objet peut servir dans plusieurs populations
    TitForTat tft;
    TitForTat tft2; // deuxieme joueur TFT pour le test de la diapo
    AllD alld;
    Random random;
    Tester tester;
    Joss joss;
    Grudger grudger;
    WSLS wsls;

    std::vector<Strategie*> populationCours = { &tft, &alld, &random, &tester, &joss };
    std::vector<Strategie*> populationElargie = { &tft, &alld, &random, &tester, &joss, &grudger, &wsls };

    if (mode == "diapo") {
        std::vector<Strategie*> population = { &tft, &tft2, &alld };
        afficherClassement(tournoi(population, 1, 10, gains, rng, options));
    } else if (mode == "etape1") {
        afficherClassement(tournoi(populationCours, 5, 200, gains, rng, options));
    } else if (mode == "etape2") {
        afficherClassement(tournoi(populationElargie, 5, 200, gains, rng, options));
    } else if (mode == "bruit") {
        options.bruit = 0.05;
        afficherClassement(tournoi(populationElargie, 5, 200, gains, rng, options));
    } else if (mode == "horizon") {
        options.w = 0.995;
        afficherClassement(tournoi(populationElargie, 5, 200, gains, rng, options));
    } else if (mode == "combine") {
        options.bruit = 0.05;
        options.w = 0.995;
        afficherClassement(tournoi(populationElargie, 5, 200, gains, rng, options));
    } else {
        std::cout << "Mode inconnu : " << mode << std::endl;
        afficherUsage();
        return 1;
    }
    return 0;
}
