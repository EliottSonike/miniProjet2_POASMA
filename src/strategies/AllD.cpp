#include "AllD.hpp"

Coup AllD::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    // retourne tout le temps D
    return Coup::D;
}

std::string AllD::nom() const {
    return "ALL-D";
}
