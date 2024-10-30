/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:36:32 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/22 19:06:28 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/*
INFO:
Color coding in Hex is 0x_a_b_g_r
but is in BYTE: r_g_b_a (is it little endian ?!)
*/

// Mix RGBA to get the corresponding uint (4 byte)
uint32_t	mix_pixel_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

// Returns the texture pixel color in x, y.
uint32_t	get_pixel_color(mlx_texture_t *texture, uint32_t x, uint32_t y)
{
	uint32_t	*pixel;

	if (!texture || x >= texture->width || y >= texture->height)
		return (0);
	pixel = (uint32_t *)texture->pixels;
	return (pixel[y * texture->width + x]);
}

// Set the pixel x, y to color in given image.
void	color_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	*pixel;

	if (!image || x >= image->width || y >= image->height)
		return ;
	pixel = (uint32_t *)image->pixels;
	pixel[y * image->width + x] = color;
}
