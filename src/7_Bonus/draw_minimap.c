/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:33:11 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/28 22:50:15 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* half size of player size */
void	draw_enemies(t_data *data)
{
	int	px;
	int	py;
	int	d;

	d = -1;
	while (++d < MAX_ENEMY)
	{
		if (!data->enemy[d].visible)
			continue ;
		py = -data->enemy_size;
		while (py <= data->enemy_size)
		{
			px = -data->enemy_size;
			while (px <= data->enemy_size)
			{
				color_pixel(data->mini_img,
					(uint32_t)(data->enemy[d].x * data->mini_img_size) + px,
					(uint32_t)(data->enemy[d].y * data->mini_img_size) + py,
					MINIMAP_ENEMY_COLOR);
				px++;
			}
			py++;
		}
	}
}

void	draw_player(t_data *data)
{
	int	player_size;
	int	px;
	int	py;

	player_size = data->mini_img_size * data->mini_map_player / 10;
	py = -player_size;
	while (py <= player_size)
	{
		px = -player_size;
		while (px <= player_size)
		{
			color_pixel(data->mini_img, \
				(int)(data->player.x * data->mini_img_size) + px, \
				(int)(data->player.y * data->mini_img_size) + py, \
				MINIMAP_PLAYER_COLOR);
			px++;
		}
		py++;
	}
	draw_player_direction(data);
	draw_enemies(data);
	if (!data->mini_img->instances)
		mlx_image_to_window(data->mlx, data->mini_img, 10, 10);
}

/* Draw a data->mini_img_size x data->mini_img_size square for each map tile */
void	draw_minimap_sub(t_data *data, uint32_t color, int x, int y)
{
	int	x_sub;
	int	y_sub;

	y_sub = 0;
	while (y_sub < data->mini_img_size)
	{
		x_sub = 0;
		while (x_sub < data->mini_img_size)
		{
			color_pixel(data->mini_img, x * data->mini_img_size + \
				x_sub, y * data->mini_img_size + y_sub, color);
			x_sub++;
		}
		y_sub++;
	}
}

void	draw_minimap(t_data *data)
{
	int			x;
	int			y;
	uint32_t	color;

	y = 0;
	while (y < (int)data->map_height)
	{
		x = 0;
		while (x < (int)data->map_width)
		{
			if (data->map[y][x] == IS_DOOR)
				color = MINIMAP_DOOR_COLOR;
			else if (data->map[y][x] == CHAR_FLOOR)
				color = MINIMAP_FLOOR_COLOR;
			else if (data->map[y][x] == IS_OPEN_DOOR)
				color = MINIMAP_OPEN_DOOR_COLOR;
			else
				color = MINIMAP_UNDER_FLOOR;
			draw_minimap_sub(data, color, x, y);
			x++;
		}
		y++;
	}
	draw_player(data);
}
