/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formuls2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:25:52 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:39:53 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vector_cos(t_vector v1, t_vector v2)
{
	double		result;

	result = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z) \
	/ (length_of_vector(v1) * length_of_vector(v2));
	return (result);
}

t_vector	vector_multiply(t_vector v1, double k)
{
	t_vector	v;

	v.x = v1.x * k;
	v.y = v1.y * k;
	v.z = v1.z * k;
	return (v);
}

t_vector	vector_diverg(t_vector v1, double k)
{
	t_vector	v;

	v.x = v1.x / k;
	v.y = v1.y / k;
	v.z = v1.z / k;
	return (v);
}

double	vector_dot(t_vector v1, t_vector v2)
{
	double	r;

	r = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (r);
}

t_vector	calculating_normal_vector(t_vector ori)
{
	t_vector	n_vec;

	if (ori.z == 0)
	{
		n_vec.x = 0;
		n_vec.y = 0;
		n_vec.z = 1;
	}
	else
	{
		if (ori.x == 0 && ori.y == 0)
			n_vec.x = 1;
		else if (ori.z >= 0)
			n_vec.x = ori.x * -1;
		if (ori.z >= 0)
			n_vec.y = ori.y * -1;
		n_vec.z = sqrt(1 - ori.z * ori.z);
	}
	n_vec = vector_multiply(n_vec, length_of_vector(n_vec));
	n_vec.z *= -1;
	return (n_vec);
}
