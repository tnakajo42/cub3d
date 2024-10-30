/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:31:48 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/30 15:09:24 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"
/* 
TODO: FREE everything at each stage, where program can be aborted (also begin)
TODO: There should be collectable candy - it raises energy (life)
TODO: Valgrind ignore file
 */

/* printf("BONUS-FLAG: %i, MUSIC: %i\n", BONUS, MUSIC); */
/* mlx_close_hook(data.mlx, &clean_up, &data); */
int32_t	main(int ac, char **av)
{
	t_data		data;

	check_argument(ac, av);
	if (!init_game(&data, av))
	{
		mlx_delete_image(data.mlx, data.image);
		mlx_terminate(data.mlx);
		ft_error_general(&data, "Couldn't init the game");
	}
	mlx_image_to_window(data.mlx, data.image, 0, 0);
	mlx_cursor_hook(data.mlx, &mouse_callback, &data);
	mlx_key_hook(data.mlx, &key_press, &data);
	mlx_loop_hook(data.mlx, &get_new_frame, &data);
	if (BONUS)
	{
		draw_minimap(&data);
		mlx_loop_hook(data.mlx, &animate, &data);
	}
	mlx_loop(data.mlx);
	clean_up(&data);
	return (EXIT_SUCCESS);
}
