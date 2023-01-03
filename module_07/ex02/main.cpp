#include "Array.hpp"

int main(int, char **)
{
  try
  {
    Array<int> arr(10);

    for (size_t i = 0; i < static_cast<size_t>(arr.get_size()); i++)
      arr[i] = i; 
    
    Array<int> cp = arr;

    for (size_t i = 0; i < static_cast<size_t>(cp.get_size()); i++)
      std::cout << cp[i] <<std::endl;

    cp[11];
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return 0;
}