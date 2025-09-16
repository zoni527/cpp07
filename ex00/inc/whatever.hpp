/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:14:13 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/16 15:40:51 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	swap( T &x, T &y )
{
	T	temp = x;

	x = y;
	y = temp;
}

template<typename T>
T		&min( T &x, T &y )
{
	return ( ( x < y ) ? x : y );
}

template<typename T>
T		&max( T &x, T &y )
{
	return ( ( x > y ) ? x : y );
}
