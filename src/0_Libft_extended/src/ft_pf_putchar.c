/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:38:47 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:03 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Writes char c to stout including given [width]
int	ft_pf_putchar(char c, t_subs *subs)
{
	if (!subs->flag_minus && subs->width > 1)
		ft_pf_repchar(' ', subs->width - 1);
	write(1, &c, 1);
	if (subs->flag_minus && subs->width > 1)
		ft_pf_repchar(' ', subs->width - 1);
	if (subs->width > 1)
		return (subs->width);
	return (1);
}

int	ft_pf_putperc(void)
{
	write(1, "%", 1);
	return (1);
}
