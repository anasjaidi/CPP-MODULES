#include "./Brain.hpp"

Brain::Brain()
{
  std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
  std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
  std::cout << "Brain Copy assignment operator called" << std::endl;
  for (size_t i = 0; i < 100; i++)
    ideas[i] = src.getIdea(i);
  return *this;
}

Brain::Brain(const Brain &src)
{

  std::cout << "Brain Copy constructor called" << std::endl;
  *this = src;
}

void Brain::setIdea(const int &i, const std::string &idea) {
  const unsigned index = (unsigned char)i;
  
  if (index > 99)
    return (void)(std::cout << "index out of range\n");
  ideas[index] = idea;
}
std::string &Brain::getIdea(const int &i) const
{
  const unsigned index = (unsigned char)i;

  if (index > 99)
    (std::cout << "index out of range\n");
  return (std::string&)(ideas[i]);
}

