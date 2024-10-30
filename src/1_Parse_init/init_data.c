/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:34:57 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/29 16:02:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

/* TODO: Check the failing cases and how to handle */

int	init_game(t_data *data, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	data->fd = open(av[1], O_RDONLY);
	if (data->fd <= 0)
		ft_error_general(data, "Failed to open *.cub file");
	if (!init_data(data))
		return (0);
	init_image(data);
	init_map(data);
	init_zone(data);
	if (!load_textures(data))
		ft_error_and_free_map("Failed to load textures", data);
	if (BONUS)
		init_life(data);
	return (1);
}

// mlx_set_setting(MLX_MAXIMIZED, true);
// mlx_settings_t
	// mlx_set_setting(MLX_FULLSCREEN, true);
int	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!data->mlx)
		ft_error_general(data, "Failed to init MLX42");
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		mlx_terminate(data->mlx);
		ft_error_general(data, "Failed to create an image for MLX42");
	}
	data->fov_factor = 0.625;
	data->shift_dist = 2.0 * data->fov_factor / (data->image->width - 1.0);
	return (1);
}

/*data->player.dir_angle = 0; // 180°*/
