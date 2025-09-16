/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:40:48 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/16 16:07:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );
static int			doubleTheInt( int & d );
static double		doubleTheDouble( double &d );
static void			printTheInt( int const &i );
static void			printTheDouble( double const &d );

int	main( void )
{
	int		iArray[] = { -3, -2, -1, 0, 1, 2, 3 };
	double	dArray[] = { 0.123, -3.21, 42.0420, 1000.0001 };

	print_test_name("Int array iter");
	{
		size_t	n = sizeof( iArray ) / sizeof( iArray[0] );
		iter( iArray, n, doubleTheInt );
		iter( iArray, n, printTheInt );
	}
	print_test_name("Double array iter");
	{
		size_t	n = sizeof( dArray ) / sizeof( dArray[0] );
		iter( dArray, n, doubleTheDouble );
		iter( dArray, n, printTheDouble );
	}
	std::cout << std::endl;
	return 0;
}

static double	doubleTheDouble( double &d )
{
	return ( d *= 2 );
}

static int	doubleTheInt( int &i )
{
	return ( i *= 2 );
}

static void		printTheInt( int const &i )
{
	std::cout << i << std::endl;
}

static void		printTheDouble( double const &d )
{
	std::cout << d << std::endl;
}


/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str ) {

	for ( char &c : str )
		c = std::toupper( c );

	size_t width = str.length() + 10;

	std::string separator = n_chars( '-', width );
	std::cout << "\n" C_HI_Y << separator << "\n";
	std::cout << "**** " << str << " ****";
	std::cout << "\n" << separator << C_RST "\n";
	std::cout << std::endl;
}

static std::string n_chars( char c, size_t n ) {
	std::string str = "";
	while ( n-- )
		str += c;
	return str;
}
