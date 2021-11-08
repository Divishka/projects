/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:56:47 by awhana            #+#    #+#             */
/*   Updated: 2021/04/28 15:08:18 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int dot)
{
	int	i;

	i = 0;
	while (s[i] && i < dot)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	write_until_precision(char *string, int precision)
{
	int	length;

	length = 0;
	while (string[length] && length < precision)
		ft_putchar(string[length++]);
	return (length);
}

int	count_of_nums(long n)
{
	size_t	count;
	int		num;

	count = 0;
	num = 0;
	if (n < 0)
	{
		count++;
		num++;
		n = n * -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	length_of_u2(long num)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	if (num < 0)
	{
		i++;
		n++;
		num = -num;
	}
	while (num >= 1)
	{
		i++;
		num /= 10;
	}
	return (i);
}
