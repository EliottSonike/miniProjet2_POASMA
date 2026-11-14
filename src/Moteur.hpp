#pragma once

#include <random>
#include <string>
#include <utility>
#include <vector>

#include "Strategie.hpp"

struct Gains {
    int T, R, P, S;
};

std::pair<int, int> partie(Strategie& s1, Strategie& s2, int nbTours, const Gains& gains, std::mt19937& rng);

std::pair<int, int> match(Strategie& s1, Strategie& s2, int nbParties, int nbTours, const Gains& gains, std::mt19937& rng);

std::vector<std::pair<std::string, int>> tournoi(std::vector<Strategie*>& population, int nbParties, int nbTours, const Gains& gains, std::mt19937& rng);

void afficherClassement(const std::vector<std::pair<std::string, int>>& classement);
