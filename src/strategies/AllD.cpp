// ALL-D : trahit (D) a chaque tour, quoi que fasse l'adversaire.
// Strategie "rationnelle" obtenue par recurrence a rebours sur un nombre de tours connu.
// Ne perd jamais un duel, mais se prive des 3 points de la cooperation mutuelle.

#include "AllD.hpp"

Coup AllD::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    // retourne tout le temps D
    return Coup::D;
}

std::string AllD::nom() const {
    return "ALL-D";
}
