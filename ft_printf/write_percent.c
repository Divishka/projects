/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:31:49 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 08:45:12 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_percent(t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += write_until_precision("%", 1);
	length += write_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		length += write_until_precision("%", 1);
	return (length);
}
