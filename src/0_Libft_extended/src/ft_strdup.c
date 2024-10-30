/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:00:34 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:51 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *string)
{
	size_t	len;
	char	*out;
	char	*write;

	len = ft_strlen(string);
	out = (char *)malloc(len + 1);
	if (!out)
		return (0);
	write = out;
	while (len--)
		*(write++) = *(string++);
	*write = '\0';
	return (out);
}
