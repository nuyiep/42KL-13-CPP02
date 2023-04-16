/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:50:57 by plau              #+#    #+#             */
/*   Updated: 2023/04/16 21:58:25 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/* Default constructor */
Fixed::Fixed(void) //: _fixed_point_number(0)
{
	std::cout << CYAN << "Default constructor called" << RESET << '\n';
	this->_fixed_point_number = 0;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN << "Copy constructor called" << RESET << '\n';
	(*this) = src;
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
	if (this != &src) //check for self-assignment
		this->_fixed_point_number = src.getRawBits(); //copy the data from src
	return (*this); //return a reference to the current object
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << '\n';
	return (this->_fixed_point_number);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setter function" << '\n';
	this->_fixed_point_number = raw;
}
