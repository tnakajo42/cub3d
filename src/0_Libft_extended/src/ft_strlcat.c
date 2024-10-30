/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:40 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:59 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dst_len = 0;
	while (*dst && size)
	{
		dst++;
		dst_len++;
		size--;
	}
	while (*src && size > 1)
	{
		*(dst++) = *(src++);
		size--;
	}
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (src_len + dst_len);
}
