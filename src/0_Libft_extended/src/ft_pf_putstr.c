/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:31:39 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:21 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pf_strlen(char *str)
{
	int	str_len;

	str_len = 0;
	while (*(str++))
		str_len++;
	return (str_len);
}

void	ft_pf_repchar(char c, int rep)
{
	while (rep-- > 0)
		write(1, &c, 1);
}

int	print_str(char *str, int other, t_subs *subs)
{
	if (subs->width > other && !subs->flag_minus)
		ft_pf_repchar(' ', subs->width - other);
	write(1, str, other);
	if (subs->width > other && subs->flag_minus)
		ft_pf_repchar(' ', subs->width - other);
	if (subs->width > other)
		return (subs->width);
	return (other);
}

int	ft_pf_putstr(char *str, t_subs *subs)
{
	int		str_len;

	if (!str && subs->precision >= 0 && subs->precision < 6)
		str = "";
	else if (!str)
		str = "(null)";
	str_len = ft_pf_strlen(str);
	if (subs->precision >= 0 && subs->precision < str_len)
		return (print_str(str, subs->precision, subs));
	else
		return (print_str(str, str_len, subs));
}

int	ft_pf_atoi(const char **string)
{
	long	res;

	res = 0;
	while (**string >= '0' && **string <= '9')
	{
		res = 10 * res + (long)**string - '0';
		if (res > 2147483647L)
			return (-1);
		(*string)++;
	}
	return ((int)res);
}
