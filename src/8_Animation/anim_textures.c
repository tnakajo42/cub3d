/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:25:39 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/28 23:12:23 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	move_circles(t_data *data, t_enemy *enemy);
static void	try_to_move_y(t_data *data, t_enemy *en);
static void	calculate_enemy(t_data *data, t_enemy *enemy);

void	animate(void *param)
{
	t_data	*data;
	double	time;
	size_t	n;

	data = (t_data *)param;
	time = fmod(mlx_get_time(), 0.75);
	n = 6;
	while (n--)
	{
		if (time >= n * 0.125)
		{
			data->anim.wall = data->textures.wall[n];
			data->anim.pumpkin = data->textures.pumpkin[n];
			data->anim.candy = data->textures.candy[n];
			break ;
		}
	}
	n = MAX_ENEMY;
	while (n--)
	{
		if (!data->enemy[n].visible)
			continue ;
		move_circles(data, &data->enemy[n]);
		calculate_enemy(data, &data->enemy[n]);
	}
}

// Moves an enemy circular
static void	move_circles(t_data *data, t_enemy *en)
{
	char	new;

	if (en->mov_x)
	{
		if (en->mov_x < 0)
			new = data->map[(int) en->y][(int)(en->x + en->mov_x - WALL_DST)];
		else
			new = data->map[(int) en->y][(int)(en->x + en->mov_x + WALL_DST)];
		if (new == CHAR_FLOOR || new == IS_OPEN_DOOR)
			en->x += en->mov_x;
		else
		{
			en->mov_y = en->mov_x;
			en->mov_x = 0;
		}
	}
	else
		try_to_move_y(data, en);
}

static void	try_to_move_y(t_data *data, t_enemy *en)
{
	char	new;

	if (en->mov_y < 0)
		new = data->map[(int)(en->y + en->mov_y - WALL_DST)][(int)en->x];
	else
		new = data->map[(int)(en->y + en->mov_y + WALL_DST)][(int)en->x];
	if (new == CHAR_FLOOR || new == IS_OPEN_DOOR)
		en->y += en->mov_y;
	else
	{
		en->mov_x = -en->mov_y;
		en->mov_y = 0;
	}
}

// gets distance and angle to enemy, and calculates its image slice
static void	calculate_enemy(t_data *data, t_enemy *enemy)
{
	double	en_dir_x;
	double	en_dir_y;
	double	dot_prod;
	double	cross_prod;

	en_dir_x = enemy->x - data->player.x;
	en_dir_y = enemy->y - data->player.y;
	enemy->dist = hypot(en_dir_x, en_dir_y);
	if (enemy->dist < 0.55 && mlx_get_time() - enemy->last_hit > 1)
	{
		damage_life(data, enemy->damage);
		enemy->last_hit = mlx_get_time();
	}
	dot_prod = en_dir_x * data->player.dir_x + en_dir_y * data->player.dir_y;
	cross_prod = data->player.dir_x * en_dir_y - data->player.dir_y * en_dir_x;
	if (cross_prod < 0)
		enemy->angle = -acos(dot_prod / enemy->dist);
	else
		enemy->angle = acos(dot_prod / enemy->dist);
	enemy->slice = enemy->angle / (data->shift_dist - 0.00015) + 400;
}
