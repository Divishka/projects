/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsng6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:09:25 by awhana            #+#    #+#             */
/*   Updated: 2021/05/10 21:12:53 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_SPHERE", data);
	while (**str == ' ')
		(*str)++;
}

static t_sphere	*create_sphere(t_all_data *data)
{
	t_sphere		*new_sphere;
	t_sphere		*iter;

	new_sphere = malloc(sizeof(t_sphere));
	if (new_sphere == NULL)
		write_error("FAILED ALLOCATION SPHERE", data);
	if (data->objects.sphere == NULL)
	{
		data->objects.sphere = new_sphere;
		data->objects.sphere->next = NULL;
	}
	else
	{
		iter = data->objects.sphere;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new_sphere;
		iter->next->next = NULL;
	}
	new_sphere->color = 0;
	new_sphere->diameter = 0.0;
	return (new_sphere);
}

void	get_sphere(t_all_data *data, char *str)
{
	t_sphere		*sphere;

	sphere = create_sphere(data);
	str += 2;
	skip_space(data, &str);
	if (!get_cords(&str, &sphere->cords))
		write_error("INCORRECT_SPHERE", data);
	skip_space(data, &str);
	if (!get_double_strict(&str, &sphere->diameter, INT_MIN + 1, INT_MAX))
		write_error("INCORRECT_SPHERE", data);
	skip_space(data, &str);
	if (!add_rgb(&str, &sphere->color))
		write_error("INCORRECT_SPHERE", data);
	if (*str != '\0')
		write_error("INCORRECT_SPHERE", data);
}
