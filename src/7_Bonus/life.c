/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:29:18 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/29 17:47:15 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	damage_life(t_data *data, uint32_t damage)
{
	if (data->player.life <= damage)
		ft_error_and_free_map("Good luck in your next life", data);
	data->player.life -= damage;
}

void	init_life(t_data *data)
{
	data->heart_scaling = (double) data->image->height \
		/ data->textures.life[0]->height / 15;
	data->offset = data->image->height / 40;
	data->scaled_heart_width = data->textures.life[0]->width \
		* data->heart_scaling;
	data->scaled_heart_height = data->image->height / 15;
}
