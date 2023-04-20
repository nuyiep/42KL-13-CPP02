/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:51:00 by plau              #+#    #+#             */
/*   Updated: 2023/04/20 20:08:19 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

#define	RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE  "\033[34m"
#define CYAN  "\033[36m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

class Fixed
{
	public:
		Fixed(void); // default constructor
		Fixed(const Fixed &fixed); //copy constructor 
		~Fixed(void); //destructor 
		// Fixed& 	operator=(const Fixed& src);// copy assignment operator
		int		getRawBits(void) const; //getter
		void	setRawBits(int const raw); //setter
	private:
		int	_fixed_point_number;
		static const int fractional_bits = 8;
		// int[]
		/**
		 * static const int
		 * 	creates a single copy of the fractional_bits variable
		 * 	that is shared by all instances of the Fixed class
		 * (const) ensures that the value cannot be changed 
		 */
};



#endif
