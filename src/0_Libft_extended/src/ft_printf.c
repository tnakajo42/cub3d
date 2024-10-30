/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:43:50 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/15 16:14:27 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	use_func(va_list args, const char **input, t_subs *subs)
{
	if (**input == 'c')
		return (ft_pf_putchar(va_arg(args, int), subs));
	else if (**input == 's')
		return (ft_pf_putstr(va_arg(args, char *), subs));
	else if (**input == 'p')
		return (ft_pf_putptr(va_arg(args, void *), subs));
	else if (**input == 'd')
		return (ft_pf_putint(va_arg(args, int), 1, subs));
	else if (**input == 'i')
		return (ft_pf_putint(va_arg(args, int), 1, subs));
	else if (**input == 'u')
		return (ft_pf_putunsigned(va_arg(args, unsigned int), subs));
	else if (**input == 'x')
		return (ft_pf_puthex("0xabcdef", va_arg(args, unsigned int), subs));
	else if (**input == 'X')
		return (ft_pf_puthex("0XABCDEF", va_arg(args, unsigned int), subs));
	else if (**input == '%')
		return (ft_pf_putperc());
	return (-1);
}

// Initialises struct and sets the flags 1, if they are set in string.
static void	care_flags(const char **input, t_subs *subs)
{
	subs->flag_minus = 0;
	subs->flag_plus = 0;
	subs->flag_space = 0;
	subs->flag_hash = 0;
	subs->flag_zero = 0;
	subs->width = 0;
	subs->precision = -1;
	while (**input)
	{
		if (**input == '-')
			subs->flag_minus = 1;
		else if (**input == '+')
			subs->flag_plus = 1;
		else if (**input == ' ')
			subs->flag_space = 1;
		else if (**input == '#')
			subs->flag_hash = 1;
		else if (**input == '0')
			subs->flag_zero = 1;
		else
			return ;
		(*input)++;
	}
}

// Initializes sub-specifiers (flags, width, precision) and hands them to use.
static int	handle_specifier(va_list args, const char **input, t_subs *subs)
{
	care_flags(input, subs);
	if (**input == '*')
	{
		subs->width = va_arg(args, int);
		(*input)++;
	}
	else
		subs->width = ft_pf_atoi(input);
	if (**input == '.')
	{
		(*input)++;
		if (**input == '*')
		{
			subs->precision = va_arg(args, int);
			(*input)++;
		}
		else
			subs->precision = ft_pf_atoi(input);
	}
	return (use_func(args, input, subs));
}

static int	handle_input(va_list args, const char **input, t_subs *subs)
{
	char	*save;
	int		out;

	if (**input != '%')
	{
		write(1, (*input)++, 1);
		return (1);
	}
	(*input)++;
	save = (char *)*input;
	out = handle_specifier(args, input, subs);
	if (out == -1 && !(**input))
		return (-1);
	else if (out == -1)
	{
		write(1, "%", 1);
		*input = save;
		return (1);
	}
	(*input)++;
	return (out);
}

// function that will mimic the original printf()
// including specifiers: "cspdiuxX%"
// flags: '-+ #0' ; width: int/* ; precision: int/*
int	ft_printf(const char *input, ...)
{
	int		writes;
	int		out;
	va_list	args;
	t_subs	subs;

	va_start(args, input);
	writes = 0;
	while (*input)
	{
		out = handle_input(args, &input, &subs);
		if (out == -1)
			break ;
		else
			writes += out;
	}
	va_end(args);
	if (out == -1)
		return (-1);
	return (writes);
}
