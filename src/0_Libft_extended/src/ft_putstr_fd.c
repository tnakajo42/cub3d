/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:44:31 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:38 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Outputs the string ’s’ to the given file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
