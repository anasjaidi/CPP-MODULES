# pragma once 
 
# include <iostream>


template<typename T>
void iter(T* arr, uint size, void (*f)(T&)) {
  for (size_t i = 0; i < size; i++)
  {
    f(arr[i]);
  }
  
}