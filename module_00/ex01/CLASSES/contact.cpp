#include "../phonebook.hpp"



const std::string &CONTACT::get_first_name(void) const
{
  return (this->first_name);
}

const std::string &CONTACT::get_last_name(void) const
{
  return (this->last_name);
}

const std::string &CONTACT::get_nickname(void) const
{
  return (this->nickname);
}

const std::string &CONTACT::get_phone_number(void) const
{
  return (this->phone_number);
}

const std::string &CONTACT::get_darckest_secret(void) const
{
  return (this->darckest_secret);
}

void CONTACT::set_first_name(const std::string &first_name)
{
  if (!first_name.empty())
    this->first_name = first_name;
}

void CONTACT::set_last_name(const std::string &last_name)
{
  if (!last_name.empty())
    this->last_name = last_name
}

void CONTACT::set_nickname(const std::string &nickname)
{
  if (!nickname.empty())
    this->nickname = nickname;
}

void CONTACT::set_phone_number(const std::string &phone_number)
{
  if (!phone_number.empty())
    this->phone_number =phone_number;
}

void CONTACT::set_darckest_secret(const std::string &darckest_secret)
{
  if (!darckest_secret.empty())
    this->darckest_secret = darckest_secret;
}


