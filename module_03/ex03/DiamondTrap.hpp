#pragma once 
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
private:
  std::string name;
public:
  DiamondTrap();
  DiamondTrap(const std::string &);
  ~DiamondTrap();
  using ScavTrap::attack;
  void whoAmI();
};

