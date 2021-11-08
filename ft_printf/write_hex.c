/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:05:16 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 13:33:02 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_until_precision_for_hex(char *string, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.dot >= 0)
		length += write_width(flags.dot - 1, ft_strlen(string) - 1, 1);
	length += write_until_precision(string, ft_strlen(string));
	return (length);
}

static char	*cut_four(unsigned long long temp, char *str_out, int count)
{
	while (temp != 0)
	{
		if ((temp % 16) < 10)
			str_out[count - 1] = (temp % 16) + 48;
		else
			str_out[count - 1] = (temp % 16) + 55;
		temp = temp / 16;
		count--;
	}
	return (str_out);
}

static char	*hex_itoa(unsigned long long hex)
{
	char				*str_out;
	unsigned long long	temp;
	int					count;

	str_out = 0;
	count = 0;
	temp = hex;
	if (hex == 0)
		return (ft_strdup("0"));
	while (hex != 0)
	{
		hex = hex / 16;
		count++;
	}
	str_out = malloc(sizeof(char) * (count + 1));
	if (!str_out)
		return (0);
	str_out[count] = '\0';
	str_out = cut_four(temp, str_out, count);
	return (str_out);
}

static int	cut_five(char *hex, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += write_until_precision_for_hex(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width = flags.width - flags.dot;
		length += write_width(flags.width, 0, 0);
	}
	else
		length += write_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		length += write_until_precision_for_hex(hex, flags);
	return (length);
}

int	write_hex(unsigned int i, t_flags flags)
{
	int		low;
	char	*hex;
	int		length;

	length = 0;
	low = 0;
	i = (unsigned int)(4294967295 + 1 + i);
	if (flags.type == 'x')
		low = 1;
	if (flags.dot == 0 && i == 0)
		return (length += write_width(flags.width, 0, 0));
	hex = hex_itoa((unsigned long long)i);
	if (low == 1)
		hex = str_to_lower(hex);
	length += cut_five(hex, flags);
	free(hex);
	return (length);
}
