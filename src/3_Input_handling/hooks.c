/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:13:20 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/23 16:59:52 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static char	check_movement(mlx_key_data_t *keydata, t_data *data);
static char	check_rest(mlx_key_data_t *keydata, t_data *data);

/*  Handle mouse input */
void	mouse_callback(double xpos, double ypos, void *param)
{
	t_data	*data;

	(void)ypos;
	data = param;
	xpos -= (double)data->image->width / 2;
	if (xpos > 40)
		data->player.dir_angle += 6 * TURN;
	else if (xpos > 20)
		data->player.dir_angle += 3 * TURN;
	else if (xpos > 1)
		data->player.dir_angle += TURN;
	else if (xpos < -40)
		data->player.dir_angle -= 6 * TURN;
	else if (xpos < -20)
		data->player.dir_angle -= 3 * TURN;
	else if (xpos < -1)
		data->player.dir_angle -= TURN;
	data->player.dir_x = cos(data->player.dir_angle);
	data->player.dir_y = sin(data->player.dir_angle);
	mlx_set_mouse_pos(data->mlx, data->image->width / 2,
		data->image->height / 2);
}

/* Handle keyboard input */
/* return (mlx_close_window(data->mlx));	// this needs to be cared of! */
void	key_press(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (check_movement(&keydata, data))
		return ;
	else if (check_rest(&keydata, data))
		return ;
}

static char	check_movement(mlx_key_data_t *keydata, t_data *data)
{
	if (keydata->key == MLX_KEY_W && keydata->action == MLX_PRESS)
		data->player.front = 1;
	else if (keydata->key == MLX_KEY_W && keydata->action == MLX_RELEASE)
		data->player.front = 0;
	else if (keydata->key == MLX_KEY_S && keydata->action == MLX_PRESS)
		data->player.front = -1;
	else if (keydata->key == MLX_KEY_S && keydata->action == MLX_RELEASE)
		data->player.front = 0;
	else if (keydata->key == MLX_KEY_A && keydata->action == MLX_PRESS)
		data->player.side = -1;
	else if (keydata->key == MLX_KEY_A && keydata->action == MLX_RELEASE)
		data->player.side = 0;
	else if (keydata->key == MLX_KEY_D && keydata->action == MLX_PRESS)
		data->player.side = 1;
	else if (keydata->key == MLX_KEY_D && keydata->action == MLX_RELEASE)
		data->player.side = 0;
	else
		return (0);
	return (1);
}

static char	check_rest(mlx_key_data_t *keydata, t_data *data)
{
	if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_PRESS)
		data->player.turn = -0.05;
	else if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_RELEASE)
		data->player.turn = 0;
	else if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_PRESS)
		data->player.turn = 0.05;
	else if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_RELEASE)
		data->player.turn = 0;
	else if (keydata->key == MLX_KEY_SPACE && keydata->action == MLX_PRESS)
		knock_door(data);
	else
		return (0);
	return (1);
}
