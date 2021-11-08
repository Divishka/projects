/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:44:41 by awhana            #+#    #+#             */
/*   Updated: 2021/05/19 11:18:38 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	end_program(t_all_data *data)
{
	(void)data;
	exit(1);
}

void	put_pixel(t_image_data data, int x, int y, int color)
{
	void	*pixel;

	pixel = data.addr + (data.width * y + x * (data.bpp / 8));
	*(int *)pixel = color;
}

void	write_error(char *str, t_all_data *data)
{
	(void)data;
	printf("%s\n", str);
	exit(1);
}

int	key_pressed(int key, t_all_data *data)
{
	if (key == TAB)
	{
		if (data->cur_cam->next == NULL)
			data->cur_cam = data->objects.cam;
		else
			data->cur_cam = data->cur_cam->next;
		render(data, 0);
	}
	if (key == ESC)
		end_program(data);
	printf("%d\n", key);
	return (0);
}

t_vector	ternar_operator_7(t_vector v1, t_vector v2)
{
	if (v2.x + v1.x < 255)
		v2.x = v2.x + v1.x;
	else
		v2.x = 255;
	if (v2.y + v1.y < 255)
		v2.y = v2.y + v1.y;
	else
		v2.y = 255;
	if (v2.z + v1.z < 255)
		v2.z = v2.z + v1.z;
	else
		v2.z = 255;
	return (v2);
}
