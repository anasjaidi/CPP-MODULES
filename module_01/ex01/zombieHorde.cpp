#include "./Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
  Zombie *zombies = new Zombie[N];
  for (size_t i = 0; i < (size_t)N; i++)
    zombies[i].set_name(
      name + " NO: " + std::to_string(i + 1)
    );
    return (zombies);
}