#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
  std::cout << "Wrong animal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
  std::cout << "Wrong animal Type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "Wrong animal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
  std::cout << "Wrong animal Copy assignment operator called" << std::endl;
  type = src.type;
  return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{

  std::cout << "Wrong animal Copy constructor called" << std::endl;
  *this = src;
}

std::string WrongAnimal::getType() const
{
  return type;
}

void WrongAnimal::setType(const std::string &newType)
{
  type = newType;
}

void WrongAnimal::makeSound() const
{
  std::cout << "WrongAnimal PURE SOUND\n";
}