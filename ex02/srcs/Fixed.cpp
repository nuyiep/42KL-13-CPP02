/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:01:21 by plau              #+#    #+#             */
/*   Updated: 2023/04/18 21:30:12 by plau             ###   ########.fr       */
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

/* Copy constructor */
Fixed::Fixed(const Fixed &src)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << '\n';
	(*this) = src;
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << CYAN << "Destructor" << RESET << '\n';
}

/******************************************************************************/
/*								COMPARISON OPERATOR FUNCTIONS							  */
/******************************************************************************/

/******************************************************************************/
/*								ARITHMETIC OPERATOR FUNCTIONS							  */
/******************************************************************************/

Fixed Fixed::operator+(Fixed src) const
{
	return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator*(Fixed src) const
{
	return (this->toFloat() * src.toFloat());
}

/* Pre-increment (++n) */
Fixed Fixed::operator++(void)
{
	this->_fpn++;
	return (*this);
}

/**
 * Post-increment (n++)
 * int - dummy argument used to distinguish prefix and postfix 
 * 	   - serves no actual purpose, is simply a convention
 * 	   - when we call a++, 0 is passed as the int 
 *     - just a placeholder, not used for any actual computation
 */
Fixed Fixed::operator++(int)
{
	Fixed	preIncrement;

	preIncrement = *this;
	this->_fpn++;
	return (preIncrement);
}

/* Normal minus operation */ 
Fixed Fixed::operator-(Fixed src)const
{
	return (this->toFloat() - src.toFloat());
}

/* --n */
Fixed Fixed::operator--(void)
{
	this->_fpn--;
	return (*this);
}

/* n-- */
Fixed Fixed::operator--(int)
{
	Fixed preDecrement;

	preDecrement = this->_fpn;
	this->_fpn--;
	return (preDecrement);
}

/* Divide */
Fixed Fixed::operator/(Fixed src) const
{
	return (this->toFloat() / src.toFloat());
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
