/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:35:04 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:10 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pf_intlen(int input)
{
	int	len;

	len = 0;
	while (input)
	{
		input /= 10;
		len++;
	}
	return (len);
}

void	write_int(int input, int len)
{
	char	tmp;

	if (input > 9 || input < -9 || len > 0)
		write_int(input / 10, len - 1);
	if (input < 0)
		tmp = '0' - input % 10;
	else
		tmp = '0' + input % 10;
	if (input || len > 0)
		write(1, &tmp, 1);
}

int	ft_pf_putint(int input, int len, t_subs *subs)
{
	if (input)
		len = ft_pf_intlen(input);
	if (subs->precision > len || (!subs->precision && !input))
		len = subs->precision;
	if (input < 0 || subs->flag_plus || subs->flag_space)
		subs->width--;
	subs->width -= len;
	if (!subs->flag_minus && (!subs->flag_zero || subs->precision >= 0))
		ft_pf_repchar(' ', subs->width);
	if (input < 0)
		write(1, "-", 1);
	else if (subs->flag_plus)
		write(1, "+", 1);
	else if (subs->flag_space)
		write(1, " ", 1);
	if (!subs->flag_minus && subs->flag_zero && subs->precision < 0)
		ft_pf_repchar('0', subs->width);
	write_int(input, len);
	if (subs->flag_minus)
		ft_pf_repchar(' ', subs->width);
	if (input < 0 || subs->flag_plus || subs->flag_space)
		len++;
	if (subs->width > 0)
		return (len + subs->width);
	return (len);
}
