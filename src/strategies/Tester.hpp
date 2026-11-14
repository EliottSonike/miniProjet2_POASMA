#pragma once

#include "../Strategie.hpp"

class Tester : public Strategie {
public:
    Coup choisir(const std::vector<Coup>& mesCoups, const std::vector<Coup>& coupsAdverses, std::mt19937& rng) override;
    std::string nom() const override;
};
