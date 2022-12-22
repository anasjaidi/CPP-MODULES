#pragma once 

# include <iostream>

class Animal {
  protected:
    std::string type;
  public:
    Animal();
    Animal(const std::string&);
    virtual ~Animal();
    Animal(const Animal &);
    Animal &operator = (const Animal &);
    virtual void makeSound() const = 0;
    void setType(const std::string &);
    std::string getType() const;
};