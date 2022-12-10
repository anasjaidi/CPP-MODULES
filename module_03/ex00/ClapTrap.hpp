#include <iostream>

class ClapTrap
{
private:
  std::string name;
  int healthPoints;
  int energyPoints;
  int attackDamage;
public:
  public:
  ClapTrap();
  ClapTrap(std::string &);
  ClapTrap(const ClapTrap &ClapTrap);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &);
  void setAttack(int&);
  void setHealth(int&);
  void setEnergy(int&);
  void setName(std::string&);
  int getEnergy(void) const;
  int getHealth(void) const;
  int getAttack(void) const;
  std::string  getName(void) const;
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};
