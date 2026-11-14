#pragma once

#include <random>
#include <string>
#include <vector>

#include "Coup.hpp"

class Strategie {
public:
    virtual ~Strategie() = default;
    virtual Coup choisir(const std::vector<Coup>& mesCoups,
                         const std::vector<Coup>& coupsAdverses,
                         std::mt19937& rng) = 0;
    virtual void reset() {}
    virtual std::string nom() const = 0;
};
