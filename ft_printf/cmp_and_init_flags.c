/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_and_init_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:00:38 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 08:45:38 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(t_flags flags)
{
	flags.zero = 0;
	flags.minus = 0;
	flags.dot = -1;
	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

int	type_was_found(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i'
		|| s == 'u' || s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

int	flag_was_found(char s)
{
	if (s == '-' || s == '0' || s == '.' || s == '*')
		return (1);
	return (0);
}
