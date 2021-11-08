/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:59:25 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 10:49:43 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_space(t_all_data *data, char **str)
{
	if (**str != ' ')
		write_error("INCORRECT_CAMERAAA", data);
	while (**str == ' ')
		(*str)++;
}

static t_camera	*create_cam(t_all_data *data)
{
	t_camera	*new_cam;
	t_camera	*iter;

	new_cam = malloc(sizeof(t_camera));
	if (new_cam == NULL)
		write_error("Failed allocation for camera", data);
	if (data->objects.cam == NULL)
	{
		data->objects.cam = new_cam;
		data->objects.cam->next = NULL;
	}
	else
	{
		iter = data->objects.cam;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new_cam;
		iter->next->next = NULL;
	}
	return (new_cam);
}

void	get_camera(t_all_data *data, char *str)
{
	t_camera	*cam;

	cam = create_cam(data);
	str++;
	skip_space(data, &str);
	if (!get_cords(&str, &cam->pov))
		write_error("INCORRECT_CAMERA1", data);
	skip_space(data, &str);
	if (!get_cords(&str, &cam->ori))
		write_error("INCORRECT_CAMERA2", data);
	if (1 < cam->ori.x || cam->ori.x < -1 || 1 < cam->ori.y || cam->ori.y < -1 \
		|| 1 < cam->ori.z || cam->ori.z < -1 || length_of_vector(cam->ori) > 1 \
		|| length_of_vector(cam->ori) == 0)
		write_error("INCORRECT_CAMERA3", data);
	skip_space(data, &str);
	if (!get_int_strict(&str, (long *)(&cam->fov), 0, 3600))
		write_error("INCORRECT_CAMERA4", data);
	if (*str != '\0')
		write_error("INCORRECT_CAMERA5", data);
	data->cur_cam = data->objects.cam;
}
