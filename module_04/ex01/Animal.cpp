# include "./Animal.hpp"

Animal::Animal() 
{
  std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): type(type)
{
  std::cout << "Type constructor called" << std::endl;
}

Animal::~Animal()
{
  std::cout << "Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  type = src.type;
  return *this;
}

Animal::Animal(const Animal &src)
{

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

std::string Animal::getType() const{
  return type;
}

void Animal::setType(const std::string &newType) {
  type = newType;
}

void Animal::makeSound() const {
  std::cout << "ANIMAL PURE SOUND\n";
}