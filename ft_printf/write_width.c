/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:28:20 by awhana            #+#    #+#             */
/*   Updated: 2021/04/27 14:05:47 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_width(int width, int minus, int zero)
{
	int	length;

	length = 0;
	while (width - minus > 0)
	{
		if (zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width--;
		length++;
	}
	return (length);
}
