#include "backgammon/version.hpp"

#include <iostream>

int main()
{
    std::cout << "Backgammon v" << backgammon::version() << '\n';
    return 0;
}
