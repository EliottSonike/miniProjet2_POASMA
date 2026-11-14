// TIT-FOR-TAT (donnant-donnant) : coopere au premier tour,
// puis rejoue le coup de l'adversaire au tour precedent.
// Gagnante du tournoi d'Axelrod (1980) : gentille, rancuniere mais indulgente, et lisible.

#include "TitForTat.hpp"

Coup TitForTat::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    //
    if (coupsAdverses.empty()){
        return Coup::C;
    }
    else{
        return coupsAdverses.back();
    }
}

std::string TitForTat::nom() const {
    return "TIT-FOR-TAT";
}
