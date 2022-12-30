#include <iostream>
#include <cstdlib>

class Base
{
public:
  virtual ~Base() {}
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base *generate(void)
{
  srand(time(NULL));
  int r = rand() % 10;
  if (!(r % 3))
    return new A;
  else if (!(r % 2))
    return new B;
  else
    return new C;
  return nullptr;
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
}

void identify(Base &p)
{
  try
  {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A\n";
  }
  catch (const std::exception &e)
  {
    try
    {
      B &b = dynamic_cast<B &>(p);
      (void)b;
      std::cout << "B\n";
    }
    catch (const std::exception &e)
    {
      try
      {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C\n";
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }
    }
  }
}

int main()
{
  Base *ptr = generate();
  identify(ptr);
  identify(*ptr);
  return 0;
}
