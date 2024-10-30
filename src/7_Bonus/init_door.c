/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:49:09 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/29 16:02:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	init_door(t_data *data, uint32_t x, uint32_t y)
{
	int	i;

	i = data->door_count;
	data->doors[i].y = y;
	data->doors[i].x = x;
	data->door_count++;
	if (data->door_count >= MAX_DOORS)
		ft_error_general(data, "Too many doors in the map file");
}

void	put_door_on_map(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->door_count)
	{
		x = (int)data->doors[i].x;
		y = (int)data->doors[i].y;
		data->map[y][x] = IS_DOOR;
		i++;
	}
}

void	knock_door(t_data *data)
{
	int	d;
	int	x;
	int	y;

	d = 0;
	while (data->door_count > d)
	{
		if (data->doors[d].x - 0.5 < data->player.x && \
			data->doors[d].y - 0.5 < data->player.y && \
			data->player.x < data->doors[d].x + 1.5 && \
			data->player.y < data->doors[d].y + 1.5)
		{
			x = (int)data->doors[d].x;
			y = (int)data->doors[d].y;
			if ((data->map[y][x] == IS_DOOR) || 
				(data->doors[d].x < data->player.x && \
				data->doors[d].y < data->player.y && \
				data->doors[d].x + 1.0 > data->player.x && \
				data->doors[d].y + 1.0 > data->player.y))
				data->map[y][x] = IS_OPEN_DOOR;
			else
				data->map[y][x] = IS_DOOR;
		}
		d++;
	}
}
