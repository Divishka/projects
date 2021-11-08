/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:09:26 by awhana            #+#    #+#             */
/*   Updated: 2021/04/28 14:42:59 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_to_lower(char *point)
{
	int	i;

	i = 0;
	while (point[i])
	{
		if (point[i] >= 65 && point[i] <= 90)
			point[i] = point[i] + 32;
		i++;
	}
	return (point);
}

char	*length_nums(unsigned long long temp, \
int base, char *str_out, int length)
{
	while (temp != 0)
	{
		if ((temp % base) < 10)
			str_out[length - 1] = (temp % base) + 48;
		else
			str_out[length - 1] = (temp % base) + 55;
		temp /= base;
		length--;
	}
	return (str_out);
}

static char	*dec_to_hex(unsigned long long i, int base)
{
	int					length;
	char				*str_out;
	unsigned long long	temp;

	temp = i;
	str_out = 0;
	length = 0;
	if (i == 0)
		return (ft_strdup("0"));
	while (i != 0)
	{
		length++;
		i /= base;
	}
	str_out = malloc(sizeof(char) * (length + 1));
	if (!str_out)
		return (0);
	str_out[length] = '\0';
	str_out = length_nums(temp, base, str_out, length);
	return (str_out);
}

static int	write_until_for_pointer(char *pointer, t_flags flags)
{
	int	length;

	length = 0;
	length += write_until_precision("0x", 2);
	if (flags.dot >= 0)
	{
		length += write_width(flags.dot, ft_strlen(pointer), 1);
		length += write_until_precision(pointer, flags.dot);
	}
	else
		length += write_until_precision(pointer, ft_strlen(pointer));
	return (length);
}

int	write_pointer(unsigned long long i, t_flags flags)
{
	char	*pointer;
	int		length;

	length = 0;
	if (i == 0 && flags.dot == 0)
	{
		length += write_until_precision("0x", 2);
		return (length += write_width(flags.width, 0, 1));
	}
	pointer = dec_to_hex(i, 16);
	pointer = str_to_lower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		length += write_until_for_pointer(pointer, flags);
	length += write_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		length += write_until_for_pointer(pointer, flags);
	free(pointer);
	return (length);
}
