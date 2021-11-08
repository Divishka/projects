/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:21:42 by awhana            #+#    #+#             */
/*   Updated: 2021/05/12 18:21:19 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_closer_point_intersection(t_vector v1, t_vector v2, \
t_intersection *x_point)
{
	t_vector	x_point_1;
	t_vector	x_point_2;

	v2 = vector_plus(v2, -1, v1);
	x_point_1 = vector_multiply(v2, x_point->point.x);
	x_point_2 = vector_multiply(v2, x_point->point.y);
	x_point_1 = vector_plus(x_point_1, 1, v1);
	x_point_2 = vector_plus(x_point_2, 1, v1);
	if (x_point->point.x > 0.0000001 && x_point->point.y > 0.0000001)
	{
		if (closer(x_point_1, x_point_2, v1))
			x_point->point = x_point_1;
		else
			x_point->point = x_point_2;
	}
	else if (x_point->point.x > 0.0000001)
		x_point->point = x_point_1;
	else if (x_point->point.y > 0.0000001)
		x_point->point = x_point_2;
	else
		x_point->point.x = NAN;
}

static int	intersection(t_sphere *sphere, t_vector v1, t_vector v2, \
t_intersection *point)
{
	double		d;
	t_vector	k;
	t_vector	a;
	t_vector	b;

	a = vector_plus(v1, -1, sphere->cords);
	b = vector_plus(v2, -1, v1);
	k.x = b.x * b.x + b.y * b.y + b.z * b.z;
	k.y = 2 * (a.x * b.x + a.y * b.y + a.z * b.z);
	k.z = a.x * a.x + a.y * a.y + a.z * a.z;
	k.z -= sphere->diameter / 2 * sphere->diameter / 2;
	d = k.y * k.y - 4 * k.x * k.z;
	if (d < 0)
		return (0);
	point->point.x = (-k.y - sqrt(d)) / (2 * k.x);
	point->point.y = (-k.y + sqrt(d)) / (2 * k.x);
	find_closer_point_intersection(v1, v2, point);
	if (point->point.x != point->point.x)
		return (0);
	point->obj.sphere = sphere;
	point->color = sphere->color;
	return (1);
}

t_intersection	inters_with_sphere(t_all_data *data, t_vector v1, t_vector v2)
{
	t_intersection	point;
	t_intersection	result;
	t_sphere		*iter;

	result.point.x = NAN;
	result.obj.sphere = NULL;
	iter = data->objects.sphere;
	while (iter != NULL)
	{
		if (intersection(iter, v1, v2, &point))
			if (closer(point.point, result.point, v1))
				result = point;
		iter = iter->next;
	}
	result.obj.plane = NULL;
	result.obj.square = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
