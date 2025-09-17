/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:29:37 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/17 18:03:03 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
public:
	Array( void ) = delete;
	Array( Array const &other );
	Array( size_t n = 0 );
	~Array( void );

	Array	&operator=( Array const &rhs );
	T		&operator[]( size_t idx ) const;

	size_t	size( void ) const;

private:
	T		*_members = nullptr;
	size_t	_size = 0;
};

/* -------------------------------------------------------------------------- */

template<typename T>
Array<T>:: Array( size_t n )
	: _size( n ), _members( new T[n] ) {}

template<typename T>
Array<T>:: Array( Array<T> const &other )
	:	_size( other._size ),
		_members( new T[other._size] )
{
	for ( size_t i = 0; i < _size; ++i )
		_members[i] = other._members[i];
}

template<class T>
Array<T>:: ~Array( void )
{
	delete[] _members;
}

template<class T>
Array<T>	&Array<T>:: operator=( Array<T> const &rhs )
{
	if ( this != &rhs)
	{
		if ( _size != rhs._size )
		{
			delete[] _members;
			_size = rhs._size;
			_members = new T[_size];
		}
		for ( size_t i = 0; i < _size; ++i )
		{
			_members[i] = rhs._members[i];
		}
	}
	return *this;
}

template<class T>
T			&Array<T>:: operator[]( size_t idx ) const
{
	if ( idx >= _size )
		throw std::out_of_range( "Array: index out of range" );
	return _members[idx];
}
