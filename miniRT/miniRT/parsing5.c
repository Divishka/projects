/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:02:56 by awhana            #+#    #+#             */
/*   Updated: 2021/05/10 21:07:16 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_PLANE", data);
	while (**str == ' ')
		(*str)++;
}

static t_plane	*create_plane(t_all_data *data)
{
	t_plane		*new_plane;
	t_plane		*iter;

	new_plane = malloc(sizeof(t_plane));
	if (new_plane == NULL)
		write_error("FAILED ALLOCATION PLANE", data);
	if (data->objects.plane == NULL)
	{
		data->objects.plane = new_plane;
		data->objects.plane->next = NULL;
	}
	else
	{
		iter = data->objects.plane;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new_plane;
		iter->next->next = NULL;
	}
	new_plane->color = 0;
	return (new_plane);
}

void	get_plane(t_all_data *data, char *str)
{
	t_plane		*plane;

	plane = create_plane(data);
	str += 2;
	skip_space(data, &str);
	if (!get_cords(&str, &plane->cords))
		write_error("INCORRECT PLANE", data);
	skip_space(data, &str);
	if (!get_cords(&str, &plane->normal_vector))
		write_error("INCORRECT PLANE", data);
	if (1 < plane->normal_vector.x || plane->normal_vector.x < -1 \
		|| 1 < plane->normal_vector.y || plane->normal_vector.y < -1 \
		|| 1 < plane->normal_vector.z || plane->normal_vector.z < -1 \
		|| length_of_vector(plane->normal_vector) > 1 \
		|| length_of_vector(plane->normal_vector) == 0)
		write_error("INCORRECT PLANE", data);
	skip_space(data, &str);
	if (!add_rgb(&str, &plane->color))
		write_error("INCORRECT PLANE", data);
	if (*str != '\0')
		write_error("INCORRECT PLANE", data);
}
