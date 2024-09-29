/* 2-D random walk generator
With a user-defined number of particles and number of steps, it outputs the resulting random walk. A bounded box can be implemented to restrict the walks.*/

#include <iostream>
#include "lib/Particle.hpp"
#include <string>

int main(int argc, char* argv[])
{

    int step_number, particle_number;

    std::cout << "Enter the number of particles: ";
    std::cin >> particle_number;
    std::cout << "Enter the number of steps: ";
    std::cin >> step_number;

    for (int i = 1; i <= particle_number; i++)
    {
        Particle part(step_number);
        //part.set_bounds(-100, 100, 100, -100);
        part.random_walk();
        part.write_output("particle"+std::to_string(i)+"-rw.dat");
        //std::cout << part;
    }

    // Calculate mean square displacement over 1000 random walks for an increasing number of steps 1 to 1000:
    
    int walks = 1000, max_steps = 1000;

    for (int n = 1; n <= max_steps; n++)
    {
        Particle part(n);
        double MSD = 0;

        for (int i = 0; i < walks; i++)
        {
            part.random_walk();
            MSD += part.end_displacement();
        }

        std::cout << MSD / walks << "\n"; 
    }
}
