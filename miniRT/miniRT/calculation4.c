/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:49:42 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:34:15 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	intersection_plane_square(t_square *square, t_vector v1, t_vector v2, \
t_vector *point)
{
	double		var;
	double		div;

	v2 = vector_plus(v2, -1, v1);
	div = (square->normal_vector.x * v2.x + square->normal_vector.y * v2.y + square->normal_vector.z \
	* v2.z);
	if (-0.000000000001 < div && div < 0.000000000001)
		return (0);
	var = -(square->normal_vector.x * v1.x + square->normal_vector.y * v1.y + square->normal_vector.z * v1.z \
	- square->normal_vector.x * square->cords.x - square->normal_vector.y * square->cords.y \
	- square->normal_vector.z * square->cords.z) / div;
	if (var > 0.0000001)
	{
		v1 = vector_plus(v1, 1, vector_multiply(v2, var));
		*point = v1;
		return (1);
	}
	else
		return (0);
}

static int	intersection(t_square *square, t_vector v1, t_vector v2, \
t_intersection *point)
{
	double		len;
	double		cos;
	t_vector	inter;
	t_vector	vector_on_square;

	if (!intersection_plane_square(square, v1, v2, &inter))
		return (0);
	inter = vector_plus(inter, -1, square->cords);
	vector_on_square = calculating_normal_vector(square->normal_vector);
	len = length_of_vector(inter);
	cos = vector_cos(vector_on_square, inter);
	if (cos < 0)
		cos *= -1;
	else
		cos *= 1;
	if (square->side_size / 2 <= cos * len || square->side_size / 2 <= \
	sqrt(1 - cos * cos) * len)
		return (0);
	inter = vector_plus(inter, 1, square->cords);
	point->point = inter;
	point->obj.square = square;
	point->color = square->color;
	return (1);
}

t_intersection	inters_with_square(t_all_data *data, t_vector v1, t_vector v2)
{
	t_intersection	point;
	t_intersection	result;
	t_square		*iter;

	result.point.x = NAN;
	result.obj.square = NULL;
	iter = data->objects.square;
	while (iter != NULL)
	{
		if (intersection(iter, v1, v2, &point))
			if (closer(point.point, result.point, v1))
				result = point;
		iter = iter->next;
	}
	result.obj.plane = NULL;
	result.obj.sphere = NULL;
	result.obj.cylinder = NULL;
	result.obj.triangle = NULL;
	return (result);
}
