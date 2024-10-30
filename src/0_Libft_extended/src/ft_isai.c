/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isai.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:38:58 by bschneid          #+#    #+#             */
/*   Updated: 2024/09/05 12:53:01 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 1 if a string is a valid integer, 0 otherwise.
char	ft_isai(const char *string)
{
	if (!string || !*string)
		return (0);
	if (*string == '-' || *string == '+')
		string++;
	while (*string)
	{
		if (*string < '0' || *string > '9')
			return (0);
		string++;
	}
	return (1);
}
