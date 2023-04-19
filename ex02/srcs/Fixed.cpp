/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:01:21 by plau              #+#    #+#             */
/*   Updated: 2023/04/19 12:08:44 by plau             ###   ########.fr       */
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

/*  Returns true if LHS is bigger than src, else returns false */
bool	Fixed::operator>(Fixed src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<(Fixed src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>=(Fixed src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator<=(Fixed src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==(Fixed src) const
{
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator!=(Fixed src) const
{
	return (this->toFloat() != src.toFloat());
}

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

/* Passing in 2 references on fpns */
/* Returns a reference to the bigger one */
Fixed	&Fixed::max(Fixed &x, Fixed &y)
{
	std::cout << RED << "using this function w/o const\n" << RESET;
	if (x.toFloat() >= y.toFloat())
		return (x);
	else
		return (y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	std::cout << RED << "using this const function\n" << RESET;
	if (x.toFloat() >= y.toFloat())
		return (x);
	else
		return (y);
}

Fixed	&Fixed::min(Fixed &x, Fixed &y)
{
	std::cout << RED << "Not using this function w/o const\n" << RESET;
	if (x.toFloat() >= y.toFloat())
		return (y);
	else
		return (x);
}

const Fixed	&Fixed::min(const Fixed &x, const Fixed &y)
{
	std::cout << RED << "using this const function\n" << RESET;
	if (x.toFloat() >= y.toFloat())
		return (y);
	else
		return (x);
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
