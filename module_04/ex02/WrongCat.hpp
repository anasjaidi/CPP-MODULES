#pragma once
#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
  WrongCat();
  WrongCat(const std::string &);
  ~WrongCat();
  WrongCat(const WrongCat &);
  WrongCat &operator=(const WrongCat &);
  void makeSound() const;
};