/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_igned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:42:33 by awhana            #+#    #+#             */
/*   Updated: 2021/04/28 14:48:36 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*gain_the_num(char *str_out, long num, int l, int n)
{
	if (num != 0)
		str_out = malloc(sizeof(char) * (l + 1));
	else
		return (str_out = ft_strdup("0"));
	if (!str_out)
		return (0);
	n = 0;
	if (num < 0)
	{
		n++;
		num = -num;
	}
	str_out[l] = '\0';
	while (--l)
	{
		str_out[l] = (num % 10) + '0';
		num /= 10;
	}
	if (n == 1)
		str_out[0] = '-';
	else
		str_out[0] = (num % 10) + '0';
	return (str_out);
}

char	*unsigned_itoa(unsigned int i)
{
	int		l;
	char	*str_out;
	long	num;
	int		n;

	num = i;
	l = length_of_u2(num);
	str_out = 0;
	n = 0;
	str_out = gain_the_num(str_out, num, l, n);
	if (!str_out)
		return (0);
	return (str_out);
}

static int	cut_unsigned(char *i, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.dot >= 0)
		length += write_width(flags.dot - 1, ft_strlen(i) - 1, 1);
	length += write_until_precision(i, ft_strlen(i));
	return (length);
}

static int	cut_unsigned_1(char *i, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += cut_unsigned(i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(i))
		flags.dot = ft_strlen(i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		length += write_width(flags.width, 0, 0);
	}
	else
		length += write_width(flags.width, ft_strlen(i), flags.zero);
	if (flags.minus == 0)
		length += cut_unsigned(i, flags);
	return (length);
}

int	write_unsigned_int(unsigned int u, t_flags flags)
{
	char	*i;
	int		length;

	length = 0;
	u = (unsigned int)(4294967295 + 1 + u);
	if (flags.dot == 0 && u == 0)
	{
		length += write_width(flags.width, 0, 0);
		return (length);
	}
	i = unsigned_itoa(u);
	length += cut_unsigned_1(i, flags);
	free(i);
	return (length);
}
