// WSLS (Win-Stay, Lose-Shift, aussi appelee PAVLOV) : coopere au premier tour,
// puis garde son coup si le tour precedent a rapporte 5 ou 3 (gagne),
// et change de coup s'il a rapporte 2 ou 0 (perdu).

#include "WSLS.hpp"

Coup WSLS::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    if (mesCoups.empty()) {
        return Coup::C;
    }
    Coup dernierCoup = mesCoups.back();
    Coup dernierCoupAdverse = coupsAdverses.back();
    if (dernierCoupAdverse == Coup::C) {
        return dernierCoup; // Gagne reste sur le meme coup
    }
    return (dernierCoup == Coup::C) ? Coup::D : Coup::C; // Perdu change de coup
}

std::string WSLS::nom() const {
    return "WSLS";
}
