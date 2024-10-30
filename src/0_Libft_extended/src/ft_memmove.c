/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:57:21 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:13:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*str;
	unsigned char	*from;

	if (!dest && !src)
		return (0);
	str = dest;
	from = (unsigned char *)src;
	if (src < dest)
		while (count--)
			str[count] = from[count];
	else
		while (count--)
			*(str++) = *(from++);
	return (dest);
}
