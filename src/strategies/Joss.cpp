// JOSS : joue comme TIT-FOR-TAT, mais remplace une cooperation (C) par une trahison (D)
// une fois sur dix, de facon deterministe

#include "Joss.hpp"

Coup Joss::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    if (coupsAdverses.empty()) {
        return Coup::C;
    } else if (coupsAdverses.back() == Coup::D) {
        return Coup::D;
    } else if (mesCoups.size() % 10 == 9) {
        return Coup::D;
    }
    return Coup::C;
}

std::string Joss::nom() const {
    return "JOSS";
}
