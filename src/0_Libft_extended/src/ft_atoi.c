/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:00:12 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:13:17 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\f' || str == '\n')
		return (1);
	if (str == '\r' || str == '\t' || str == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *string)
{
	long	sign;
	long	res;

	while (ft_isspace(*string))
		string++;
	sign = 1;
	if (*string == '-' || *string == '+')
		if (*(string++) == '-')
			sign = -1;
	res = 0;
	while (*string && ft_isdigit(*string))
	{
		res = 10 * res + *string - '0';
		if (res * sign > 2147483647L)
			return (-1);
		else if (res * sign < -2147483648L)
			return (0);
		string++;
	}
	return ((int)(res * sign));
}
