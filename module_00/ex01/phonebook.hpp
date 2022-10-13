#pragma once
# include <iostream>
# include <iomanip> 
# include <string>
# include "contact.hpp"


class PhoneBook {
  private:
    int index;
    CONTACT contactes[8];
  public:
    PhoneBook();
    void        add(void);
    void        search(void);
    std::string get_parsed_attribute(std::string);
};