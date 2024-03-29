#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
  private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_exec;
    Form();
  public:
    Form(const Form &);
    Form & operator = (const Form &);
    Form(const std::string &, const int&, const int&);
    ~Form();
    const std::string &get_name() const ;
    bool beSigned(const Bureaucrat &bur);
    int get_grade_sign() const;
    int get_grade_exec() const;
    bool get_signed() const;
    class GradeTooHighException : public std::exception
    {
      virtual const char *what(void) const throw();
    };
    class GradeTooLowException : public std::exception
    {
      virtual const char *what(void) const throw();
    };
    
};

std::ostream &operator<<(std::ostream &, const Form &);

# endif