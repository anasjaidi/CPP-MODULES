#pragma once

#include <iostream>

class WrongAnimal
{
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const std::string &);
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &);
  WrongAnimal &operator=(const WrongAnimal &);
  void makeSound() const;
  void setType(const std::string &);
  std::string getType() const;
};