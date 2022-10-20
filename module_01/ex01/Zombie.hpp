# pragma once 

# include <iostream>
# include <string>

class Zombie {
  private:
    std::string name;
  public:
    Zombie();
    Zombie(std::string);
    void  set_name(std::string);
    ~Zombie();
    void announce(void);
};

Zombie* zombieHorde( int N, std::string name );