# include "iter.hpp"

void inc(int &i) {
  i++;
}

int main()
{
  int arr[5] = {1,2,3,4,5};
  iter(arr, 5, inc);
  for (size_t i = 0; i < 5; i++)
  {
    std::cout << arr[i] << std::endl;
  }
  
  return 0;
}
