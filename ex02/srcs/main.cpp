/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:12:28 by plau              #+#    #+#             */
/*   Updated: 2023/04/19 12:08:57 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl; //0
	std::cout << ++a << std::endl; //0.0390625
	std::cout << a << std::endl; //0.039625
	std::cout << a++ << std::endl; //0.039625
	std::cout << a << std::endl; //0.0078125
	std::cout << b << std::endl; //10.1016
	std::cout << Fixed::max( a, b ) << std::endl; //10.1016
	return 0;
}

/**
 * "1 + ε > 1."
 * ε (epsilon) denotes a small positive number or a 
 * 						 small positive quantity
 */
