/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:52:08 by awhana            #+#    #+#             */
/*   Updated: 2021/05/13 13:19:23 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	closer(t_vector v1, t_vector v2, t_vector v_start)
{
	double		len_1;
	double		len_2;

	if (v2.x != v2.x && v1.x != v1.x)
		return (0);
	if (v2.x != v2.x)
		return (1);
	v1 = vector_plus(v1, -1, v_start);
	v2 = vector_plus(v2, -1, v_start);
	len_1 = length_of_vector(v1);
	len_2 = length_of_vector(v2);
	if (len_1 < len_2)
		return (1);
	return (0);
}

static	int	find_cross_point(t_all_data *data, \
t_vector v1, t_vector v2, t_intersection *inter)
{
	int				i;
	int				result;
	t_intersection	cross_point[5];

	cross_point[0] = intersection_with_plane(data, v1, v2);
	cross_point[1] = inters_with_sphere(data, v1, v2);
	cross_point[2] = inters_with_square(data, v1, v2);
	cross_point[3] = inters_with_cylinder(data, v1, v2);
	cross_point[4] = inters_with_triangle(data, v1, v2);
	i = 0;
	result = 0;
	while (i < 5)
	{
		if (cross_point[i].point.x == cross_point[i].point.x)
		{
			if (closer(cross_point[i].point, inter->point, v1))
			{
				*inter = cross_point[i];
				result = 1;
			}
		}
		i++;
	}
	return (result);
}

int	ray_trace(t_all_data *data, t_vector v1, t_vector v2)
{
	int				color;
	t_intersection	cross_point;

	cross_point.point.x = NAN;
	if (!find_cross_point(data, v1, v2, &cross_point))
		return (0x000000);
	color = calc_shadows(data, cross_point, v1);
	return (color);
}
