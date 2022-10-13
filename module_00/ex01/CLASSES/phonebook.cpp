#include "./../phonebook.hpp"

void PhoneBook::add(void)
{
  std::string first_name, last_name, nickename, phone_number, darckest_secret;
  while (first_name.empty())
  {
    std::cout << "enter your first name: ";
    std::getline(std::cin, first_name);
    if (!std::cin.good())
      return;
  }
  while (last_name.empty())
  {
    std::cout << "enter your last name: ";
    std::getline(std::cin, last_name);
    if (!std::cin.good())
      return;
  }
  while (nickename.empty())
  {
    std::cout << "enter your nickname: ";
    std::getline(std::cin, nickename);
    if (!std::cin.good())
      return;
  }
  while (phone_number.empty())
  {
    std::cout << "enter your phone number: ";
    std::getline(std::cin, phone_number);
    if (!std::cin.good())
      return;
  }
  while (darckest_secret.empty())
  {
    std::cout << "enter your darckest secret: ";
    std::getline(std::cin, darckest_secret);
    if (!std::cin.good())
      return;
  }
  this->contactes[this->index % 8].set_first_name(first_name);
  this->contactes[this->index % 8].set_last_name(last_name);
  this->contactes[this->index % 8].set_nickname(nickename);
  this->contactes[this->index % 8].set_phone_number(phone_number);
  this->contactes[this->index % 8].set_darckest_secret(darckest_secret);
  this->index++;
}
std::string PhoneBook::get_parsed_attribute(std::string str)
{
  return (
      str.length() == 10  ? str
      : str.length() > 10 ? str.substr(0, 9) + "."
                          : std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::search()
{
  int i = -1, in = 0;
  std::string index;
  std::cout << "     index"
            << " | "
            << "first name"
            << " | "
            << " last name"
            << " | "
            << "  nickname" << std::endl;
  while (!this->contactes[++i].get_first_name().empty() && i < 8)
  {
    std::cout << "         " << i + 1 << " | ";
    std::cout << this->get_parsed_attribute(this->contactes[i].get_first_name()) + " | ";
    std::cout << this->get_parsed_attribute(this->contactes[i].get_last_name()) + " | ";
    std::cout << this->get_parsed_attribute(this->contactes[i].get_nickname()) << std::endl;
  }
  do
  {
    std::cout << "Enter index of contacte: ";
    std::getline(std::cin, index);
    if (!std::cin.good())
      exit(0);
    try
    {
      in = std::stoi(index);
    }
    catch (...)
    {
      std::cout << "  Plese enter a valid index" << std::endl;
    }
  } while (in <= 0 || (in > 8 || this->contactes[in - 1].get_first_name().empty()));
  std::cout << "first name      : " << this->contactes[--in].get_first_name() << std::endl;
  std::cout << "last name       : " << this->contactes[in].get_last_name() << std::endl;
  std::cout << "nickname        : " << this->contactes[in].get_nickname() << std::endl;
  std::cout << "phone number    : " << this->contactes[in].get_phone_number() << std::endl;
  std::cout << "darckest secret : " << this->contactes[in].get_darckest_secret() << std::endl;
}

PhoneBook::PhoneBook()
{
  this->index = 0;
}