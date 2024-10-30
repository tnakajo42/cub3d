/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:35:58 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:23 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pf_unsignedlen(unsigned int input)
{
	int	len;

	if (!input)
		return (1);
	len = 0;
	while (input)
	{
		input /= 10;
		len++;
	}
	return (len);
}

void	write_unsigned(unsigned int input, int len)
{
	char	tmp;

	if (input > 9 || len > 0)
		write_unsigned(input / 10, len - 1);
	tmp = '0' + input % 10;
	if (input || len > 0)
		write(1, &tmp, 1);
}

int	ft_pf_putunsigned(unsigned int input, t_subs *subs)
{
	int	len;

	len = ft_pf_unsignedlen(input);
	if (subs->precision > len || (!subs->precision && !input))
		len = subs->precision;
	subs->width -= len;
	if (!subs->flag_minus && subs->flag_zero && subs->precision < 0)
		ft_pf_repchar('0', subs->width);
	else if (!subs->flag_minus)
		ft_pf_repchar(' ', subs->width);
	write_unsigned(input, len);
	if (subs->flag_minus)
		ft_pf_repchar(' ', subs->width);
	if (subs->width > 0)
		return (len + subs->width);
	return (len);
}
