/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:34:51 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/30 15:05:23 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	map_malloc(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * MAX_HEIGHT);
	if (!data->map)
		ft_error_general(data, "Failed to allocate memory for map");
	ft_memset(data->map, 0, MAX_HEIGHT);
}

void	check_max_map_x(t_data *data, char *line)
{
	unsigned int	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			line[len] = '\0';
		len++;
	}
	if (data->map_width < len)
		data->map_width = len;
	return ;
}

size_t	ft_strlcpy_w_space(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	while (*src && (size-- > 1))
		*(dst++) = *(src++);
	while ((size-- > 1))
		*(dst++) = ' ';
	*dst = '\0';
	return (len);
}

void	init_map_sub(t_data *data, char *line, int i)
{
	while (line)
	{
		if (line[0] == '\n')
		{
			line = get_next_line(data->fd);
			continue ;
		}
		else if (line && line[0] != '\0')
			ft_error_and_free_map("Invalid map", data);
	}
	data->map_height = i;
	if (data->map_height < 15 && data->map_height < 15)
		data->mini_img_size = data->mini_img_size * 2;
	data->enemy_size = data->mini_img_size * data->mini_map_player / 10;
}

void	init_map(t_data *data)
{
	int		i;
	char	*line;

	line = get_next_line(data->fd);
	line = check_emtpy_file(data, line);
	i = 0;
	while (line && line[0] != '\n')
	{
		if (data->map == NULL)
			map_malloc(data);
		data->map[i] = malloc(sizeof(char) * (MAX_WIDTH + 1));
		if (!data->map[i])
			ft_error_and_free_map("Something wrong in the map file", data);
		check_max_map_x(data, line);
		ft_strlcpy_w_space(data->map[i++], line, MAX_WIDTH + 1);
		check_forbidden_chars(data, line, 1);
		free(line);
		line = get_next_line(data->fd);
	}
	init_map_sub(data, line, i);
	close(data->fd);
	data->fd = 0;
	return (free(line));
}
