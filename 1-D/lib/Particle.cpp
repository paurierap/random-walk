#include "Particle.hpp"
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
    int previous_step = 0;

    for (int step = 0; step < step_number; step++)
    {
        int new_step = std::fabs(std::rand() - 0.5) > 0 ? previous_step - 1: previous_step + 1;
        previous_step = position[step] = new_step;
    }
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