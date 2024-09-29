#ifndef PARTICLEHEADERHPP
#define PARTICLEHEADERHPP

#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <vector>

// Random engine and seeding (see https://stackoverflow.com/questions/7114043/random-number-generation-in-c11-how-to-generate-how-does-it-work).

class Particle
{
private:
    std::vector<std::vector<int>> position;
    // int **position;
    int step_number;
    int left_bound, right_bound, upper_bound, lower_bound;
    std::mt19937 rng; // Mersenne Twister RNG

public:
    Particle(int);
    //~Particle();
    void rng_init();
    void set_bounds(int, int, int, int);
    bool check_left_bound(int x) 
    {
        return x >= left_bound;
    };
    bool check_upper_bound(int y)
    {
        return y <= upper_bound;
    };
    bool check_right_bound(int x)
    {
        return x <= right_bound;
    };
    bool check_lower_bound(int y)
    {
        return y >= lower_bound;
    };
    void random_walk();
    void write_output(std::string) const;
    double end_displacement() const 
    {
        return std::sqrt(position[step_number-1][0] * position[step_number-1][0] + position[step_number-1][1] * position[step_number-1][1]);
    };
    friend std::ostream &operator<<(std::ostream &, const Particle&);
};

#endif