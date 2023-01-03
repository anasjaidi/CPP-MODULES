#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
  T *arr;
  int size;

public:
  Array()
  {
    size = 0;
    arr = NULL;
  }
  Array(unsigned int n)
  {
    size = n;
    arr = new (std::nothrow) T[n]();
    if (!arr)
      exit(1);
  }
  Array(const Array &rhs)
  {
    size = 0;
    *this = rhs;
  }
  Array &operator=(const Array &rhs)
  {
    if (size)
      delete[] arr;

    size = rhs.size;

    arr = new (std::nothrow) T[size];

    if (!arr)
      exit(1);

    for (int i = 0; i < size; ++i)
      arr[i] = rhs.arr[i];

    return *this;
  }
  int get_size()
  {
    return size;
  }
  ~Array()
  {
    if (size)
      delete[] arr;
  }
  T &operator[](int i)
  {
    if (i < 0 || i >= size)
      throw(std::exception());

    return arr[i];
  }
};

#endif