/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:35:44 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/29 16:05:56 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* 
	if (data->textures.nord)
		mlx_delete_texture(data->textures.nord);
	if (data->textures.west)
		mlx_delete_texture(data->textures.west);
	if (data->textures.east)
		mlx_delete_texture(data->textures.east);
	if (data->textures.south)
		mlx_delete_texture(data->textures.south);
 */
void	clean_up(t_data *data)
{
	if (data->image)
		mlx_delete_image(data->mlx, data->image);
	if (data->fd)
		close(data->fd);
	ft_free_map(data, data->map);
	ft_free_walls(data);
	if (BONUS)
		clean_up_bonus(data);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

void	clean_up_bonus(t_data *data)
{
	int	size;

	size = -1;
	while (++size < 6)
	{
		if (data->textures.wall[size])
			mlx_delete_texture(data->textures.wall[size]);
		if (data->textures.pumpkin[size])
			mlx_delete_texture(data->textures.pumpkin[size]);
		if (data->textures.candy[size])
			mlx_delete_texture(data->textures.candy[size]);
		if (data->textures.life[size])
			mlx_delete_texture(data->textures.life[size]);
	}
	if (data->textures.closed_door)
		mlx_delete_texture(data->textures.closed_door);
}

	// free_tex_slice(&data->textures.wall[0], 6);
	// free_tex_slice(&data->textures.pumpkin[0], 6);
	// free_tex_slice(&data->textures.candy[0], 6);
	// free_tex_slice(&data->textures.life[0], 6);

void	ft_free_map(t_data *data, char **target)
{
	int	i;

	if (!target || !*target)
		ft_error_general(data, "Map data not found or invalid");
	i = 0;
	while (target[i] != NULL)
	{
		free(target[i]);
		i++;
	}
	free(target);
}

void	ft_free_walls(t_data *data)
{
	if (data->walls.north)
		free(data->walls.north);
	if (data->walls.south)
		free(data->walls.south);
	if (data->walls.west)
		free(data->walls.west);
	if (data->walls.east)
		free(data->walls.east);
	if (data->walls.floor_row)
		free(data->walls.floor_row);
	if (data->walls.ceiling_row)
		free(data->walls.ceiling_row);
	if (data->textures.nord)
		mlx_delete_texture(data->textures.nord);
	if (data->textures.west)
		mlx_delete_texture(data->textures.west);
	if (data->textures.east)
		mlx_delete_texture(data->textures.east);
	if (data->textures.south)
		mlx_delete_texture(data->textures.south);
}

void	free_tex_slice(mlx_texture_t **tex_slice, size_t size)
{
	while (size--)
	{
		if (*tex_slice)
			mlx_delete_texture(*tex_slice);
		tex_slice++;
	}
}
