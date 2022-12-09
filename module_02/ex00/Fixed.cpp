# include "./Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
  std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed & src) {
  std::cout << "Copy assignment operator called" << std::endl;
  fixed_point = src.getRawBits();
  return *this;
}

void Fixed::setRawBits(const int set) {
  fixed_point = set;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (
    fixed_point
  );
}
Fixed::Fixed(const Fixed &src) {

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}