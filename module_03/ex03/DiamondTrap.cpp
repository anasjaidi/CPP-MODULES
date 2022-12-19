# include "./DiamondTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
  std::cout << "DiamondTrap Default constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

DiamondTrap::DiamondTrap(const std::string &name) : FragTrap(name + "_clap_name")
{
  std::cout << "DiamondTrap String constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap Destructor called" << std::endl;
}
