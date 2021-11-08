/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:44:11 by awhana            #+#    #+#             */
/*   Updated: 2021/05/13 09:52:23 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r' || str[*i] == '\v' \
	|| str[*i] == '\f' || str[*i] == '\n')
		(*i)++;
}

static void	get_num(t_all_data *data, char *str, int *i, char mode)
{
	int			*number;

	if (mode == 'w')
		number = &data->width;
	else
		number = &data->height;
	skip_space(str, i);
	if (str[*i] == '0' || str[*i] == '-')
		write_error("INCORRECT_RESOLUTION", data);
	while ('0' <= str[*i] && str[*i] <= '9')
		*number = *number * 10 + str[(*i)++] - '0';
}

static void	get_resolution(t_all_data *data, char *str)
{
	int		i;

	i = 1;
	if (str[i] != ' ')
		write_error("INCORRECT_RESOLUTION", data);
	get_num(data, str, &i, 'w');
	get_num(data, str, &i, 'h');
	if (str[i] != '\0' || data->width == 0 || data->height == 0)
		write_error("INCORRECT_RESOLUTION", data);
}

static void	parsing_string(t_all_data *data, char *str, int *r_and_a)
{
	if (str[0] == 'R' && r_and_a[0] == 'R')
		write_error("Resolution already set", data);
	if (str[0] == 'A' && r_and_a[1] == 'A')
		write_error("Ambient lightning already set", data);
	if (str[0] == 'R')
		get_resolution(data, str);
	else if (str[0] == 'A')
		get_ambient(data, str);
	else if (str[0] == 'c' && str[1] != 'y')
		get_camera(data, str);
	else if (str[0] == 'l')
		get_light(data, str);
	else if (str[0] == 'p' && str[1] == 'l')
		get_plane(data, str);
	else if (str[0] == 's' && str[1] == 'p')
		get_sphere(data, str);
	else if (str[0] == 's' && str[1] == 'q')
		get_square(data, str);
	else if (str[0] == 'c' && str[1] == 'y')
		get_cylinder(data, str + 2);
	else if (str[0] == 't' && str[1] == 'r')
		get_triangle(data, str);
}

void	parse_file(t_all_data *data, char *argv, int gnl)
{
	int		r_and_a[2];
	char	*str;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		write_error("Cant open scene file", data);
	while (gnl)
	{
		gnl = get_next_line(fd, &str);
		if (gnl < 0)
			write_error("GNL FAILED", data);
		parsing_string(data, str, r_and_a);
		if (str[0] == 'R')
			r_and_a[0] = 'R';
		else
			r_and_a[0] = 0;
		if (str[0] == 'A')
			r_and_a[0] = 'A';
		else
			r_and_a[0] = 0;
		free(str);
	}
	if (data->objects.cam == NULL)
		write_error("Incorrect camera", data);
}
