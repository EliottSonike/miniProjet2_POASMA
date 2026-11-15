#include "Moteur.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

int gain(Coup monCoup, Coup coupAdversaire, const Gains& g){
    if(monCoup == Coup::C){
        if(coupAdversaire == Coup::C){
            return g.R;
        }
        else{
            return g.S;
        }
    }
    else {
        if(coupAdversaire == Coup::C){
            return g.T;
        }
        else{
            return g.P;
        }   
    }
}

std::pair<int, int> partie(Strategie& s1, Strategie& s2, int nbTours, const Gains& gains, std::mt19937& rng) {
    
    std::vector<Coup> listeCoupsS1;
    std::vector<Coup> listeCoupsS2;
    int scoreS1 = 0;
    int scoreS2 = 0;

    for (int i = 0; i < nbTours; i++){
        Coup coupS1 = s1.choisir(listeCoupsS1, listeCoupsS2, rng);
        Coup coupS2 = s2.choisir(listeCoupsS2, listeCoupsS1, rng);
        scoreS1 += gain(coupS1, coupS2, gains);
        scoreS2 += gain(coupS2, coupS1, gains);
        listeCoupsS1.push_back(coupS1);
        listeCoupsS2.push_back(coupS2);
    }
    return {scoreS1,scoreS2};
}

std::pair<int, int> match(Strategie& s1, Strategie& s2, int nbParties, int nbTours, const Gains& gains, std::mt19937& rng) {
    int totalS1 = 0;
    int totalS2 = 0;
    for (int i = 0; i<nbParties; i++){
        s1.reset();
        s2.reset();
        std::pair<int, int> game = partie(s1, s2, nbTours, gains, rng);
        totalS1 += game.first;
        totalS2 += game.second;
    }
    return {totalS1,totalS2};
}

std::vector<std::pair<std::string, int>> tournoi(std::vector<Strategie*>& population, int nbParties, int nbTours, const Gains& gains, std::mt19937& rng) {
    // Une case de la population = un joueur
    // Deux joueurs peuvent avoir la meme strategie, mais un joueur ne joue jamais contre lui-meme.
    size_t n = population.size(); // Nombre de joueurs dans la population
    std::vector<int> scores(n, 0); // Initialisation des scores à zéro

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) { // chaque paire de joueurs differents, une seule fois
            std::pair<int, int> result = match(*population[i], *population[j], nbParties, nbTours, gains, rng);
            std::cout << "Match entre " << population[i]->nom() << " et " << population[j]->nom() << " : "
                      << result.first << " - " << result.second << std::endl;
            scores[i] += result.first; // Ajouter le score du joueur i
            scores[j] += result.second; // Ajouter le score du joueur j
        }
    }
    std::vector<std::pair<std::string, int>> classement;
    for (size_t i = 0; i < n; i++) {
        classement.push_back({population[i]->nom(), scores[i]});
    }
    std::sort(classement.begin(), classement.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });
    return classement;
}

void afficherClassement(const std::vector<std::pair<std::string, int>>& classement) {
    std::cout << "Classement du tournoi :" << std::endl;
    for (const auto& joueur : classement) {
        std::cout << std::setw(20) << std::left << joueur.first << " : " << std::setw(5) << std::right << joueur.second << " points" << std::endl;
    }
}
