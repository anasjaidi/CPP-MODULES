#include "./Zombie.hpp"


void  Zombie::announce(void)
{
  std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void  Zombie::set_name(std::string name)
{
  this->name = name;
}

Zombie::Zombie()
{
  
}

Zombie::Zombie(std::string name)
{
  this->name = name;
}

Zombie::~Zombie()
{
  std::cout << this->name<< std::endl;
}