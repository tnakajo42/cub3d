/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_hearts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:01:24 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/27 21:51:18 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	put_heart(t_data *data, uint32_t x_0, uint32_t state);

void	show_life_hearts(t_data *data)
{
	uint32_t	heart_start;
	uint32_t	diff;
	uint32_t	heart_nr;

	diff = data->scaled_heart_width + data->offset;
	heart_start = data->image->width - 5 * diff;
	heart_nr = 5;
	while (heart_nr)
	{
		if (data->player.life >= heart_nr-- *5)
			put_heart(data, heart_start, 5);
		else if (data->player.life < heart_nr * 5)
			put_heart(data, heart_start, 0);
		else
			put_heart(data, heart_start, data->player.life % 5);
		heart_start += diff;
	}
}

static void	put_heart(t_data *data, uint32_t x_0, uint32_t state)
{
	uint32_t	x_wr;
	uint32_t	y_wr;
	uint32_t	tex_x;
	uint32_t	tex_y;
	uint32_t	color;

	x_wr = x_0 + data->scaled_heart_width;
	while (x_wr-- > x_0)
	{
		y_wr = data->offset + data->scaled_heart_height;
		while (y_wr-- > data->offset)
		{
			tex_x = (x_wr - x_0) / data->heart_scaling;
			tex_y = (y_wr - data->offset) / data->heart_scaling;
			color = get_pixel_color(data->textures.life[state], tex_x, tex_y);
			if (color)
				color_pixel(data->image, x_wr, y_wr, color);
		}
	}
}
