/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:42:42 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:19:23 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	test_gnl(int fd1, int fd2)
{
	char	*line1;
	char	*line2;
	int		lines;

	lines = 1;
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		if (line1)
		{
			ft_printf("%d.Line test1 -> %s", lines, line1);
			free(line1);
		}
		if (line2)
		{
			ft_printf("%d.Line test2 -> %s", lines, line2);
			free(line2);
		}
		ft_printf("\n");
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		lines++;
	}
}

// cc -g gnl_test.c -o gnl_test.out -L.. -lft
int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Couldn't open text1 or text2!");
		return (1);
	}
	test_gnl(fd1, fd2);
	close(fd1);
	close(fd2);
	return (0);
}
