/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:12:31 by plau              #+#    #+#             */
/*   Updated: 2023/04/17 12:52:56 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

/* Default constructor */
Fixed::Fixed(void)
{
	std::cout << CYAN << "Default constructor called" << RESET << '\n';
}

/* Copy constrcutor */
Fixed::Fixed(const Fixed &src)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << '\n';
	(*this) = src;
}

/* Int constructor */
Fixed::Fixed(const int x)
{
	(void)x;
	std::cout << GREEN << "Int constructor called" << RESET << '\n';
}

/* Float constructor */
Fixed::Fixed(const float x)
{
	(void)x;
	std::cout << MAGENTA << "Float constructor called" << RESET << '\n';
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << CYAN << "Destructor called" << RESET << '\n';
}
