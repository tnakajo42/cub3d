/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:55:51 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:35 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	void	fd_rec_write(int n, int fd)
{
	char	tmp;

	if (n < -9 || n > 9)
		fd_rec_write(n / 10, fd);
	if (n < 0)
		tmp = '0' - n % 10;
	else
		tmp = '0' + n % 10;
	write(fd, &tmp, 1);
}

// Outputs the integer ’n’ to the given file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	fd_rec_write(n, fd);
}
