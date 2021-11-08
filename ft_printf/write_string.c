/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:17:55 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 13:22:19 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	precision_is_positive_for_string(t_flags flags, char *string)
{
	int	length;

	length = 0;
	if (flags.dot >= 0)
	{
		length += write_width(flags.dot, ft_strlen(string), 0);
		length += ft_putstr(string, flags.dot);
	}
	else
		length += write_until_precision(string, ft_strlen(string));
	return (length);
}

int	write_string(char *string, t_flags flags)
{
	int	length;

	length = 0;
	if (!string)
		string = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(string))
		flags.dot = ft_strlen(string);
	if (flags.minus == 1)
		length += precision_is_positive_for_string(flags, string);
	if (flags.dot >= 0)
		length += write_width(flags.width, flags.dot, 0);
	else
		length += write_width(flags.width, ft_strlen(string), 0);
	if (flags.minus == 0)
	{
		length += precision_is_positive_for_string(flags, string);
	}
	return (length);
}
