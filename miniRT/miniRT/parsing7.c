/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:14:55 by awhana            #+#    #+#             */
/*   Updated: 2021/05/10 21:27:24 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_SQUARE", data);
	while (**str == ' ')
		(*str)++;
}

static t_square	*create_square(t_all_data *data)
{
	t_square		*new_square;
	t_square		*iter;

	new_square = malloc(sizeof(t_square));
	if (new_square == NULL)
		write_error("FAILED ALLOCATION SQUARE", data);
	if (data->objects.square == NULL)
	{
		data->objects.square = new_square;
		data->objects.square->next = NULL;
	}
	else
	{
		iter = data->objects.square;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new_square;
		iter->next->next = NULL;
	}
	new_square->color = 0;
	return (new_square);
}

void	get_square(t_all_data *data, char *str)
{
	t_square		*square;

	square = create_square(data);
	str += 2;
	skip_space(data, &str);
	if (!get_cords(&str, &square->cords))
		write_error("INCORRECT_SQUARE", data);
	skip_space(data, &str);
	if (!get_cords(&str, &square->normal_vector))
		write_error("INCORRECT_SQUARE", data);
	if (length_of_vector(square->normal_vector) > 1
		|| length_of_vector(square->normal_vector) == 0)
		write_error("INCORRECT_SQUARE", data);
	square->normal_vector = vector_multiply(square->normal_vector, \
	1.0 / length_of_vector(square->normal_vector));
	skip_space(data, &str);
	if (!get_double_strict(&str, &square->side_size, INT_MIN + 1, INT_MAX))
		write_error("INCORRECT_SQUARE", data);
	skip_space(data, &str);
	if (!add_rgb(&str, &square->color))
		write_error("INCORRECT_SQUARE", data);
	if (*str != '\0')
		write_error("INCORRECT_SQUARE", data);
}
