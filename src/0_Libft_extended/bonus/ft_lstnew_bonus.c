/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:23:49 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:16:02 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with the value of the parameter 
// ’content’. The variable ’next’ is initialized to NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (0);
	out->content = content;
	out->next = NULL;
	return (out);
}
