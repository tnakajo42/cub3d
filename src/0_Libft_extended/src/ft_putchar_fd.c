/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:32:09 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:30 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Outputs the character ’c’ to the given file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
