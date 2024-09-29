#include "Particle.hpp"
#include <fstream>
#include <cmath>
#include <cassert>

Particle::Particle(int steps) : step_number(steps), left_bound(-steps), right_bound(steps), upper_bound(steps), lower_bound(-steps)
{
    assert(step_number > 0);

    position = std::vector<std::vector<int>>(step_number);
    // position[i] = new int *[step_number];

    for (int i = 0; i < step_number; i++)
    {
        position[i] = std::vector<int>(2);
        // position[i] = new int[2];
    }
}

/*Particle::~Particle()
{
    for (int i = 0; i < step_number; i++)
    {
        delete[] position[i];
    }

    delete[] position;
}*/

void Particle::rng_init()
{
    std::random_device rd;
    rng.seed(rd());
}

void Particle::set_bounds(int left, int right, int upper, int lower)
{
    assert(left < right && lower < upper);

    if (left == right || upper == lower) {std::cout << "Try 1-D case!";};

    left_bound = left;
    right_bound = right;
    upper_bound = upper;
    lower_bound = lower;
}

void Particle::random_walk()
{
    rng_init();

    // 4 differents steps to be taken at each intersection: back, forward, up and down:
    std::uniform_int_distribution<int> unif(0, 3);

    int previous_step_x = 0;
    int previous_step_y = 0;

    for (int i = 0; i < step_number; i++)
    {
        switch (unif(rng))
        {

        // Move back:
        case 0:
            previous_step_x--;
            if (!check_left_bound(previous_step_x)) {previous_step_x++;}
            position[i][0] = previous_step_x;
            position[i][1] = previous_step_y;
            break;
        
        // Move forward:
        case 1:
            previous_step_x++;
            if (!check_right_bound(previous_step_x)) {previous_step_x--;}
            position[i][0] = previous_step_x;
            position[i][1] = previous_step_y;
            break;

        // Move up:
        case 2:
            previous_step_y++;
            if (!check_upper_bound(previous_step_y)) {previous_step_y--;}
            position[i][0] = previous_step_x;
            position[i][1] = previous_step_y;
            break;

        // Move down:
        case 3:
            previous_step_y--;
            if (!check_lower_bound(previous_step_y)) {previous_step_y++;}
            position[i][0] = previous_step_x;
            position[i][1] = previous_step_y;
            break;

        default:
            break;
        }
    }
}

void Particle::write_output(std::string filename="random-walk.dat") const
{
    std::ofstream outputfile;
    outputfile.open(filename);

    for (int i = 0; i < step_number; i++)
    {
        outputfile << i << " " << position[i][0] << " " << position[i][1] << "\n";
    }

    outputfile.close();

    std::cout << "Output file written." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Particle &part)
{
    out << "Time history: ";

    for (int i = 0; i < part.step_number; i++)
    {
        out << "(" << part.position[i][0] << "," << part.position[i][1] << ") ";
    }

    out << "\n";

    return out;
}