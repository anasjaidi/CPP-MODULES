#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : healthPoints(10), energyPoints(10), attackDamage(0)
{
  std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string &name) : name(name), healthPoints(10), energyPoints(10), attackDamage(0)
{
  std::cout << "String constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  energyPoints = src.getEnergy();
  healthPoints = src.getHealth();
  name = src.getName();
  attackDamage = src.getAttack();
  return *this;
}

void ClapTrap::setEnergy(int &a)
{
  attackDamage = a;
}

void ClapTrap::setAttack(int &a)
{
  energyPoints = a;
}

void ClapTrap::setHealth(int &a)
{
  healthPoints = a;
}

void ClapTrap::setName(std::string &name)
{
  this->name = name;
}

int ClapTrap::getAttack(void) const
{
  return (
      attackDamage);
}

int ClapTrap::getEnergy(void) const
{
  return (
      energyPoints);
}

int ClapTrap::getHealth(void) const
{
  return (
      healthPoints);
}

std::string ClapTrap::getName(void) const
{
  return name;
}

void ClapTrap::attack(const std::string &target)
{
  if (!energyPoints || !healthPoints)
  {
    std::cout << "ClapTrap " << name << " can't attack " << target << "!\n";
    return;
  }
  energyPoints--;
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (!energyPoints || !healthPoints)
  {
    std::cout << "ClapTrap " << name << " can't be repaired "
              << "!\n";
    return;
  }
  energyPoints--;
  std::cout << "ClapTrap " << name << " repaired with " << amount << " amount of health points!\n";
  healthPoints += amount;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << "ClapTrap " << name << " takes " << amount << " amount of damage!\n";
  healthPoints -= healthPoints >= (int)amount ? amount : healthPoints;
}