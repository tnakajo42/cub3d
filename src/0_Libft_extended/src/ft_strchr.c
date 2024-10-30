/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:11:31 by bschneid          #+#    #+#             */
/*   Updated: 2024/05/27 15:45:08 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int c)
{
	char	match;

	match = (char)c;
	while (*string)
	{
		if (*string == match)
			return ((char *)string);
		string++;
	}
	if (!match)
		return ((char *)string);
	return (0);
}
