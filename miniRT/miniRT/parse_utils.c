/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:07:57 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 10:39:21 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	fract_part(char **str, long number, double *num, int minus)
{
	int			dot;

	dot = 1;
	while ('0' <= **str && **str <= '9')
	{
		number = number * 10 + minus * (**str - '0');
		(*str)++;
		dot++;
	}
	if (dot == 1)
		return (0);
	*num = number;
	while (--dot)
		*num /= 10;
	return (1);
}

static int	ternar_operator1(char **str, int tr, int fa, char cmp)
{
	if (**str == cmp)
		return (tr);
	return (fa);
}

static int	ternar_operator2(int from, double *num, int to)
{
	if (from <= *num && *num <= to)
		return (1);
	return (0);
}

int	get_int_strict(char **str, long *num, int from, int to)
{
	int			first_zero;
	int			count_of_digit;
	int			minus;

	count_of_digit = 0;
	minus = ternar_operator1(str, -1, 1, '-');
	if (**str == '-')
		(*str) = (*str) + 1;
	if ('0' <= **str && **str <= '9')
		*num = 0;
	else
		*num = from - 1;
	first_zero = ternar_operator1(str, 1, 0, '0');
	while ('0' <= **str && **str <= '9' && ++count_of_digit)
		*num = *num * 10 + minus * (*(*str)++ - '0');
	if ((first_zero && *num != 0) || (count_of_digit > 1 && *num == 0))
		return (0);
	return (ternar_operator3(from, num, to));
}

int	get_double_strict(char **str, double *num, int from, int to)
{
	long		number;
	int			minus;

	number = 0;
	if (('9' < **str || **str < '0') && **str != '-')
		return (0);
	minus = ternar_operator1(str, -1, 1, '-');
	if (**str == '0')
	{
		if (*++(*str) != '.')
			return (!(*num = 0.0));
		(*str)++;
		if (!fract_part(str, number, num, minus))
			return (0);
		return (ternar_operator2(from, num, to));
	}
	if (!get_int_strict(str, &number, from, to))
		return (0);
	*num = number;
	if (*(*str) != '.')
		return (ternar_operator2(from, num, to));
	(*str)++;
	if (!fract_part(str, number, num, minus))
		return (0);
	return (ternar_operator2(from, num, to));
}
