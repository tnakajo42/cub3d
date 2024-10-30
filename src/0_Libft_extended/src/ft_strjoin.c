/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:15:23 by bschneid          #+#    #+#             */
/*   Updated: 2024/09/05 13:08:26 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Allocates and returns a new string, which is 
// the result of the concatenation of ’s1’ and ’s2’.
// s1 can be NULL, in which case it will be treated as an empty string.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	copy_len;
	char	*checker;
	char	*substr;

	copy_len = 0;
	checker = (char *)s1;
	while (s1 && *(checker++))
		copy_len++;
	checker = (char *)s2;
	while (*(checker++))
		copy_len++;
	substr = (char *)malloc(copy_len + 1);
	if (substr == 0)
		return (NULL);
	checker = substr;
	while (s1 && *s1)
		*(checker++) = *(s1++);
	while (*s2)
		*(checker++) = *(s2++);
	*checker = '\0';
	return (substr);
}
