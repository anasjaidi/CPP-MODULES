# pragma once 
# include <iostream>




class Span {
  private:
    int *_tab;
    int N;
    int length;
  public:
    Span();
    Span(int &);
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();
    int &get_N(void);
};