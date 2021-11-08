/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:35:16 by awhana            #+#    #+#             */
/*   Updated: 2021/05/10 21:37:39 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_TRIANGLE", data);
	while (**str == ' ')
		(*str)++;
}

//printf("cam_create : %p\n", new_cam);

static t_triangle	*create_triangle(t_all_data *data)
{
	t_triangle		*new_triangle;
	t_triangle		*iter;

	new_triangle = malloc(sizeof(t_triangle));
	if (new_triangle == NULL)
		write_error("FAILED ALLOCATION TRIANGLE", data);
	if (data->objects.triangle == NULL)
	{
		data->objects.triangle = new_triangle;
		data->objects.triangle->next = NULL;
	}
	else
	{
		iter = data->objects.triangle;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new_triangle;
		iter->next->next = NULL;
	}
	new_triangle->color = 0;
	return (new_triangle);
}

void	get_triangle(t_all_data *data, char *str)
{
	t_triangle		*triangle;

	triangle = create_triangle(data);
	str += 2;
	skip_space(data, &str);
	if (!get_cords(&str, &triangle->a))
		write_error("INCORRECT_TRIANGLE", data);
	skip_space(data, &str);
	if (!get_cords(&str, &triangle->b))
		write_error("INCORRECT_TRIANGLE", data);
	skip_space(data, &str);
	if (!get_cords(&str, &triangle->c))
		write_error("INCORRECT_TRIANGLE", data);
	skip_space(data, &str);
	if (!add_rgb(&str, &triangle->color))
		write_error("INCORRECT_TRIANGLE", data);
	if (*str != '\0')
		write_error("INCORRECT_TRIANGLE", data);
}
