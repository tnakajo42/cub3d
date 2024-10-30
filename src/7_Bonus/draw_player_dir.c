/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:38:28 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/28 23:02:49 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	initialize_coordinates(t_data *data)
{
	data->player_dir.px = (int)(data->player.x * data->mini_img_size);
	data->player_dir.py = (int)(data->player.y * data->mini_img_size);
	data->player_dir.ex = data->player_dir.px + \
		(int)(cos(data->player.dir_angle) * data->mini_img_size);
	data->player_dir.ey = data->player_dir.py + \
		(int)(sin(data->player.dir_angle) * data->mini_img_size);
}

void	initialize_drawing_parameters(t_data *data)
{
	data->player_dir_line.dx = ft_abs(data->player_dir.ex - \
		data->player_dir.px);
	data->player_dir_line.dy = ft_abs(data->player_dir.ey - \
		data->player_dir.py);
	if (data->player_dir.px < data->player_dir.ex)
		data->player_dir_line.sx = 1;
	else
		data->player_dir_line.sx = -1;
	if (data->player_dir.py < data->player_dir.ey)
		data->player_dir_line.sy = 1;
	else
		data->player_dir_line.sy = -1;
	if (data->player_dir_line.dx > data->player_dir_line.dy)
		data->player_dir_line.err = data->player_dir_line.dx / 2;
	else
		data->player_dir_line.err = -data->player_dir_line.dy / 2;
}

void	draw_line(t_data *data)
{
	int	e2;
	int	px;
	int	py;

	px = data->player_dir.px;
	py = data->player_dir.py;
	while (1)
	{
		color_pixel(data->mini_img, px, py, MINIMAP_DIRECTION_COLOR);
		if (px == data->player_dir.ex && py == data->player_dir.ey)
			break ;
		e2 = data->player_dir_line.err;
		if (e2 > -data->player_dir_line.dx)
		{
			data->player_dir_line.err -= data->player_dir_line.dy;
			px += data->player_dir_line.sx;
		}
		if (e2 < data->player_dir_line.dy)
		{
			data->player_dir_line.err += data->player_dir_line.dx;
			py += data->player_dir_line.sy;
		}
	}
}

void	draw_player_direction(t_data *data)
{
	initialize_coordinates(data);
	initialize_drawing_parameters(data);
	draw_line(data);
}

/* void	draw_player_direction(t_data *data)
{
	int	px; 
	int	py;
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	px = (int)(data->player.x * data->mini_img_size);
	py = (int)(data->player.y * data->mini_img_size);
	ex = px + (int)(cos(data->player.dir_angle) * data->mini_img_size);
	ey = py + (int)(sin(data->player.dir_angle) * data->mini_img_size);

	if (ex > px)
		dx = ex - px;
	else
		dx = px - ex;

	if (ey > py)
		dy = ey - py;
	else
		dy = py - ey;

	if (px < ex)
		sx = 1; 
	else
		sx = -1;

	if (py < ey)
		sy = 1;
	else
		sy = -1;

	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;

	while (1)
	{
		color_pixel(data->mini_img, px, py, MINIMAP_DIRECTION_COLOR);
		if (px == ex && py == ey)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			px += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			py += sy;
		}
	}
} */
