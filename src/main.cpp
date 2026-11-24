#include "backgammon/game.hpp"

#include <iostream>
#include <random>

int main()
{
    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<int> die(1, 6);
    return backgammon::runGame(std::cin, std::cout, [&] { return die(rng); });
}
