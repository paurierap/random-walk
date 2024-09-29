#ifndef PARTICLEHEADERHPP
#define PARTICLEHEADERHPP

#include <iostream>
#include <random>
#include <string>

// Random engine and seeding (see https://stackoverflow.com/questions/7114043/random-number-generation-in-c11-how-to-generate-how-does-it-work).

class Particle
{
private:
    int *position;
    int step_number;
    std::mt19937 rng; // Mersenne Twister RNG

public:
    Particle(int);
    ~Particle();
    void rng_init() {rng.seed(time(0));};
    void random_walk();
    void write_output(std::string);
    friend std::ostream &operator<<(std::ostream &, const Particle&);
};

#endif