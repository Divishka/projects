/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:29:57 by awhana            #+#    #+#             */
/*   Updated: 2021/05/10 21:33:53 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT CYLINDER", data);
	while (**str == ' ')
		(*str)++;
}

static t_cylinder	*create_cylinder(t_all_data *data)
{
	t_cylinder		*new_cylinder;
	t_cylinder		*iterator;

	new_cylinder = malloc(sizeof(t_cylinder));
	if (new_cylinder == NULL)
		write_error("FAILED ALLOCATION CYLINDER", data);
	if (data->objects.cylinder == NULL)
	{
		data->objects.cylinder = new_cylinder;
		data->objects.cylinder->next = NULL;
	}
	else
	{
		iterator = data->objects.cylinder;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = new_cylinder;
		iterator->next->next = NULL;
	}
	new_cylinder->color = 0;
	return (new_cylinder);
}

void	get_cylinder(t_all_data *data, char *str)
{
	t_cylinder		*cylinder;

	cylinder = create_cylinder(data);
	skip_space(data, &str);
	if (!get_cords(&str, &cylinder->cords))
		write_error("INCORRECT_CYLINDER", data);
	skip_space(data, &str);
	if (!get_cords(&str, &cylinder->ori))
		write_error("INCORRECT_CYLINDER", data);
	if (length_of_vector(cylinder->ori) > 1 || \
	length_of_vector(cylinder->ori) == 0)
		write_error("INCORRECT_CYLINDER", data);
	cylinder->ori = vector_multiply(cylinder->ori, \
	1.0 / length_of_vector(cylinder->ori));
	skip_space(data, &str);
	if (!get_double_strict(&str, &cylinder->diameter, INT_MIN + 1, INT_MAX))
		write_error("INCORRECT_CYLINDER", data);
	skip_space(data, &str);
	if (!get_double_strict(&str, &cylinder->height, INT_MIN + 1, INT_MAX))
		write_error("INCORRECT_CYLINDER", data);
	skip_space(data, &str);
	if (!add_rgb(&str, &cylinder->color))
		write_error("INCORRECT_CYLINDER", data);
	if (*str != '\0')
		write_error("INCORRECT_CYLINDER", data);
}
