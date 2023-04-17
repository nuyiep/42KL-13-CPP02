/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:12:31 by plau              #+#    #+#             */
/*   Updated: 2023/04/17 22:55:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/* FPN = fixed point number */

/* Default constructor */
Fixed::Fixed(void) :_fb(8)
{
	std::cout << CYAN << "Default constructor called" << RESET << '\n';
	this->_fpn = 0;
}

/* Copy constrcutor */
Fixed::Fixed(const Fixed &src) :_fb(8)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << '\n';
	(*this) = src;
}

/* Int constructor */
/* Converts Int to Fpn */
/* By multiplying it by 2^bits or 2^8 or 256 */
/**/ 
Fixed::Fixed(int const x) : _fb(8)
{
	this->_fpn = x << this->_fb;
	std::cout << GREEN << "Int constructor called" << RESET << '\n';
}

/* Float constructor */
/* Converts Float to Fpn */
Fixed::Fixed(const float x) :_fb(8)
{
	(void)x;
	std::cout << MAGENTA << "Float constructor called" << RESET << '\n';
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << CYAN << "Destructor called" << RESET << '\n';
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

/* Copy assignment operator overload */
 Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << '\n';
	if (this != &src) // check for self-assignment
		this->_fpn = src.getRawBits(); //copy the data from src
	return (*this); //return a reference to the current object
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

int Fixed::getRawBits(void) const
{
	return (this->_fpn);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void Fixed::setRawBits(int const x)
{
	this->_fpn = x;
}

/******************************************************************************/
/*								PUBLIC FUNCTIONS							  */
/******************************************************************************/

/* Converts fpn to a floating point number */
float 	Fixed::toFloat(void) const
{
	return (this->_fpn >> Fixed::_fb);
}

/* Converts fpn to an int */ 
int   	Fixed::toInt(void) const
{
	return ();
}

/******************************************************************************/
/*								OTHER FUNCTIONS							  	  */
/******************************************************************************/

/* Overload of the insertion (<<) operator */
/* inserts a floating-point representation of the fixed-point number */
/* into the output stream object passed as parameter */
std::ostream &operator<<(std::ostream &output, const Fixed &src)
{
	return (output);
}

