#include "./../phonebook.hpp"


void  PhoneBook::add(void)
{
  std::string first_name, last_name, nickename, phone_number, darckest_secret;
  std::cout << "enter your first name: ";
  std::getline(std::cin, first_name);
  if (!std::cin.good() || first_name.empty())
    return ;
  else
    std::cout << phone_number;
}


PhoneBook::PhoneBook()
{
  this->index = 0;
}