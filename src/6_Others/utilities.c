/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:36:08 by bschneid          #+#    #+#             */
/*   Updated: 2024/10/29 17:38:14 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

char	*check_emtpy_file(t_data *data, char *line)
{
	while (line && ft_strncmp(line, "\n", 2) == 0)
	{
		free (line);
		line = get_next_line(data->fd);
	}
	check_forbidden_chars(data, line, 0);
	if (line == NULL)
		ft_error_general(data, "Map file's empty or contains only empty lines");
	return (line);
}

void	check_forbidden_chars(t_data *data, char *line, int flag)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
	{
		if (!ft_strchr(CHAR_MAP, line[i]) && BONUS == 0)
		{
			free(line);
			if (!flag)
				ft_error_general(data, "Invalid map. Only use 01NSEW");
			else
				ft_error_and_free_map("Invalid map. Only use 01NSEW", data);
		}
		if (!ft_strchr(CHAR_MAP_B, line[i]) && BONUS == 1)
		{
			free(line);
			if (!flag)
				ft_error_general(data, "Invalid map. Only use 01NSEWDPC");
			else
				ft_error_and_free_map("Invalid map. Only use 01NSEW", data);
		}
		i++;
	}
}
