#include "./Zombie.hpp"


int main()
{
  Zombie *zs = zombieHorde(5, "anas jaidi");
  for (size_t i = 0; i < 5; i++)
    zs[i].announce();
  delete [] zs;
}