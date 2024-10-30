/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:53:19 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:07 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Applies the function f to each character of the string s, passing its index
// as the first argument and the character itself as the second. A new string 
// is created (using malloc(3)) to collect the results from the successive 
// applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*out;

	len = ft_strlen(s);
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	i = 0;
	while (i < len)
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[len] = '\0';
	return (out);
}
