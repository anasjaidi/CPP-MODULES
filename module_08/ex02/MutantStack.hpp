#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
private:
  /* data */
public:
  typedef typename std::deque<T>::iterator iterator;
  MutantStack() {

  };
  MutantStack(const MutantStack<T>&rhs) {
    *this = rhs;
  };
  MutantStack<T> &operator=(const MutantStack<T> &rhs) {
    this->c = rhs.c;
    return *this;
  }
  iterator begin() {return this->c.begin(); }
  iterator end() {return this->c.end();}
  ~MutantStack() {};
};