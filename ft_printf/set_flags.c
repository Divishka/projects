/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:04:35 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 09:31:27 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	flag_width(va_list arg, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(arg, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}

t_flags	flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int	flag_dot(int start, char *form, t_flags *flags, va_list arg)
{
	start++;
	if (form[start] == '*')
	{
		flags->dot = va_arg(arg, int);
		start++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(form[start]))
			flags->dot = (flags->dot * 10) + (form[start++] - '0');
	}
	return (start);
}
