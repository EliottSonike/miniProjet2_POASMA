// TESTER : trahit au premier tour pour sonder l'adversaire.
// - si l'adversaire riposte (D au tour 1), elle joue TIT-FOR-TAT a partir du tour 2 ;
// - sinon, elle l'exploite en repetant le cycle C, C, D a partir du tour 2.

#include "Tester.hpp"

Coup Tester::choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) {
    if (mesCoups.empty()) {
        return Coup::D;
    } else if (coupsAdverses[0] == Coup::D) {
        return coupsAdverses.back();
    } else {
        if (mesCoups.size() % 3 == 0) {
            return Coup::D;
        } else if (mesCoups.size() % 3 == 1) {
            return Coup::C;
        } else {
            return Coup::C;
        }
    }
}

std::string Tester::nom() const {
    return "TESTER";
}
