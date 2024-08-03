#include <iostream>
#include "lib/Particle.hpp"

int main(int argc, char* argv[])
{
    int step_number;
    std::cout << "Enter the number of steps: ";
    std::cin >> step_number;

    Particle part(step_number);
    part.random_walk();
    std::cout << part;
}
