/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_new_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:21:36 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/28 23:28:16 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	move_player(t_data *d);
static void	put_enemies(t_data *data);
static void	put_descending(t_data *data, int *next, int *index);
static void	calculate_move_dist(t_data *d, double *part_x, double *part_y);

void	get_new_frame(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->player.turn)
	{
		data->player.dir_angle += data->player.turn;
		data->player.dir_x = cos(data->player.dir_angle);
		data->player.dir_y = sin(data->player.dir_angle);
	}
	if (data->player.front || data->player.side)
		move_player(data);
	raycasting(data);
	if (BONUS)
	{
		put_enemies(data);
		draw_minimap(data);
		show_life_hearts(data);
	}
}

// Finds the enemy with the largest distance ...
static void	put_enemies(t_data *data)
{
	int		next;
	int		index;

	index = -1;
	next = MAX_ENEMY;
	while (next--)
	{
		if (!data->enemy[next].visible)
			continue ;
		if (index == -1)
			index = next;
		else if (data->enemy[next].dist > data->enemy[index].dist)
			index = next;
	}
	put_descending(data, &next, &index);
}

// ... and draws enemies from their distance in descending order
static void	put_descending(t_data *data, int *next, int *index)
{
	double	dist;

	while (*index != -1)
	{
		dist = data->enemy[*index].dist;
		enemy_to_image(data, &data->enemy[*index]);
		*index = -1;
		*next = MAX_ENEMY;
		while ((*next)--)
		{
			if (!data->enemy[*next].visible)
				continue ;
			if (*index == -1 && data->enemy[*next].dist < dist)
				*index = *next;
			else if (data->enemy[*next].dist < dist && data->enemy[*next].dist \
				> data->enemy[*index].dist)
				*index = *next;
		}
	}
}

static void	move_player(t_data *d)
{
	double	part_x;
	double	part_y;

	part_x = 0;
	part_y = 0;
	calculate_move_dist(d, &part_x, &part_y);
	if (d->map[(int)d->player.y][(int)(d->player.x + part_x)] == CHAR_FLOOR ||
		d->map[(int)d->player.y][(int)(d->player.x + part_x)] == IS_OPEN_DOOR)
		d->player.x += part_x;
	if (d->map[(int)(d->player.y + part_y)][(int)d->player.x] == CHAR_FLOOR || 
		d->map[(int)(d->player.y + part_y)][(int)d->player.x] == IS_OPEN_DOOR)
		d->player.y += part_y;
}

static void	calculate_move_dist(t_data *d, double *part_x, double *part_y)
{
	double	movement;

	movement = STEP;
	if (d->player.front && d->player.side)
		movement *= 0.5;
	if (d->player.front == 1)
	{
		*part_x += movement * d->player.dir_x;
		*part_y += movement * d->player.dir_y;
	}
	else if (d->player.front == -1)
	{
		*part_x -= movement * d->player.dir_x;
		*part_y -= movement * d->player.dir_y;
	}
	if (d->player.side == 1)
	{
		*part_x -= movement * d->player.dir_y;
		*part_y += movement * d->player.dir_x;
	}
	else if (d->player.side == -1)
	{
		*part_x += movement * d->player.dir_y;
		*part_y -= movement * d->player.dir_x;
	}
}
