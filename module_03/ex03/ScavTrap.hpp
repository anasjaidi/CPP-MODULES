#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
  ScavTrap();
  ScavTrap(std::string &name);
  void attack(const std::string &target);
  void guardGate();
  ~ScavTrap();
};