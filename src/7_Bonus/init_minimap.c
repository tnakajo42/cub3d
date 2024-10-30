/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:29:18 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/29 16:02:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	init_minimap(t_data *data)
{
	uint32_t	minimap_width;
	uint32_t	minimap_height;

	data->mini_img_size = MINI_IMG_SIZE;
	data->mini_map_player = MINI_CHARACTER_SIZE;
	data->player.life = MAX_LIFE;
	minimap_width = data->map_width * data->mini_img_size;
	minimap_height = data->map_height * data->mini_img_size;
	data->mini_img = mlx_new_image(data->mlx, minimap_width, minimap_height);
	if (!data->mini_img)
		ft_error_general(data, "Failed to create the minimap image");
}
