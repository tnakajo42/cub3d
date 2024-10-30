/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:55:33 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:47 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	wordcount(char const *s, char c)
{
	char	active;
	size_t	words;

	words = 0;
	active = 0;
	while (*s)
	{
		if (*s != c && !active)
		{
			words++;
			active = 1;
		}
		else if (*s == c)
			active = 0;
		s++;
	}
	return (words);
}

static	char	*wordwrite(char const *s, char c)
{
	size_t	len;
	char	*out;
	char	*search;

	len = 0;
	search = (char *)s;
	while (*search && *search != c)
	{
		len++;
		search++;
	}
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	search = out;
	while (len--)
		*(search++) = *(s++);
	*search = '\0';
	return (out);
}

static	char	write_all(char const *s, char c, char **split, size_t words)
{
	char	**writer;

	writer = split;
	while (words--)
	{
		while (*s == c)
			s++;
		*writer = wordwrite(s, c);
		if (!(*(writer++)))
		{
			ft_split_free(split);
			return (0);
		}
		while (*s && *s != c)
			s++;
	}
	*writer = 0;
	return (1);
}

// Allocates (with malloc(3)) and returns an array of strings 
// obtained by splitting ’s’ using the character ’c’ as a delimiter. 
// The array must end with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = wordcount(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!write_all(s, c, split, words))
		return (NULL);
	return (split);
}
