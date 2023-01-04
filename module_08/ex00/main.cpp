#include "easyfind.hpp"

int main()
{
  std::vector<int> v;
  for (size_t i = 0; i < 10; i++)
    v.push_back(i);

  try
  {
    bool founded = easyfind(v, 11);
    std::cout << "founded: " << founded << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
