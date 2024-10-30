/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:02:53 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:28 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Returns 1, if '\n' in given string.
char	has_nl(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*(line++) == '\n')
			return (1);
	}
	return (0);
}

// Is given a string with '\n'.
// Cuts the part until '\n' with anything behind.
void	refactor_line(char *text)
{
	char	*copy;

	copy = text;
	while (*copy && *copy != '\n')
		copy++;
	if (!(*copy))
		*text = '\0';
	else if (*copy == '\n')
		copy++;
	while (*copy)
		*(text++) = *(copy++);
	*text = '\0';
}

// Counts bytes until '\n' or EndOfString
ssize_t	len_toend(char *element)
{
	ssize_t	len;

	if (!element)
		return (0);
	len = 0;
	while (*element && *element != '\n')
	{
		len++;
		element++;
	}
	if (*element == '\n')
		len++;
	return (len);
}

// Fills the malloced out-string from given llist-strings
void	copy_to_out(char *out, t_list *segment)
{
	char	copied;
	char	*src;

	while (segment)
	{
		copied = 0;
		src = segment->content;
		while (*src && *src != '\n')
		{
			*(out++) = *(src++);
			copied = 1;
		}
		if (*src == '\n')
		{
			*(out++) = '\n';
			break ;
		}
		if (!copied)
			break ;
		segment = segment->next;
	}
	*out = '\0';
}
