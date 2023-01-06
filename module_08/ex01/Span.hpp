# pragma once 
# include <iostream>

# include <list>
# include <cmath>



class Span {
  private:
    std::list<int> _tab;
    int N;
  public:
    Span();
    void  addNumber(int n);
    void addNumber(std::list<int>::iterator , std::list<int>::iterator );
    Span(int );
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();
    int longestSpan();
    int shortestSpan();
    int &get_N(void);
};