#include "Particle.hpp"
#include <fstream>
#include <cmath>
#include <cassert>

Particle::Particle(int steps) : step_number(steps)
{
    assert(step_number > 0);

    position = new int[step_number];
}

Particle::~Particle()
{
    delete position;
}

void Particle::random_walk()
{
    rng_init();
    std::uniform_int_distribution<int> unif(0, 1);

    int previous_step = 0;

    for (int step = 0; step < step_number; step++)
    {
        int new_step = unif(rng) > 0.5 ? previous_step - 1: previous_step + 1;
        previous_step = position[step] = new_step;
    }
}

void Particle::write_output(std::string filename="random-walk.dat")
{
    std::ofstream outputfile;
    outputfile.open(filename);

    for (int i = 0; i < step_number; i++)
    {
        outputfile << i << " " << position[i] << "\n";
    }

    outputfile.close();

    std::cout << "Output file written." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Particle &part)
{
    out << "Time history: ";

    for (int step = 0; step < part.step_number; step++)
    {
        out << part.position[step] << " ";
    }

    out << "\n";

    return out;
}