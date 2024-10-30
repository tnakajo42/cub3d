/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:24 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:16:29 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_split_free(char **split)
{
	char	**writer;

	writer = split;
	while (*writer)
	{
		free(*writer);
		writer++;
	}
	free(split);
}
