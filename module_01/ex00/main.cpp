#include "./Zombie.hpp"


int main()
{
  Zombie *zm = newZombie("anas jaidi");
  zm->announce();
  randomChump("robin hood");
  delete zm;
}