/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:09 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:05 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pf_hexlen(unsigned int input)
{
	int	len;

	if (!input)
		return (1);
	len = 0;
	while (input)
	{
		input /= 16;
		len++;
	}
	return (len);
}

void	write_hex(unsigned int input, char *set, int len)
{
	char	tmp;

	if (input > 15 || len > 0)
		write_hex(input / 16, set, len - 1);
	if (input % 16 > 9)
		tmp = set[input % 16 - 8];
	else
		tmp = input % 16 + '0';
	if (len > 0)
		write(1, &tmp, 1);
}

int	ft_pf_puthex(char *set, unsigned int input, t_subs *subs)
{
	int				len;

	len = ft_pf_hexlen(input);
	if (subs->precision > len || (!subs->precision && !input))
		len = subs->precision;
	if (subs->flag_hash && input)
		subs->width -= 2;
	subs->width -= len;
	if (!subs->flag_minus && (!subs->flag_zero || subs->precision >= 0))
		ft_pf_repchar(' ', subs->width);
	if (subs->flag_hash && input)
		write(1, set, 2);
	if (!subs->flag_minus && subs->flag_zero && subs->precision < 0)
		ft_pf_repchar('0', subs->width);
	write_hex(input, set, len);
	if (subs->flag_minus)
		ft_pf_repchar(' ', subs->width);
	if (subs->flag_hash && input)
		len += 2;
	if (subs->width > 0)
		return (len + subs->width);
	return (len);
}
