/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:47:33 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:00 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	char	*str;

	str = dest;
	while (count-- > 0)
		*(str++) = (char)c;
	return (dest);
}
