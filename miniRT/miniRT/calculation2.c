/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:33:16 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:49:02 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	convert_light(int light)
{
	int			alpha;
	int			l_color;
	double		illum_lvl;
	t_vector	result;

	l_color = light & 0xffffff;
	alpha = 255 - ((light >> 24) & 0xff);
	illum_lvl = alpha / 255.0;
	result.x = ((light & 0xff0000) >> 16) * illum_lvl;
	result.y = ((light & 0xff00) >> 8) * illum_lvl;
	result.z = (light & 0xff) * illum_lvl;
	return (result);
}

static int	find_point_intersection(t_all_data *data, t_vector v1, t_vector v2)
{
	int				i;
	t_intersection	cross_p[5];

	cross_p[0] = intersection_with_plane(data, v1, v2);
	cross_p[1] = inters_with_sphere(data, v1, v2);
	cross_p[2] = inters_with_square(data, v1, v2);
	cross_p[3] = inters_with_cylinder(data, v1, v2);
	cross_p[4] = inters_with_triangle(data, v1, v2);
	i = 0;
	while (i < 5)
	{
		if (cross_p[i].point.x == cross_p[i].point.x)
			if (closer(cross_p[i].point, v2, v1))
				return (1);
		i++;
	}
	return (0);
}

static void	gradient_level(t_intersection inter, t_light light, t_vector *color, \
t_vector start)
{
	double		level;
	double		distanse;
	t_vector	normal_vector;

	if (inter.obj.plane != NULL)
		normal_vector = normal_for_plane(*inter.obj.plane, start);
	if (inter.obj.sphere != NULL)
		normal_vector = normal_for_sphere(inter, start);
	if (inter.obj.square != NULL)
		normal_vector = normal_for_square(*inter.obj.square, start);
	if (inter.obj.cylinder != NULL)
		normal_vector = normal_for_cylinder(inter, start);
	if (inter.obj.triangle != NULL)
		normal_vector = normal_for_triangle(*inter.obj.triangle, start);
	light.cords = vector_plus(light.cords, -1, inter.point);
	distanse = length_of_vector(light.cords);
	level = vector_cos(light.cords, normal_vector) \
	/ (0.00003 * distanse * distanse + 1);
	if (level > 0)
		*color = vector_multiply(*color, level);
	else
		*color = vector_multiply(*color, 0.0);
}

static t_vector	get_color_light(t_all_data *data, t_intersection inter, \
t_vector start)
{
	t_vector	v1;
	t_vector	v2;
	t_light		*iter;

	iter = data->objects.light;
	v2 = convert_light(data->ambient);
	while (iter != NULL)
	{
		if (!find_point_intersection(data, inter.point, \
		iter->cords))
		{
			v1 = convert_light(iter->color);
			gradient_level(inter, *iter, &v1, start);
			v2 = ternar_operator_7(v1, v2);
		}
		iter = iter->next;
	}
	return (v2);
}

int	calc_shadows(t_all_data *data, t_intersection intersection, t_vector start)
{
	t_vector	light;
	int			new_color;

	light = get_color_light(data, intersection, start);
	new_color = rgba(((intersection.color >> 16) & 0xff) * (light.x / 255), \
	((intersection.color >> 8) & 0xff) * (light.y / 255), \
	(intersection.color & 0xff) * (light.z / 255), 0);
	new_color = rgba(((new_color >> 16) & 0xff) + ((0x000000 >> 16) & 0xff), \
	((new_color >> 8) & 0xff) + ((0x000000 >> 8) & 0xff), \
	(new_color & 0xff) + (0x000000 & 0xff), \
	((new_color >> 24) & 0xff) + ((0x000000 >> 24) & 0xff));
	return (new_color);
}
