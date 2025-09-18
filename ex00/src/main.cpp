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

#include "whatever.hpp"
#include <string>
#include <iostream>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static void			subjectMain( void );
static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );


int	main( void )
{
	print_test_name("Subject's main");
	subjectMain();
	print_test_name("Const ints");
	{
		int const	a = 1;
		int const	b = 2;

		// Won't compile if uncommented
		// swap( a, b );
		std::cout << "a = " << a << ", b = " << b << '\n';
		std::cout << "min( a, b) = " << min( a, b ) << '\n';
		std::cout << "max( a, b) = " << max( a, b ) << '\n';
	}
	print_test_name("Doubles");
	{
		double	a = .1;
		double	b = -.1;

		std::cout << "a = " << a << ", b = " << b << '\n';
		std::cout << "swap( a, b );" << '\n';
		swap( a, b );
		std::cout << "a = " << a << ", b = " << b << '\n';
		std::cout << "min( a, b) = " << min( a, b ) << '\n';
		std::cout << "max( a, b) = " << max( a, b ) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

static void	subjectMain( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << '\n';
	std::cout << "min( a, b ) = " << ::min( a, b ) << '\n';
	std::cout << "max( a, b ) = " << ::max( a, b ) << '\n';

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << '\n';
	std::cout << "min( c, d ) = " << ::min( c, d ) << '\n';
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

/* -------------------------------------------------------------------------- */

static void print_test_name( std::string str ) {

	for ( size_t i = 0; i < str.size(); ++i )
		str[i] = std::toupper( str[i] );

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
