/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:10:46 by awhana            #+#    #+#             */
/*   Updated: 2021/04/28 13:58:40 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	write_char(char c, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += ft_putchar(c);
	length += write_width(flags.width, 1, 0);
	if (flags.minus == 0)
		length += ft_putchar(c);
	return (length);
}
