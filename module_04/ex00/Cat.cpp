#include "./Cat.hpp"

Cat::Cat() : Animal()
{
  type = "Cat";
  std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
  std::cout << "Cat Type constructor called" << std::endl;
}

Cat::~Cat()
{
  std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
  std::cout << "Cat Copy assignment operator called" << std::endl;
  type = src.type;
  return *this;
}

Cat::Cat(const Cat &src)
{
  std::cout << "Cat Copy constructor called" << std::endl;
  *this = src;
}

void Cat::makeSound() const
{
  std::cout << "CAT SOUND\n";
}