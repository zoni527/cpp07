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

#include "Array.hpp"
#include <iostream>

#define C_HI_Y	"\033[0;93m\001"
#define C_RST	"\033[0m\002"

static std::string	n_chars( char c, size_t n );
static void			print_test_name( std::string str );

int	main( void )
{
	print_test_name( "Default constructor (0 size array)" );
	{
		Array<int>	arr;
		try
		{
			std::cout << arr[0] << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "Parameterized constructor (n members), default initialization, size(), subscript operator" );
	{
		Array<int>	arr( 10 );
		try
		{
			for ( size_t i = 0; i < arr.size() + 1; ++i )
				std::cout << arr[i] << std::endl;
		}
		catch ( std::exception const &e )
		{
			std::cout << e.what() << std::endl;
		}
	}
	print_test_name( "Copy constructor, subcript assignment" );
	{
		Array<unsigned int>	arr( 10 );
		for ( size_t i = 0; i < arr.size(); ++i )
			arr[i] = i;
		Array<unsigned int>	copy( arr );
		for ( size_t i = 0; i < arr.size(); ++i )
			std::cout << copy[i] << std::endl;
	}
	print_test_name( "String array" );
	{
		Array<std::string>	arr( 10 );
		std::string	msg = "test";
		for ( size_t i = 0; i < arr.size(); ++i )
			arr[i] = msg + " " + std::to_string( i );
		for ( size_t i = 0; i < arr.size(); ++i )
			std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
	return 0;
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
