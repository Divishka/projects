/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:57:21 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:36:14 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	cut_norm(t_cylinder cylinder, t_vector p_inter_1, t_vector top)
{
	if (vector_dot(cylinder.ori, vector_plus(p_inter_1, -1, top)) < 0.0 && \
	vector_dot(cylinder.ori, vector_plus(p_inter_1, -1, cylinder.cords)) > 0.0)
		return (1);
	return (0);
}

static void	find_closer_point_intersection(t_cylinder cylinder, t_vector v1, t_vector v2, \
t_intersection *p_inter)
{
	t_vector	top;
	t_vector	p_inter_1;
	t_vector	p_inter_2;

	v2 = vector_plus(v2, -1, v1);
	p_inter_1 = vector_multiply(v2, p_inter->point.x);
	p_inter_2 = vector_multiply(v2, p_inter->point.y);
	p_inter_1 = vector_plus(p_inter_1, 1, v1);
	p_inter_2 = vector_plus(p_inter_2, 1, v1);
	top = vector_multiply(cylinder.ori,
			cylinder.height / length_of_vector(cylinder.ori));
	if (p_inter->point.x > 0.0000001 && p_inter->point.y > 0.0000001)
	{
		if (closer(p_inter_1, p_inter_2, v1) && cut_norm(cylinder, p_inter_1, \
		top))
			p_inter->point = p_inter_1;
		else
			p_inter->point = p_inter_2;
	}
	else if (p_inter->point.x > 0.0000001)
		p_inter->point = p_inter_1;
	else if (p_inter->point.y > 0.0000001)
		p_inter->point = p_inter_2;
	else
		p_inter->point.x = NAN;
}

static t_vector	get_k(t_cylinder cylinder, t_vector v1, t_vector v2)
{
	t_vector	vectors[4];
	t_vector	result;

	vectors[0] = vector_plus(v2, -1, v1);
	vectors[3] = vector_plus(v1, -1, cylinder.cords);
	vectors[1] = vector_multiply(cylinder.ori, vector_dot(vectors[0], \
	cylinder.ori));
	vectors[1] = vector_plus(vectors[1], -1, vectors[0]);
	vectors[2] = vector_multiply(cylinder.ori, vector_dot(vectors[3], \
	cylinder.ori));
	vectors[2] = vector_plus(vectors[2], -1, vectors[3]);
	result.x = vector_dot(vectors[1], vectors[1]);
	result.y = 2 * vector_dot(vectors[1], vectors[2]);
	result.z = vector_dot(vectors[2], vectors[2]);
	result.z -= (cylinder.diameter / 2) * (cylinder.diameter / 2);
	return (result);
}

static int	intersection(t_cylinder *cylinder, t_vector v1, t_vector v2, \
t_intersection *inter)
{
	t_vector	top;
	t_vector	coef;
	double		discriminant;

	coef = get_k(*cylinder, v1, v2);
	discriminant = coef.y * coef.y - 4 * coef.x * coef.z;
	if (discriminant < 0)
		return (0);
	inter->point.x = (-coef.y - sqrt(discriminant)) / (2 * coef.x);
	inter->point.y = (-coef.y + sqrt(discriminant)) / (2 * coef.x);
	find_closer_point_intersection(*cylinder, v1, v2, inter);
	if (inter->point.x != inter->point.x)
		return (0);
	top = vector_multiply(cylinder->ori, cylinder->height / \
	length_of_vector(cylinder->ori));
	if (vector_dot(cylinder->ori, vector_plus(inter->point, -1, top)) > 0.0 || \
	vector_dot(cylinder->ori, vector_plus(inter->point, -1, cylinder->cords)) \
	< 0.0)
		return (0);
	inter->obj.cylinder = cylinder;
	inter->color = cylinder->color;
	return (1);
}

t_intersection	inters_with_cylinder(t_all_data *data, t_vector v1, t_vector v2)
{
	t_intersection		point;
	t_intersection		result;
	t_cylinder			*iter;

	result.point.x = NAN;
	result.obj.cylinder = NULL;
	iter = data->objects.cylinder;
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
	result.obj.triangle = NULL;
	return (result);
}
