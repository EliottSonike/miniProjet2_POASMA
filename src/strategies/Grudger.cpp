// GRUDGER (rancunier, Friedman) : coopere tant que l'adversaire n'a jamais trahi,
// puis trahit (D) pour toujours des que l'adversaire a joue D une seule fois.

#include "Grudger.hpp"
#include <algorithm>

Coup Grudger::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    if (std::find(coupsAdverses.begin(), coupsAdverses.end(), Coup::D) != coupsAdverses.end()) {
        return Coup::D;
    }
    return Coup::C;
}

std::string Grudger::nom() const {
    return "GRUDGER";
}
