#include "./../phonebook.hpp"


void  PhoneBook::add(void)
{
  std::string first_name, last_name, nickename, phone_number, darckest_secret;
  std::cout << this->index % 8<< std::endl;
  while (first_name.empty())
  {
    std::cout << "enter your first name: ";
    std::getline(std::cin, first_name);
    if (!std::cin.good())
      return ;
  }
  while (last_name.empty())
  {
    std::cout << "enter your last name: ";
    std::getline(std::cin, last_name);
    if (!std::cin.good())
      return ;
  }
  while (nickename.empty())
  {
    std::cout << "enter your nickname: ";
    std::getline(std::cin, nickename);
    if (!std::cin.good())
      return ;
  }
  while (phone_number.empty())
  {
    std::cout << "enter your phone number: ";
    std::getline(std::cin, phone_number);
    if (!std::cin.good())
      return ;
  }
  while (darckest_secret.empty())
  {
    std::cout << "enter your darckest secret: ";
    std::getline(std::cin, darckest_secret);
    if (!std::cin.good())
      return ;
  }
  this->contactes[this->index % 8].set_first_name(first_name);
  this->contactes[this->index % 8].set_last_name(last_name);
  this->contactes[this->index % 8].set_nickname(nickename);
  this->contactes[this->index % 8].set_phone_number(phone_number);
  this->contactes[this->index % 8].set_darckest_secret(darckest_secret);
  this->index++;
}

void  PhoneBook::search()
{
  int i = -1;
  std::string first_name, last_name, nickname;
  std::cout << "   index  " <<  " | "  << "first name" << " | " << "last name"<< " | "  << "nickname "<< std::endl;
  while (!this->contactes[++i].get_first_name().empty())
  {
    std::cout << "   " << i  << "       | ";
    first_name = this->contactes[i].get_first_name().length >= 10 ? this->contactes[i].get_first_name().substr(0,9) : "ok";
  }
}

PhoneBook::PhoneBook()
{
  this->index = 0;
}