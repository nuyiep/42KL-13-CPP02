/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:12:31 by plau              #+#    #+#             */
/*   Updated: 2023/04/18 14:31:13 by plau             ###   ########.fr       */
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

/**
 * Converts float to fpn
 * ( 1 << _fb) - calculates the scaling factor for the conversion
 * 				 which is 2^(_fb)
 * 			   - 1 * 2 ^ _fb 
 * 			   - 1 * 2 ^ 8 
 * if we use (x << this->_fb) may produce the same fpn 
 * but this may not always be the case, esp for floating point values
 * that are not integers
 * using a scaling factor ensures that the resulting fpn has the 
 * correct precision and accuracy, while using bit shifting may 
 * produce a fpn that is shifted too much or too little
 * depending on the binary representation of the floating point value
 */
Fixed::Fixed(const float x) :_fb(8)
{
	this->_fpn = std::roundf(x * (1 << this->_fb));
	//printf("%d", this->_fpn);
	//printf("\n");
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

/* Converts fpn to a float */
/* By dividing it by 2^(_fb) or 256 */
float 	Fixed::toFloat(void) const
{
	//printf("%d", this->_fpn); //return is an int - 316015
	//printf("\n");
	//printf("%d", 1 << this->_fb); //return is an int- 256
	//printf("\n");
	//need to type cast to have the decimal place
	return (float(this->_fpn / (float)(1 << this->_fb)));
}

/* Converts fpn to an int */
/* By dividing it by 2^(_fb) or 256 */
int   	Fixed::toInt(void) const
{
	return (this->_fpn >> this->_fb);
}

/******************************************************************************/
/*								OTHER FUNCTIONS							  	  */
/******************************************************************************/

/* Function when << operator is called */
/* Gets the number's float from the class and outputs it to output stream */
/* Overload of the insertion (<<) operator */
/* inserts a floating-point representation of the fixed-point number */
/* into the output stream object passed as parameter */
std::ostream &operator<<(std::ostream &output, const Fixed &src)
{
	output << src.toFloat();
	return (output);
}

