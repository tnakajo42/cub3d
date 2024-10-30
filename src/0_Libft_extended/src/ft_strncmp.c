/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:58 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:11 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	while ((*string1 || *string2) && count--)
	{
		if (*string1 != *string2)
			return ((unsigned char)*string1 - (unsigned char)*string2);
		string1++;
		string2++;
	}
	return (0);
}
