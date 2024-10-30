/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:02:31 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:13:40 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	intlen(int n)
{
	if (!n)
		return (0);
	return (1 + intlen(n / 10));
}

static	void	intwrite(int n, char *write, int len)
{
	int	value;
	int	i;

	if (!len)
		*write = '\0';
	else
	{
		value = n;
		i = 1;
		while (i++ < len)
			value /= 10;
		if (n < 0)
			*write = '0' - value % 10;
		else
			*write = '0' + value % 10;
		intwrite(n, write + 1, len - 1);
	}
}

// Allocates (with malloc(3)) and returns a string representing the integer 
// received as an argument. Negative numbers must be handled.
char	*ft_itoa(int n)
{
	int		len;
	char	*out;

	if (!n)
		len = 1;
	else if (n > 0)
		len = intlen(n);
	else
		len = intlen(n) + 1;
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	if (n < 0)
	{
		*out = '-';
		intwrite(n, out + 1, len - 1);
	}
	else
		intwrite(n, out, len);
	return (out);
}
