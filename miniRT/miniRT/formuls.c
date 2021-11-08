/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formuls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:01:34 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 19:00:17 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_plus(t_vector v1, double sign, t_vector v2)
{
	t_vector	v;

	v.x = v1.x + sign * v2.x;
	v.y = v1.y + sign * v2.y;
	v.z = v1.z + sign * v2.z;
	return (v);
}

t_vector	vector_minus(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.z = v1.x * v2.y - v1.y * v2.x;
	v.y = v1.z * v2.x - v1.x * v2.z;
	return (v);
}

t_vector	vector_normalize(t_vector vec)
{
	t_vector	normal;
	double		length;

	length = length_of_vector(vec);
	normal.x = vec.x / length;
	normal.y = vec.y / length;
	normal.z = vec.z / length;
	return (normal);
}

double	length_of_vector(t_vector v)
{
	double	length;

	length = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (length);
}
