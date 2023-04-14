/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:50:57 by plau              #+#    #+#             */
/*   Updated: 2023/04/14 19:16:08 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed(void)
{
	std::cout << CYAN << "Default constructor called" << '\n';
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << RESET << '\n';
}
