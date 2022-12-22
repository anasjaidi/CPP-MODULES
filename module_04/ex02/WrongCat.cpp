#include "./WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
  type = "Wrong Cat";
  std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
  std::cout << "WrongCat Type constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
  std::cout << "WrongCat Copy assignment operator called" << std::endl;
  type = src.type;
  return *this;
}

WrongCat::WrongCat(const WrongCat &src)
{
  std::cout << "WrongCat Copy constructor called" << std::endl;
  *this = src;
}

void WrongCat::makeSound() const
{
  std::cout << "WrongCat SOUND\n";
}