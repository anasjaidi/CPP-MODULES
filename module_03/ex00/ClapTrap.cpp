#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : energyPoints(10), attackDamage(0), healthPoints(10)
{
  std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string &name) : energyPoints(10), attackDamage(0), healthPoints(10), name(name)
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

void ClapTrap::setEnergy(int &a) {
  attackDamage = a;
}

void ClapTrap::setAttack(int &a) {
  energyPoints = a;
}

void ClapTrap::setHealth(int &a) {
  healthPoints = a;
}

void ClapTrap::setName(std::string &name) {
  this->name = name;
}

int ClapTrap::getAttack(void) const {
  return (
    attackDamage
  );
}

int ClapTrap::getEnergy(void) const {
  return (
    energyPoints
  );
}

int ClapTrap::getHealth(void) const {
  return (
    healthPoints
  );
}

std::string ClapTrap::getName(void) const {
  return name;
}

