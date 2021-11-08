/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:02:37 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 10:45:33 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_LIGHT", data);
	while (**str == ' ')
		(*str)++;
}

static t_light	*create_light(t_all_data *data)
{
	t_light		*light;
	t_light		*iter;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		write_error("Failed allocation for light", data);
	if (data->objects.light == NULL)
	{
		data->objects.light = light;
		data->objects.light->next = NULL;
	}
	else
	{
		iter = data->objects.light;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = light;
		iter->next->next = NULL;
	}
	light->color = 0;
	return (light);
}

void	get_light(t_all_data *data, char *str)
{
	t_light		*light;
	double		alpha;

	light = create_light(data);
	str++;
	skip_space(data, &str);
	if (!get_cords(&str, &light->cords))
		write_error("INCORRECT_LIGHT1", data);
	skip_space(data, &str);
	if (!get_double_strict(&str, &alpha, 0, 1))
		write_error("INCORRECT_LIGHT2", data);
	light->color = (1 - alpha) * 255;
	skip_space(data, &str);
	if (!add_rgb(&str, &light->color))
		write_error("INCORRECT_LIGHT3", data);
	if (*str != '\0')
		write_error("INCORRECT_LIGHT4", data);
}
