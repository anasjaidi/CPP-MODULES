#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
  std::cout << "TEST 1:\n";
  Animal *animals[12];

  for (int i = 0; i < 12; i++)
  {
    if (i & 1)
    {
      animals[i] = new Dog();
    }
    else
    {
      animals[i] = new Cat();
    }
  }
  for (int i = 0; i < 12; i++)
  {
    animals[i]->makeSound();
  }
  for (int i = 0; i < 12; i++)
  {
    delete animals[i];
  }
}
