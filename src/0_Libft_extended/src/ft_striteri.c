/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:17:16 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:54 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Applies the function ’f’ on each character of the string passed as argument, 
// passing its index as first argument. Each character is passed by address to 
// ’f’ to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	while (*s)
	{
		(*f)(index, s);
		s++;
		index++;
	}
}
