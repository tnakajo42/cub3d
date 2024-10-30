/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:29:24 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:15 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pf_ptrlen(size_t input)
{
	int	len;

	if (!input)
		return (3);
	len = 0;
	while (input)
	{
		input /= 16;
		len++;
	}
	return (len);
}

void	write_ptr(size_t input)
{
	char	tmp;

	if (input > 15)
		write_ptr(input / 16);
	if (input % 16 > 9)
		tmp = 'a' + input % 16 - 10;
	else
		tmp = '0' + input % 16;
	write(1, &tmp, 1);
}

int	ft_pf_putptr(void *ptr, t_subs *subs)
{
	int	len;

	len = ft_pf_ptrlen((size_t)ptr) + 2;
	if (!subs->flag_minus && subs->width > len)
		ft_pf_repchar(' ', subs->width - len);
	if (!ptr)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		write_ptr((size_t)ptr);
	}
	if (subs->flag_minus && subs->width > len)
		ft_pf_repchar(' ', subs->width - len);
	if (subs->width > len)
		return (subs->width);
	return (len);
}
