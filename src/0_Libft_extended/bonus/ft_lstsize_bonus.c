/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:09:42 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:16:05 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Counts the number of nodes in a list.
int	ft_lstsize(t_list *lst)
{
	int	nmb;

	nmb = 0;
	while (lst)
	{
		nmb++;
		lst = lst->next;
	}
	return (nmb);
}
