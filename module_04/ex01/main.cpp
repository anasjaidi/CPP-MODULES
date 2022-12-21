# include "./Dog.hpp"
# include "./Cat.hpp"
# include "./Brain.hpp"
# include "./WrongCat.hpp"

int main()
{
  // const Animal *meta = new Animal();
  // const WrongAnimal *wc = new WrongCat();
  // const Animal *j = new Dog();
  // const Animal *i = new Cat();
  // std::cout << j->getType() << " " << std::endl;
  // std::cout << i->getType() << " " << std::endl;
  // i->makeSound(); // will output the cat sound!
  // j->makeSound();
  // meta->makeSound();
  // wc->makeSound();
  // delete meta;
  // delete wc;
  // delete i;
  // delete j;
  // Brain a;

  // for (size_t i = 0; i < 100; i++)
  // {
  //   a.setIdea(i, std::string("anas") + std::to_string(i));
  // }
  // for (size_t i = 0; i < 100 && !a.getIdea(i).empty(); i++)
  // {
  //   std::cout << a.getIdea(i) << std::endl;
  // }
  // Brain b = a;
  // for (size_t i = 0; i < 100 && !a.getIdea(i).empty(); i++)
  // {
  //   std::cout << b.getIdea(i) << std::endl;
  // }
  Animal *cat = new Cat();
  cat->get_brain();
}