#pragma once
#include <iostream>

class CONTACT {
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darckest_secret;
  public:
    CONTACT();
    const std::string  &get_first_name(void) const;
    const std::string  &get_last_name(void) const;
    const std::string  &get_nickname(void) const;
    const std::string  &get_phone_number(void) const;
    const std::string  &get_darckest_secret(void) const;
    void  set_first_name(const std::string &);
    void  set_last_name(const std::string &);
    void  set_nickname(const std::string &);
    void  set_phone_number(const std::string &);
    void  set_darckest_secret(const std::string &);
};


class PhoneBook {
  private:
    int index;
    CONTACT contactes[8];
  public:
    PhoneBook();
    void add(void);
};