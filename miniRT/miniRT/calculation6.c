/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:13:12 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:51:30 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	intersection_plane_triangle(t_triangle *triangle, t_vector v1, t_vector v2, \
t_vector *point)
{
	double		var;
	double		div;

	v2 = vector_plus(v2, -1, v1);
	div = (triangle->normal_vector.x * v2.x + triangle->normal_vector.y * v2.y + \
	triangle->normal_vector.z * v2.z);
	if (-0.000000000001 < div && div < 0.000000000001)
		return (0);
	var = -(triangle->normal_vector.x * v1.x + triangle->normal_vector.y * v1.y \
	+ triangle->normal_vector.z * v1.z - triangle->normal_vector.x * triangle->a.x \
	- triangle->normal_vector.y * triangle->a.y \
	- triangle->normal_vector.z * triangle->a.z) / div;
	if (var > 0.0000001)
	{
		v1 = vector_plus(v1, 1, vector_multiply(v2, var));
		*point = v1;
		return (1);
	}
	else
		return (0);
}

static double	square_of_triangle(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (length_of_vector(v) / 2.0);
}

static int	in_triangle(t_triangle triangle, t_vector inter)
{
	t_vector	v1;
	t_vector	v2;
	double		s_of_main_tr;
	double		s_of_other_tr[3];

	v1 = vector_plus(triangle.a, -1, triangle.c);
	v2 = vector_plus(triangle.b, -1, triangle.c);
	triangle.a = vector_plus(triangle.a, -1, inter);
	triangle.b = vector_plus(triangle.b, -1, inter);
	triangle.c = vector_plus(triangle.c, -1, inter);
	s_of_main_tr = square_of_triangle(v1, v2);
	s_of_other_tr[0] = square_of_triangle(triangle.a, triangle.b);
	s_of_other_tr[1] = square_of_triangle(triangle.b, triangle.c);
	s_of_other_tr[2] = square_of_triangle(triangle.c, triangle.a);
	if (s_of_other_tr[0] + s_of_other_tr[1] + s_of_other_tr[2] > s_of_main_tr \
	+ 0.000000001)
		return (0);
	return (1);
}

static int	intersection(t_triangle *triangle, t_vector v1, t_vector v2, \
t_intersection *point)
{
	t_vector	inter;
	t_vector	a;
	t_vector	b;

	a = triangle->a;
	b = triangle->b;
	a = vector_plus(a, -1, triangle->c);
	b = vector_plus(b, -1, triangle->c);
	triangle->normal_vector.x = a.y * b.z - a.z * b.y;
	triangle->normal_vector.y = a.z * b.x - a.x * b.z;
	triangle->normal_vector.z = a.x * b.y - a.y * b.x;
	if (!intersection_plane_triangle(triangle, v1, v2, &inter))
		return (0);
	if (!in_triangle(*triangle, inter))
		return (0);
	point->point = inter;
	point->obj.triangle = triangle;
	point->color = triangle->color;
	return (1);
}

t_intersection	inters_with_triangle(t_all_data *data, t_vector v1, t_vector v2)
{
	t_intersection	point;
	t_intersection	result;
	t_triangle		*iter;

	result.point.x = NAN;
	result.obj.triangle = NULL;
	iter = data->objects.triangle;
	while (iter != NULL)
	{
		if (intersection(iter, v1, v2, &point))
			if (closer(point.point, result.point, v1))
				result = point;
		iter = iter->next;
	}
	result.obj.plane = NULL;
	result.obj.sphere = NULL;
	result.obj.square = NULL;
	result.obj.cylinder = NULL;
	return (result);
}
