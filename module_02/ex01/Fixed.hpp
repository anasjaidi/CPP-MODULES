/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:50:08 by ajaidi            #+#    #+#             */
/*   Updated: 2022/12/09 16:45:52 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:
  int fixed_point;
  static const int fractional_bits = 8;

public:
  Fixed();
  Fixed(const int&);
  Fixed(const float&);
  Fixed(const Fixed &);
  ~Fixed();
  Fixed &operator=(const Fixed &);
  int getRawBits(void) const;
  void setRawBits(int const);
  float toFloat(void) const;
  int toInt(void) const;  
};

std::ostream& operator<<(std::ostream& out, const Fixed& c);