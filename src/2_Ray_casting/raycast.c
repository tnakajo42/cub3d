/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:39:25 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/28 21:28:15 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	calculate_ray_data(t_data *data);
static void	get_distance(t_data *data);
static void	set_vertical(t_data *data);
static void	set_horizontal(t_data *data);

void	raycasting(t_data *d)
{
	d->ray.slice = d->image->width;
	d->ray.shift_factor = d->fov_factor;
	while (d->ray.slice--)
	{
		calculate_ray_data(d);
		get_distance(d);
		draw_current_slice(d);
		d->ray.shift_factor -= d->shift_dist;
	}
}

static void	calculate_ray_data(t_data *d)
{
	d->ray.x = d->player.dir_x - d->player.dir_y * d->ray.shift_factor;
	d->ray.y = d->player.dir_y + d->player.dir_x * d->ray.shift_factor;
	d->ray.delta_x = fabs(1 / d->ray.x);
	d->ray.delta_y = fabs(1 / d->ray.y);
	d->ray.hit_x = d->player.x;
	d->ray.hit_y = d->player.y;
	if (d->ray.x < 0)
	{
		d->ray.x_dir = -1;
		d->ray.dist_x = (d->player.x - d->ray.hit_x) * d->ray.delta_x;
	}
	else
	{
		d->ray.x_dir = 1;
		d->ray.dist_x = (d->ray.hit_x + 1.0 - d->player.x) * d->ray.delta_x;
	}
	if (d->ray.y < 0)
	{
		d->ray.y_dir = -1;
		d->ray.dist_y = (d->player.y - d->ray.hit_y) * d->ray.delta_y;
		return ;
	}
	d->ray.y_dir = 1;
	d->ray.dist_y = (d->ray.hit_y + 1.0 - d->player.y) * d->ray.delta_y;
}

// DDA-algorithm: passing vertical/horizontal grid lines recursively
static void	get_distance(t_data *d)
{
	char	horiz_hit;

	while (1)
	{
		if (d->ray.dist_x < d->ray.dist_y)
		{
			d->ray.dist_x += d->ray.delta_x;
			d->ray.hit_x += d->ray.x_dir;
			horiz_hit = 0;
		}
		else
		{
			d->ray.dist_y += d->ray.delta_y;
			d->ray.hit_y += d->ray.y_dir;
			horiz_hit = 1;
		}
		if (d->map[d->ray.hit_y][d->ray.hit_x] == CHAR_WALL ||
				d->map[d->ray.hit_y][d->ray.hit_x] == IS_DOOR)
			break ;
	}
	if (horiz_hit)
		set_horizontal(d);
	else
		set_vertical(d);
}

static void	set_vertical(t_data *d)
{
	if (d->ray.x_dir == 1)
	{
		d->ray.wall_dist[d->ray.slice] = (d->ray.hit_x - d->player.x)
			/ d->ray.x;
		d->ray.hit_texture = d->textures.east;
	}
	else
	{
		d->ray.wall_dist[d->ray.slice] = (d->ray.hit_x - d->player.x + 1)
			/ d->ray.x;
		d->ray.hit_texture = d->textures.west;
	}
	if (d->map[d->ray.hit_y][d->ray.hit_x] == IS_DOOR)
		d->ray.hit_texture = d->textures.closed_door;
	d->ray.hit_portion = d->player.y
		+ d->ray.wall_dist[d->ray.slice] * d->ray.y;
	d->ray.hit_portion -= floor(d->ray.hit_portion);
	if (d->ray.x_dir == -1)
		d->ray.hit_portion = 1.0 - d->ray.hit_portion;
}

static void	set_horizontal(t_data *d)
{
	if (d->ray.y_dir == 1)
	{
		d->ray.wall_dist[d->ray.slice] = (d->ray.hit_y - d->player.y)
			/ d->ray.y;
		d->ray.hit_texture = d->textures.south;
	}
	else
	{
		d->ray.wall_dist[d->ray.slice] = (d->ray.hit_y - d->player.y + 1)
			/ d->ray.y;
		if (BONUS)
			d->ray.hit_texture = d->anim.wall;
		else
			d->ray.hit_texture = d->textures.nord;
	}
	if (d->map[d->ray.hit_y][d->ray.hit_x] == IS_DOOR)
		d->ray.hit_texture = d->textures.closed_door;
	d->ray.hit_portion = d->player.x
		+ d->ray.wall_dist[d->ray.slice] * d->ray.x;
	d->ray.hit_portion -= floor(d->ray.hit_portion);
	if (d->ray.y_dir == 1)
		d->ray.hit_portion = 1.0 - d->ray.hit_portion;
}
