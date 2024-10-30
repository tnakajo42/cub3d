/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:23 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:59 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Iterates the list ’lst’ and applies the function ’f’ on the content of each 
// node. Creates a new list resulting of the successive applications of the 
// func ’f’. The ’del’ func is used to delete the content of a node if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new;

	if (!lst)
		return (0);
	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (0);
	new = out;
	new->content = (*f)(lst->content);
	lst = lst->next;
	while (lst)
	{
		new->next = (t_list *)malloc(sizeof(t_list));
		if (!new->next)
		{
			ft_lstclear(&out, del);
			return (0);
		}
		new = new->next;
		new->content = (*f)(lst->content);
		lst = lst->next;
	}
	new->next = NULL;
	return (out);
}
