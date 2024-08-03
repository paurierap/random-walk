#ifndef PARTICLEHEADERHPP
#define PARTICLEHEADERHPP

#include <iostream>

class Particle
{
private:
    int *position;
    int step_number;

public:
    Particle(int);
    ~Particle();
    void random_walk();
    friend std::ostream &operator<<(std::ostream &, const Particle&);
};

#endif