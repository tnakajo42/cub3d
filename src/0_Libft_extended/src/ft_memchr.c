/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:45:14 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:13:45 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*str;
	unsigned char	test;

	str = (unsigned char *)buf;
	test = (unsigned char)c;
	while (count--)
	{
		if (*str == test)
			return (str);
		str++;
	}
	return (0);
}
