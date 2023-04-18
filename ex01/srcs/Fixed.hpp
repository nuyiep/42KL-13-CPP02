/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:12:34 by plau              #+#    #+#             */
/*   Updated: 2023/04/18 14:14:34 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream> //std::cout
#include <cmath> //roundf

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int x);
		Fixed(const float x);
		Fixed& operator=(const Fixed& src);
		~Fixed(void);
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		float 	toFloat(void) const;
		int   	toInt(void) const;
	private:
		int _fpn; //fixed point number
		int _fb; //fractional bits
};

std::ostream &operator<<(std::ostream &output, const Fixed &src);

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

#endif
