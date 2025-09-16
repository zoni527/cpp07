/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:17:58 by jvarila           #+#    #+#             */
/*   Updated: 2025/09/16 16:34:59 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template<typename T, typename F>
void	iter( T *array, size_t len, F f )
{
	for ( size_t i = 0; i < len; ++i )
		f( array[i] );
}
