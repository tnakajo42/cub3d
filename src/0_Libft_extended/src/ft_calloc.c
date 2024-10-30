/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:00:44 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:13:20 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*data;
	char	*copy;
	size_t	total;

	total = num * size;
	data = (char *)malloc(total);
	if (!data)
		return (0);
	copy = data;
	while (total--)
		*(copy++) = 0;
	return (data);
}
