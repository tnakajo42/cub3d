/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:35:17 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/28 19:00:35 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	load_textures(t_data *data)
{
	data->textures.nord = mlx_load_png(data->walls.north);
	data->textures.east = mlx_load_png(data->walls.east);
	data->textures.west = mlx_load_png(data->walls.west);
	data->textures.south = mlx_load_png(data->walls.south);
	if (!data->textures.nord || !data->textures.east
		|| !data->textures.west || !data->textures.south)
		return (0);
	if (BONUS == 1 && !load_bonus_textures(data))
		return (0);
	return (1);
}
