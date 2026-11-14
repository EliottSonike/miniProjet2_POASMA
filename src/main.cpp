#include "Moteur.hpp"
#include "Strategies.hpp"
#include "strategies/AllD.hpp"
#include "strategies/TitForTat.hpp"
#include <iostream>

int main() {
    std::mt19937 rng(2052004);
    Gains gains{5, 3, 2,0};
    TitForTat tft1;
    TitForTat tft2;
    AllD alld;

    //test partie

    //std::pair<int, int> test = partie(tft,alld,10,gains,rng);
    //std::cout << "tft : " << test.first << std::endl;
    //std::cout << "alld : " << test.second << std::endl;

    //test match
    //std::pair<int, int> matchTest = match(tft,alld,5,10,gains,rng);
    //std::cout << "match test : " << std::endl;
    //std::cout << "tft : " << matchTest.first << std::endl;
    //std::cout << "alld : " << matchTest.second << std::endl;

    //test tournoi
    std::vector<Strategie*> population = { &tft1, &tft2, &alld };
    afficherClassement(tournoi(population, 5, 10, gains, rng));
}
