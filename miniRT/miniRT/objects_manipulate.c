/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_manipulate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:55:01 by awhana            #+#    #+#             */
/*   Updated: 2021/05/13 12:27:03 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	normal_for_plane(t_plane plane, t_vector start)
{
	double		cos;

	start = vector_plus(start, -1, plane.cords);
	cos = vector_cos(plane.normal_vector, start);
	if (cos < 0)
		return (vector_multiply(plane.normal_vector, -1));
	return (plane.normal_vector);
}

t_vector	normal_for_sphere(t_intersection inter, t_vector start)
{
	t_vector	normal_vector;

	start = vector_plus(start, -1, inter.obj.sphere->cords);
	if (inter.obj.sphere->diameter / 2 >= length_of_vector(start))
		normal_vector = vector_plus(inter.obj.sphere->cords, -1, \
		inter.point);
	else
		normal_vector = vector_plus(inter.point, -1, \
		inter.obj.sphere->cords);
	return (normal_vector);
}

t_vector	normal_for_square(t_square square, t_vector start)
{
	double		cos;

	start = vector_plus(start, -1, square.cords);
	cos = vector_cos(square.normal_vector, start);
	if (cos < 0)
		return (vector_multiply(square.normal_vector, -1));
	return (square.normal_vector);
}

t_vector	normal_for_cylinder(t_intersection inter, t_vector start)
{
	t_vector	normal_vector;

	start = vector_plus(start, -1, inter.point);
	inter.point = vector_plus(inter.point, -1, inter.obj.cylinder->cords);
	normal_vector = vector_plus(inter.point, \
	-vector_dot(inter.point, inter.obj.cylinder->ori), inter.obj.cylinder->ori);
	return (normal_vector);
}

t_vector	normal_for_triangle(t_triangle triangle, t_vector start)
{
	double		cos;

	start = vector_plus(start, -1, triangle.a);
	cos = vector_cos(triangle.normal_vector, start);
	if (cos < 0)
		return (vector_multiply(triangle.normal_vector, -1));
	return (triangle.normal_vector);
}
