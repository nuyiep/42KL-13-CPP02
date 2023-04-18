/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:01:21 by plau              #+#    #+#             */
/*   Updated: 2023/04/18 16:44:50 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/* Default constructor */
Fixed::Fixed(void)
{
	std::cout << CYAN << "Default constructor" << RESET << '\n';
	this->_fpn = 0;
}

/* Int constructor */
/* Covert int to fpn */ 
Fixed::Fixed(const int x)
{
	std::cout << GREEN << "Int constructor called" << RESET << '\n';
	this->_fpn = x << this->_fb;
}

/* Float constructor */
/* Convert float to fpn */
Fixed::Fixed(const float x)
{
	std::cout << GREEN << "Float constructor called" << RESET << '\n';
	this->_fpn = std::roundf(x * (1 << this->_fb));
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << CYAN << "Destructor" << RESET << '\n';
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

/* Getter function */
int		Fixed::getFpn(void) const
{
	return (this->_fpn);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

/* Setter function */
void	Fixed::setFpn(int x)
{
	this->_fpn = x;
}

/******************************************************************************/
/*								PUBLIC FUNCTIONS							  */
/******************************************************************************/

/* Convert from fpn to float */
float	Fixed::toFloat(void) const
{
	return ((float)this->_fpn / (float)(1 << this->_fb));
}

/******************************************************************************/
/*								OVERLOAD FUNCTIONS							  */
/******************************************************************************/

/* Overload of the insertion (<<) operator */
/* Function when << operator is called
** Gets the number's float from the class and outputs it to output stream */
std::ostream &operator<<(std::ostream &output, const Fixed &src)
{
	output << src.toFloat();
	return (output);
}
