/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:16:50 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 11:43:36 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_until_for_int(char *str_out, long int temp, t_flags flags)
{
	int	length;

	length = 0;
	if (temp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		length += write_width(flags.dot - 1, ft_strlen(str_out) - 1, 1);
	length += write_until_precision(str_out, ft_strlen(str_out));
	return (length);
}

static int	cut_int(char *str_out, long int temp, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += write_until_for_int(str_out, temp, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_out))
		flags.dot = ft_strlen(str_out);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		length += write_width(flags.width, 0, 0);
	}
	else
		length += write_width(flags.width, ft_strlen(str_out), flags.zero);
	if (flags.minus == 0)
		length += write_until_for_int(str_out, temp, flags);
	return (length);
}

int	write_int(long int i, t_flags flags)
{
	long int		temp;
	char			*str_out;
	long int		length;

	temp = i;
	length = 0;
	if (flags.dot == 0 && i == 0)
	{
		length += write_width(flags.width, 0, 0);
		return (length);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0)
			write_until_precision("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		length++;
	}
	str_out = ft_itoa(i);
	length += cut_int(str_out, temp, flags);
	free(str_out);
	return (length);
}
