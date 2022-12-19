#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
  std::cout << "FragTrap Default constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << "FragTrap String constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
  std::cout << "FragTrap " << name << " high fives\n";
}