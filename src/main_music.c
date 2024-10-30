/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:31:48 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/30 15:40:09 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"
#define MINIAUDIO_IMPLEMENTATION
#include "../miniaudio/miniaudio.h"	/* For music */

void	start_music(t_data *data, ma_engine	*engine);
void	stop_music(ma_engine	*engine);

int32_t	main(int ac, char **av)
{
	t_data		data;
	ma_engine	engine;

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
	if (BONUS && MUSIC)
	{
		start_music(&data, &engine);
		draw_minimap(&data);
		mlx_loop_hook(data.mlx, &animate, &data);
	}
	mlx_loop(data.mlx);
	if (BONUS && MUSIC)
		stop_music(&engine);
	clean_up(&data);
	return (EXIT_SUCCESS);
}

void	start_music(t_data *data, ma_engine	*engine)
{
	ma_result	result;

	result = ma_engine_init(NULL, engine);
	if (result != MA_SUCCESS)
		ft_error_and_free_map("Error with loading music", data);
	ma_engine_play_sound(engine, WAV_MUSIC, NULL);
}

void	stop_music(ma_engine	*engine)
{
	ma_engine_uninit(engine);
}
