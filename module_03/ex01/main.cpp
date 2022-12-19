#include "./ScavTrap.hpp"

int main()
{
  std::string s = "anas";
  ClapTrap a = ClapTrap(s);
  std::cout << "a: " << a.getEnergy() << std::endl;
  std::cout << "a: " << a.getAttack() << std::endl;
  std::cout << "a: " << a.getHealth() << std::endl;
  std::cout << "a: " << a.getName() << std::endl;
  s = "jaidi";
  ScavTrap b(s);
  std::cout << "b: " << b.getEnergy() << std::endl;
  std::cout << "b: " << b.getAttack() << std::endl;
  std::cout << "b: " << b.getHealth() << std::endl;
  std::cout << "b: " << b.getName() << std::endl;
  a.attack("jaidi");
  a.takeDamage(9);
  a.beRepaired(8);
  std::cout << "a: " << a.getEnergy() << std::endl;
  std::cout << "a: " << a.getAttack() << std::endl;
  std::cout << "a: " << a.getHealth() << std::endl;
  std::cout << "a: " << a.getName() << std::endl;
  b.attack("jaidi");
  b.takeDamage(9);
  b.beRepaired(8);
  std::cout << "b: " << b.getEnergy() << std::endl;
  std::cout << "b: " << b.getAttack() << std::endl;
  std::cout << "b: " << b.getHealth() << std::endl;
  std::cout << "b: " << b.getName() << std::endl;
}