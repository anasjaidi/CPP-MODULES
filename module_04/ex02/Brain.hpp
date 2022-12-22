#pragma once
# include <iostream>


class Brain {
  private:
    std::string ideas[100];
  public:
    Brain();
    Brain(const std::string &);
    ~Brain();
    Brain(const Brain &);
    Brain &operator=(const Brain &);
    void setIdea(const int &, const std::string &);
    std::string &getIdea(const int &) const ;
};

