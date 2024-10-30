/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:29:36 by bschneid          #+#    #+#             */
/*   Updated: 2024/05/27 15:56:14 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int c)
{
	char	*search;
	char	match;

	match = (char)c;
	search = (char *)string;
	while (*search)
		search++;
	if (!match)
		return (search);
	while (search-- > string)
	{
		if (*search == match)
			return (search);
	}
	return (0);
}
