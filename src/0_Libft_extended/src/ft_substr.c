/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:49:51 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:23 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	copy_len;
	char	*checker;
	char	*substr;

	while (*s && start--)
		s++;
	copy_len = 0;
	checker = (char *)s;
	while (*(checker++) && len--)
		copy_len++;
	substr = (char *)malloc(copy_len + 1);
	if (substr == 0)
		return (0);
	checker = substr;
	while (copy_len--)
		*(checker++) = *(s++);
	*checker = '\0';
	return (substr);
}
