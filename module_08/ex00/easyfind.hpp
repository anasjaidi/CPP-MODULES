# pragma once 

# include <iostream>
# include <algorithm>
#include <vector>


template <typename T> 
int easyfind(T &con, int oc) {
  typename T::iterator it = std::find(con.begin(), con.end(), oc);
  if (it == con.end())
    throw std::exception();
  return std::distance(con.begin(), it);
}