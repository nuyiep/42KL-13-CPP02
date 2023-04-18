/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:01:26 by plau              #+#    #+#             */
/*   Updated: 2023/04/18 21:59:50 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream> //std::cout, endl
#include <cmath> //roundf

class Fixed
{
	public:
		/* Constructor and destructor */
		Fixed(void);
		Fixed(const int x);
		Fixed(const float x);
		~Fixed(void);
		
		/* Copy constructor */
		Fixed(const Fixed &src);
		
		/* Comparison operators */
		bool	operator>(Fixed src) const;

		/* Arithmetic operators */
		Fixed	operator+(Fixed src) const;
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator*(Fixed src) const;
		Fixed	operator-(Fixed src) const;
		Fixed	operator--(void);
		Fixed	operator--(int);
		Fixed	operator/(Fixed src) const;
		
		/* Public functions */
		float 				toFloat(void) const;
		void				setFpn(int x);
		int					getFpn(void) const;
		static Fixed 		&max(Fixed &x, Fixed &y);
		static const Fixed 	&max(const Fixed &x, const Fixed &y);
	private:
		int 			 _fpn;
		static const int _fb = 8;
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
