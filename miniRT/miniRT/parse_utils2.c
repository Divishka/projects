/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:10:11 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 10:30:35 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ternar_operator3(int from, long *num, int to)
{
	if (from <= *num && *num <= to)
		return (1);
	return (0);
}

static int	get_spectrum(char **str, long *spectrum, int comma)
{
	if (!get_int_strict(str, spectrum, 0, 255))
		return (0);
	if (!comma)
		return (1);
	if (*(*str)++ != ',')
		return (0);
	return (1);
}

int	add_rgb(char **str, int *color)
{
	long		spectrum;

	if (!get_spectrum(str, &spectrum, 1))
		return (0);
	*color = (*color << 8) | spectrum;
	if (!get_spectrum(str, &spectrum, 1))
		return (0);
	*color = ((long)*color << 8) | spectrum;
	if (!get_spectrum(str, &spectrum, 0))
		return (0);
	*color = ((long)*color << 8) | spectrum;
	return (1);
}
