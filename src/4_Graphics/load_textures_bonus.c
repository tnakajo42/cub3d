/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:23:36 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/29 17:48:10 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static int	load_pumpkin(t_data *data);
static int	load_animated_walls(t_data *data);
static int	load_candy(t_data *data);
static int	load_life(t_data *data);

int	load_bonus_textures(t_data *data)
{
	data->textures.closed_door = mlx_load_png("images/door.png");
	if (!data->textures.closed_door)
	{
		printf("Failed to load sprite texture!\n");
		mlx_terminate(data->mlx);
		return (0);
	}
	if (!load_pumpkin(data) || !load_animated_walls(data)
		|| !load_candy(data) || !load_life(data))
		return (0);
	data->anim.pumpkin = data->textures.pumpkin[0];
	data->anim.candy = data->textures.candy[0];
	data->anim.wall = data->textures.wall[0];
	return (1);
}

/* Rotating pumpkin enemy; Source:
https://www.pngitem.com/middle/
TRbiiRm_pumpkin-clipart-spinning-png-clipart-freeuse-download-pumpkin/ */
static int	load_pumpkin(t_data *data)
{
	size_t	i;

	data->textures.pumpkin[0] = mlx_load_png("images/animated/P1.png");
	data->textures.pumpkin[1] = mlx_load_png("images/animated/P2.png");
	data->textures.pumpkin[2] = mlx_load_png("images/animated/P3.png");
	data->textures.pumpkin[3] = mlx_load_png("images/animated/P4.png");
	data->textures.pumpkin[4] = mlx_load_png("images/animated/P5.png");
	data->textures.pumpkin[5] = mlx_load_png("images/animated/P6.png");
	i = 6;
	while (i--)
	{
		if (!data->textures.pumpkin[i])
		{
			printf("Failed to load pumpkin textures!\n");
			mlx_terminate(data->mlx);
			return (0);
		}
	}
	return (1);
}

// Stone wall with moving torch
static int	load_animated_walls(t_data *data)
{
	size_t	i;

	data->textures.wall[0] = mlx_load_png("images/animated/wall_torch_01.png");
	data->textures.wall[1] = mlx_load_png("images/animated/wall_torch_02.png");
	data->textures.wall[2] = mlx_load_png("images/animated/wall_torch_03.png");
	data->textures.wall[3] = mlx_load_png("images/animated/wall_torch_04.png");
	data->textures.wall[4] = mlx_load_png("images/animated/wall_torch_05.png");
	data->textures.wall[5] = mlx_load_png("images/animated/wall_torch_06.png");
	i = 6;
	while (i--)
	{
		if (!data->textures.wall[i])
		{
			printf("Failed to load animated wall textures!\n");
			mlx_terminate(data->mlx);
			return (0);
		}
	}
	return (1);
}

// Candy enemy with movement
static int	load_candy(t_data *data)
{
	size_t	i;

	data->textures.candy[0] = mlx_load_png("images/animated/bl_candy_01.png");
	data->textures.candy[1] = mlx_load_png("images/animated/bl_candy_02.png");
	data->textures.candy[2] = mlx_load_png("images/animated/bl_candy_03.png");
	data->textures.candy[3] = mlx_load_png("images/animated/bl_candy_04.png");
	data->textures.candy[4] = mlx_load_png("images/animated/bl_candy_05.png");
	data->textures.candy[5] = mlx_load_png("images/animated/bl_candy_06.png");
	i = 6;
	while (i--)
	{
		if (!data->textures.candy[i])
		{
			printf("Failed to load candy textures!\n");
			mlx_terminate(data->mlx);
			return (0);
		}
	}
	return (1);
}

// Source of the heart sprite:
static int	load_life(t_data *data)
{
	size_t	i;

	data->textures.life[0] = mlx_load_png("images/life/life_00.png");
	data->textures.life[1] = mlx_load_png("images/life/life_01.png");
	data->textures.life[2] = mlx_load_png("images/life/life_02.png");
	data->textures.life[3] = mlx_load_png("images/life/life_03.png");
	data->textures.life[4] = mlx_load_png("images/life/life_04.png");
	data->textures.life[5] = mlx_load_png("images/life/life_05.png");
	i = 6;
	while (i--)
	{
		if (!data->textures.pumpkin[i])
		{
			printf("Failed to load pumpkin textures!\n");
			mlx_terminate(data->mlx);
			return (0);
		}
	}
	return (1);
}
