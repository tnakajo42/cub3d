/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:06:26 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/28 23:07:49 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	put_enemy_texture(t_data *d);

// paints the (enemy) texture centered at x (may be negative) 
// scaled with given dist, if not hidden by a wall
void	enemy_to_image(t_data *d, t_enemy *enemy)
{
	if (enemy->slice < -100 || enemy->slice > (int32_t)d->image->width + 100)
		return ;
	d->help.appearance = *(enemy->appearance);
	d->help.distance = enemy->dist;
	d->help.x_max = enemy->slice + d->help.appearance->width / enemy->dist / 2;
	d->help.x_0 = enemy->slice - d->help.appearance->width / enemy->dist / 2;
	d->help.y_0 = d->image->height / 2;
	if (d->help.y_0 + 
		d->help.appearance->height / enemy->dist < d->image->height)
		d->help.y_max = d->help.y_0 + d->help.appearance->height / enemy->dist;
	else
		d->help.y_max = d->image->height;
	d->help.x_wr = d->help.x_0 - 1;
	if (d->help.x_wr < -1)
		d->help.x_wr = -1;
	put_enemy_texture(d);
}

static void	put_enemy_texture(t_data *d)
{
	while (++d->help.x_wr < d->help.x_max)
	{
		if (d->help.x_wr >= (int32_t)d->image->width)
			break ;
		if (d->ray.wall_dist[d->help.x_wr] + 0.5 < d->help.distance)
			continue ;
		d->help.y_wr = d->help.y_0;
		while (d->help.y_wr < d->help.y_max)
		{
			d->help.tex_x = (d->help.x_wr - d->help.x_0) * d->help.distance;
			d->help.tex_y = (d->help.y_wr - d->help.y_0) * d->help.distance;
			d->help.color = get_pixel_color(d->help.appearance, 
					d->help.tex_x, d->help.tex_y);
			if (d->help.color)
				color_pixel(d->image, d->help.x_wr, 
					d->help.y_wr, d->help.color);
			d->help.y_wr++;
		}
	}
}
