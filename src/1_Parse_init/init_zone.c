/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:34:42 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/29 17:18:29 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	check_wall_or_floor(t_data *data, uint32_t x, uint32_t y, char replace);

void	collect_map_struct(char c, t_data *data, uint32_t x, uint32_t y)
{
	if (ft_strchr(CHAR_FILL, c))
	{
		if (data->player.dir_angle != 0)
			ft_error_and_free_map("Too many players in the map", data);
		if (c == IS_WEST)
			data->player.dir_angle = 1.0 * PI;
		if (c == IS_SOUTH)
			data->player.dir_angle = 0.5 * PI;
		if (c == IS_EAST)
			data->player.dir_angle = 2.0 * PI;
		if (c == IS_NORTH)
			data->player.dir_angle = 1.5 * PI;
		data->player.dir_x = cos(data->player.dir_angle);
		data->player.dir_y = sin(data->player.dir_angle);
		data->player.x = (double)x + 0.5;
		data->player.y = (double)y + 0.5;
	}
}

void	check_adjacent_cells(t_data *data, uint32_t x, uint32_t y, char replace)
{
	if (replace == CHAR_FLOOR)
	{
		if (!ft_strchr(CHAR_F_W, data->map[y][x - 1]))
			check_wall_or_floor(data, x - 1, y, replace);
		if (!ft_strchr(CHAR_F_W, data->map[y - 1][x]))
			check_wall_or_floor(data, x, y - 1, replace);
		if (!ft_strchr(CHAR_F_W, data->map[y][x + 1]))
			check_wall_or_floor(data, x + 1, y, replace);
		if (!ft_strchr(CHAR_F_W, data->map[y + 1][x]))
			check_wall_or_floor(data, x, y + 1, replace);
	}
	else
	{
		if (!ft_strchr(IS_FILLED, data->map[y][x - 1]))
			check_wall_or_floor(data, x - 1, y, replace);
		if (!ft_strchr(IS_FILLED, data->map[y - 1][x]))
			check_wall_or_floor(data, x, y - 1, replace);
		if (!ft_strchr(IS_FILLED, data->map[y][x + 1])) 
			check_wall_or_floor(data, x + 1, y, replace);
		if (!ft_strchr(IS_FILLED, data->map[y + 1][x]))
			check_wall_or_floor(data, x, y + 1, replace);
	}
	return ;
}

void	check_wall_or_floor(t_data *data, uint32_t x, uint32_t y, char replace)
{
	if (x >= data->map_width || y >= data->map_height \
		|| data->map[y][x] == replace)
		return ;
	if (!ft_strchr(CHAR_MAP, data->map[y][x]) && BONUS == 0)
		ft_error_and_free_map("Invalid map. You can only use 01NSEW", data);
	if (!ft_strchr(CHAR_MAP_B, data->map[y][x]) && BONUS == 1)
		ft_error_and_free_map("Invalid map. You can only use 01NSEWDPC", data);
	if ((y == 0 && data->map[y][x] != CHAR_WALL) || \
		(x == 0 && data->map[y][x] != CHAR_WALL) || \
		(y == data->map_height - 1 && data->map[y][x] != CHAR_WALL) || \
		(x == data->map_width - 1 && data->map[y][x] != CHAR_WALL))
		ft_error_and_free_map("Map is not surrounded by walls", data);
	if (data->map[y][x] == IS_SPACE)
		ft_error_and_free_map("There is undefined space in the map", data);
	if (BONUS == 1)
	{
		if (data->map[y][x] == IS_DOOR)
			init_door(data, x, y);
		if (data->map[y][x] == IS_PUMPKIN)
			init_pumpkin(data, x, y);
		if (data->map[y][x] == IS_CANDY)
			init_candy(data, x, y);
	}
	data->map[y][x] = replace;
	return (check_adjacent_cells(data, x, y, replace));
}

void	init_zone(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			collect_map_struct(data->map[y][x], data, x, y);
			x++;
		}
		y++;
	}
	if (data->player.dir_angle == 0)
		ft_error_and_free_map("No player or invalid data in map file", data);
	check_wall_or_floor(data, data->player.x, data->player.y, IS_CHECKED);
	check_wall_or_floor(data, data->player.x, data->player.y, CHAR_FLOOR);
	put_door_on_map(data);
	init_minimap(data);
}
