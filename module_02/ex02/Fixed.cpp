#include "./Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &num)
{
  std::cout << "Int constructor called" << std::endl;
  fixed_point = num << fractional_bits;
}

Fixed::Fixed(const float &num)
{
  std::cout << "Float constructor called" << std::endl;
  fixed_point = roundf(num * (1 << fractional_bits));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
  std::cout << "Copy assignment operator called" << std::endl;
  fixed_point = src.getRawBits();
  return *this;
}

Fixed::Fixed(const Fixed &src)
{

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}
void Fixed::setRawBits(const int set)
{
  fixed_point = set;
}

int Fixed::getRawBits(void) const
{
  // std::cout << "getRawBits member function called" << std::endl;
  return (
      fixed_point);
}


int Fixed::toInt(void) const
{
  return (fixed_point >> fractional_bits);
}

float Fixed::toFloat(void) const
{
  float r = (float(fixed_point) / (1 << fractional_bits));
  return r;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
  out << float(c.toFloat());
  return (out);
}

bool Fixed::operator<(const Fixed& n) {
  return (this->fixed_point < n.fixed_point);
}

bool Fixed::operator<=(const Fixed& n) {
  return (this->fixed_point <= n.fixed_point);
}

bool Fixed::operator>(const Fixed& n) {
  return (this->fixed_point > n.fixed_point);
}

bool Fixed::operator>=(const Fixed& n) {
  return (this->fixed_point >= n.fixed_point);
}

bool Fixed::operator==(const Fixed& n) {
  return (this->fixed_point == n.fixed_point);
}

bool Fixed::operator!=(const Fixed& n) {
  return (this->fixed_point != n.fixed_point);
}

float Fixed::operator*(const Fixed& n) {
  return (
    this->toFloat() * n.toFloat()
  );
}

float Fixed::operator-(const Fixed& n) {
  return (
    this->toFloat() - n.toFloat()
  );
}

float Fixed::operator+(const Fixed& n) {
  return (
    this->toFloat() + n.toFloat()
  );
}

float Fixed::operator/(const Fixed& n) {
  return (
    this->toFloat() / n.toFloat()
  );
}

Fixed &Fixed::operator++(int) {
  Fixed *tmp = new Fixed(*this);
  fixed_point++;
  return (*tmp);
}

Fixed &Fixed::operator++() {

  return (fixed_point++, *this);
}

Fixed &Fixed::operator--(int) {
  Fixed *tmp = new Fixed(*this);
  fixed_point--;
  return (*tmp);
}

Fixed &Fixed::operator--() {
  return (fixed_point--, *this);
}

const Fixed &Fixed::max(Fixed const &x, Fixed const &y)
{
  return (Fixed)x >= y ? x : y;
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
  return x >= y ? x : y;
}

const Fixed &Fixed::min(Fixed const &x, Fixed const &y)
{
  return (Fixed)x <= y ? x : y;
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
  return x <= y ? x : y;
}