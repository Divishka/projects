/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:47:06 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:54:48 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_AMBIENT", data);
	while (**str == ' ')
		(*str)++;
}

void	get_ambient(t_all_data *data, char *str)
{
	double		alpha;

	str++;
	skip_space(data, &str);
	if (!get_double_strict(&str, &alpha, 0, 1))
		write_error("INCORRECT_AMBIENT", data);
	data->ambient = (1 - alpha) * 255;
	skip_space(data, &str);
	if (!add_rgb(&str, &data->ambient))
		write_error("INCORRECT_AMBIENT", data);
	if (*str != '\0')
		write_error("INCORRECT_AMBIENT", data);
}

int	get_cords(char **str, t_vector *cords)
{
	if (!get_double_strict(str, &cords->x, INT_MIN + 1, INT_MAX))
		return (0);
	if (*(*str)++ != ',')
		return (0);
	if (!get_double_strict(str, &cords->y, INT_MIN + 1, INT_MAX))
		return (0);
	if (*(*str)++ != ',')
		return (0);
	if (!get_double_strict(str, &cords->z, INT_MIN + 1, INT_MAX))
		return (0);
	return (1);
}
