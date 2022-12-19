# include "./ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
  std::cout << "ScavTrap Default constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
  std::cout << "ScavTrap String constructor called" << std::endl;
  energyPoints = 50;
  attackDamage = 20;
  healthPoints = 100;
}

ScavTrap:: ~ScavTrap()
{
  std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
  if (!energyPoints || !healthPoints)
  {
    std::cout << "ScavTrap " << name << " can't attack " << target << "!\n";
    return;
  }
  energyPoints--;
  std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << name << " is now in Gate Keeper mode\n";
}