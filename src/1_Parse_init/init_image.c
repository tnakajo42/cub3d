/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:46:59 by tnakajo           #+#    #+#             */
/*   Updated: 2024/10/30 15:08:37 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	set_color_of_the_world(t_data *data, char *line, char *key)
{
	char	**rgb_values;
	int		i; // here

	rgb_values = ft_split(line, ',');
	i = 0; // here
	while (rgb_values[i]) // here
		i++; // here
	if (i != 3) // here
		ft_error_general(data, "Invalid RGB format"); // here		
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
		ft_error_general(data, "Invalid RGB format");
	if (ft_atoi(rgb_values[0]) < 0 || ft_atoi(rgb_values[0]) > 255
		|| ft_atoi(rgb_values[1]) < 0 || ft_atoi(rgb_values[1]) > 255
		|| ft_atoi(rgb_values[2]) < 0 || ft_atoi(rgb_values[2]) > 255)
		ft_error_general(data, "Invalid RGB format");
	if (key[0] == 'F' && (key[1] == ' ' || key[1] == '\t'))
	{
		data->walls.floor_row = line;
		data->walls.floor_color = mix_pixel_color(ft_atoi(rgb_values[0]), \
			ft_atoi(rgb_values[1]), ft_atoi(rgb_values[2]), 255);
	}
	else if (key[0] == 'C' && (key[1] == ' ' || key[1] == '\t'))
	{
		data->walls.ceiling_row = line;
		data->walls.ceiling_color = mix_pixel_color(ft_atoi(rgb_values[0]), \
			ft_atoi(rgb_values[1]), ft_atoi(rgb_values[2]), 255);
	}
	ft_split_free(rgb_values);
}

void	set_a_key_of_image(t_data *data, char *line, int i, char *key)
{
	char	*trimmed_line;
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	trimmed_line = ft_strdup(line + i);
	if ((!ft_strncmp(key, "NO", 3) && data->walls.north)
			|| (!ft_strncmp(key, "SO", 3) && data->walls.south)
			|| (!ft_strncmp(key, "WE", 3) && data->walls.west)
			|| (!ft_strncmp(key, "EA", 3) && data->walls.east))
	{
		free(trimmed_line);
		ft_error_general(data, "Something's wrong with the given map file");
	}
	else if (!ft_strncmp(key, "NO", 3))
		data->walls.north = trimmed_line;
	else if (!ft_strncmp(key, "SO", 3))
		data->walls.south = trimmed_line;
	else if (!ft_strncmp(key, "WE", 3))
		data->walls.west = trimmed_line;
	else if (!ft_strncmp(key, "EA", 3))
		data->walls.east = trimmed_line;
	else if ((key[0] == 'F' || key[0] == 'C') && \
		(key[1] == ' ' || key[1] == '\t'))
		set_color_of_the_world(data, trimmed_line, key);
	else
	{
		free(trimmed_line);
		ft_error_general(data, "Something's wrong with the given map file");
	}
}

void	get_a_key_of_image(t_data *data, char *line, int i)
{
	char	key[3];

	key[0] = line[i];
	key[1] = line[i + 1];
	key[2] = '\0';
	if ((key[0] == 'N' && key[1] == 'O') || (key[0] == 'S' && key[1] == 'O') || \
		(key[0] == 'W' && key[1] == 'E') || (key[0] == 'E' && key[1] == 'A') || \
		((key[0] == 'F' || key[0] == 'C') && (key[1] == ' ' || key[1] == '\t')))
	{
		i++;
		if ((line[i] != 'F') && (line[i] != 'C'))
			i++;
		while ((line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line == NULL)
			ft_error_general(data, "Something's wrong with the given map file");
		set_a_key_of_image(data, line, i, key);
		init_image(data);
	}
	else
	{
		free(line);
		ft_error_general(data, "Something's wrong with the given map file");
	}
}

void	init_image(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	if (data->walls.east && data->walls.west && \
		data->walls.north && data->walls.south && \
		data->walls.ceiling_row && data->walls.floor_row)
		return ;
	line = get_next_line(data->fd);
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free (line);
		line = get_next_line(data->fd);
	}
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line == NULL)
		ft_error_general(data, "Map file's empty or contains only empty lines");
	get_a_key_of_image(data, line, i);
	free(line);
}
