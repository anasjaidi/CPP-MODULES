#include "./Dog.hpp"
#include "./Brain.hpp"

Dog::Dog() : Animal()
{
  this->brain = new Brain();
  type = "Dog";
  std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
  this->brain = new Brain();
  std::cout << "Dog Type constructor called" << std::endl;
}

Dog::~Dog()
{
  std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
  std::cout << "Dog Copy assignment operator called" << std::endl;
  type = src.type;
  return *this;
}

Dog::Dog(const Dog &src)
{

  std::cout << "Dog Copy constructor called" << std::endl;
  *this = src;
}

void Dog::makeSound() const
{
  std::cout << "DOG SOUND\n";
}

Brain Dog::get_brain() const
{
  return *brain;
}