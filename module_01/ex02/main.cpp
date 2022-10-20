#include <iostream>


int main()
{
  std::string s =  "HI THIS IS BRAIN";
  std::string *stringPTR = &s;
  std::string &stringREF = s;
  std::cout << "memory of s: " << &s << std::endl;
  std::cout << "memory of stringPTR: " << stringPTR << std::endl;
  std::cout << "memory of stringREF: " << &stringREF << std::endl;
  std::cout << "value of s: " << s << std::endl;
  std::cout << "value of stringPTR: " << *stringPTR << std::endl;
  std::cout << "value of stringREF: " << stringREF << std::endl;
}