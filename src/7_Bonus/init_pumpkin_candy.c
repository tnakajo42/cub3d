/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pumpkin_candy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:29:57 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/29 16:02:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	init_pumpkin(t_data *data, uint32_t x, uint32_t y)
{
	int	i;

	i = data->enemy_count;
	data->enemy[i].visible = 1;
	data->enemy[i].x = x;
	data->enemy[i].y = y;
	data->enemy[i].mov_x = 0.05;
	data->enemy[i].mov_y = 0;
	data->enemy[i].appearance = &data->anim.pumpkin;
	data->enemy[i].dist = 10;
	data->enemy[i].damage = 4;
	data->enemy_count++;
	if (data->enemy_count >= MAX_ENEMY)
		ft_error_general(data, "Too many enemies on the map");
}

void	init_candy(t_data *data, uint32_t x, uint32_t y)
{
	int	i;

	i = data->enemy_count;
	data->enemy[i].visible = 1;
	data->enemy[i].x = x;
	data->enemy[i].y = y;
	data->enemy[i].mov_x = 0.02;
	data->enemy[i].mov_y = 0;
	data->enemy[i].appearance = &data->anim.candy;
	data->enemy[i].dist = 10;
	data->enemy[i].damage = 15;
	data->enemy_count++;
	if (data->enemy_count >= MAX_ENEMY)
		ft_error_general(data, "Too many enemies on the map");
}
