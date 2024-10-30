/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:26:25 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/27 21:29:10 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	zoom_out(t_data *data);
static void	zoom_in(t_data *data);

/* Draws the current slice in its scaling to the image */
void	draw_current_slice(t_data *data)
{
	data->ray.slice_height = (uint32_t)(data->image->height / \
		data->ray.wall_dist[data->ray.slice]);
	data->ray.texture_x = data->ray.hit_texture->width * data->ray.hit_portion;
	if (data->ray.slice_height > data->image->height)
		zoom_in(data);
	else
		zoom_out(data);
}

/* Puts a wall slice, which is mapped smaller than image height */
static void	zoom_out(t_data *data)
{
	uint32_t	rest;
	double		ratio;
	uint32_t	i;
	uint32_t	color;

	rest = (data->image->height - data->ray.slice_height) / 2;
	ratio = (double)data->ray.hit_texture->height / data->ray.slice_height;
	i = 0;
	while (i < rest)
		color_pixel(data->image, data->ray.slice, i++, \
			data->walls.ceiling_color);
	while (i < data->image->height - rest)
	{
		color = get_pixel_color(data->ray.hit_texture, \
			data->ray.texture_x, ratio * (i - rest));
		color_pixel(data->image, data->ray.slice, i++, color);
	}
	while (i < data->image->height)
		color_pixel(data->image, data->ray.slice, i++, data->walls.floor_color);
}

/**
 * Puts a wall slice, which is mapped
 * bigger than image height (zooms into a part of it)
 */
static void	zoom_in(t_data *data)
{
	uint32_t	start;
	double		ratio;
	uint32_t	i;
	uint32_t	color;

	start = ((double)data->ray.slice_height - data->image->height) \
		* data->ray.hit_texture->height / data->ray.slice_height / 2;
	ratio = (double)data->ray.hit_texture->height / data->ray.slice_height;
	i = 0;
	while (i < data->image->height)
	{
		color = get_pixel_color(data->ray.hit_texture, \
			data->ray.texture_x, start + ratio * i);
		color_pixel(data->image, data->ray.slice, i++, color);
	}
}
