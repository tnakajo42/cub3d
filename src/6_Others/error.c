/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:35:37 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/30 15:21:59 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

// with argument messages
void	ft_error_general(t_data *data, char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	if (data->fd)
		close(data->fd);
	exit(1);
}

void	ft_error_and_free_map(char *msg, t_data *data)
{
	ft_printf("[ERROR] %s\n", msg);
	clean_up(data);
	exit(1);
}

void	check_argument(int ac, char **av)
{
	int	file_len;

	if (ac != 2)
	{
		ft_printf("Wrong number of arguments! \
			Try: make && ./cub3D ./map/map00.cub\n");
		exit(1);
	}
	file_len = ft_strlen(av[1]);
	if (file_len < 4)
	{
		ft_printf("Invalid map file name\n");
		exit(1);
	}
	if (ft_strnstr(&av[1][file_len - 4], ".cub", 4) == NULL)
	{
		ft_printf("Invalid map file name\n");
		exit(1);
	}
}
