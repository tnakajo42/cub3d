/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:43:39 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:47 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Deletes and frees the given node and every successor of that node, using the 
// func ’del’ and free. Finally, the pointer to the list must be set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**end;
	t_list	*tmp;

	if (del)
	{
		end = lst;
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		*end = NULL;
	}
}
