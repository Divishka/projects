/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:14:21 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 15:38:52 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ternar_operator255(int x)
{
	if (x > 255)
		return (255);
	return (x);
}

static int	ternar_operator0(int x)
{
	if (x < 0)
		return (0);
	return (x);
}

int	rgba(int r, int g, int b, int a)
{
	r = ternar_operator0(r);
	r = ternar_operator255(r);
	g = ternar_operator0(g);
	g = ternar_operator255(g);
	b = ternar_operator0(b);
	b = ternar_operator255(b);
	a = ternar_operator0(a);
	a = ternar_operator255(a);
	return (a << 24 | r << 16 | g << 8 | b);
}

static int	intersection(t_plane *plane, t_vector v1, t_vector v2, \
t_intersection *point)
{
	double		var;
	double		div;

	v2 = vector_plus(v2, -1, v1);
	div = (plane->normal_vector.x * v2.x + plane->normal_vector.y * v2.y \
	+ plane->normal_vector.z * v2.z);
	if (-0.000000000001 < div && div < 0.000000000001)
		return (0);
	var = -(plane->normal_vector.x * v1.x + plane->normal_vector.y * v1.y \
	+ plane->normal_vector.z * v1.z - plane->normal_vector.x * plane->cords.x \
	- plane->normal_vector.y * plane->cords.y - plane->normal_vector.z * plane->cords.z) \
	/ div;
	if (var < 0.0000001)
		return (0);
	v1 = vector_plus(v1, 1, vector_multiply(v2, var));
	point->point = v1;
	point->obj.plane = plane;
	point->color = plane->color;
	return (1);
}

t_intersection	intersection_with_plane(t_all_data *data, \
t_vector v1, t_vector v2)
{
	t_intersection	point;
	t_intersection	result;
	t_plane			*iter;

	result.point.x = NAN;
	result.obj.plane = NULL;
	iter = data->objects.plane;
	while (iter != NULL)
	{
		if (intersection(iter, v1, v2, &point))
			if (closer(point.point, result.point, v1))
				result = point;
		iter = iter->next;
	}
	result.obj.sphere = NULL;
	result.obj.square = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
