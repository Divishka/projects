/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:39:20 by awhana            #+#    #+#             */
/*   Updated: 2021/05/03 15:28:03 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_cut
{
	float	atof;
	int		atoi;
	int		i;
	int		fac;
}				t_cut;

static t_cut	init_cut(t_cut cut)
{
	cut.atof = 0;
	cut.i = 0;
	cut.fac = 1;
	return (cut);
}

size_t	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f');
}

int	ft_intlen(int i)
{
	int	length;

	length = 0;
	while (i != 0)
	{
		i /= 10;
		length++;
	}
	return (length);
}

float	ft_atof(char *str)
{
	t_cut	cut;

	cut.atof = 0;
	cut = init_cut(cut);
	while (ft_is_space(str[cut.i]))
		cut.i++;
	if (str[cut.i] == '-')
		cut.fac = -1;
	cut.atoi = ft_atoi(str);
	cut.i = ft_intlen(cut.atoi);
	if (cut.fac == -1)
		cut.i++;
	if (str[cut.i] != '.')
		return (cut.atoi);
	cut.i++;
	while (str[cut.i] >= '0' && str[cut.i] <= '9')
	{
		cut.fac *= 10;
		cut.atof = cut.atof * 10 + str[cut.i] - 48;
		cut.i++;
	}
	cut.atof = cut.atof / cut.fac;
	return (cut.atoi + cut.atof);
}
