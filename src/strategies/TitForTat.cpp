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
