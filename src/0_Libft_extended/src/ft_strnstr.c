/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:04:33 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:15 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*search;
	char	*pattern;
	size_t	tail;

	if (*little == 0)
		return ((char *)big);
	while (*big && len--)
	{
		tail = len + 1;
		search = (char *)big;
		pattern = (char *)little;
		while ((*search || *pattern) && tail--)
		{
			if (*search != *pattern)
				break ;
			search++;
			pattern++;
		}
		if (*pattern == '\0')
			return ((char *)big);
		big++;
	}
	return (0);
}
