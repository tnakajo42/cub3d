/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:29:13 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:20 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Checks, if char c is in avoided set.
static	int	inset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

// Copies valid string in malloced memory.
static	void	write_str(char *begin, char *dest, size_t copy_len)
{
	while (copy_len--)
		*(dest++) = *(begin++);
	*dest = '\0';
}

// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
// specified in ’set’ removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	copy_len;
	char	*begin;
	char	*dest;

	if (!s1)
		return (0);
	while (inset(*s1, set))
		s1++;
	begin = (char *)s1;
	if (!(*s1))
		copy_len = 0;
	else
	{
		while (*s1)
			s1++;
		s1--;
		while (inset(*s1, set))
			s1--;
		copy_len = s1 - begin + 1;
	}
	dest = (char *)malloc(copy_len + 1);
	if (dest == 0)
		return (0);
	write_str(begin, dest, copy_len);
	return (dest);
}
