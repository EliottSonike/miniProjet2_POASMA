// RANDOM : joue C ou D au hasard, avec une chance sur deux.
// Sert de temoin : une strategie qui ne tient aucun compte de l'historique.
// Utilise le generateur rng passe en parametre (graine fixee) pour que le tournoi soit reproductible.

#include "Random.hpp"

Coup Random::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {

    if(rng() % 2 == 0) {
        return Coup::C;
    } else {
        return Coup::D;
    }
}

std::string Random::nom() const {
    return "RANDOM";
}
