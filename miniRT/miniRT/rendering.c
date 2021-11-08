/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:37:17 by awhana            #+#    #+#             */
/*   Updated: 2021/05/16 16:41:28 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_rotate(t_vector vector, t_vector axis, double angle)
{
	double		m[3][3];
	double		cosa;
	double		sina;
	t_vector	new_v;

	cosa = cos(angle * M_PI / 180);
	sina = sin(angle * M_PI / 180);
	m[0][0] = cosa + (1 - cosa) * axis.x * axis.x;
	m[0][1] = (1 - cosa) * axis.x * axis.y - sina * axis.z;
	m[0][2] = (1 - cosa) * axis.x * axis.z + sina * axis.y;
	m[1][0] = (1 - cosa) * axis.y * axis.x + sina * axis.z;
	m[1][1] = cosa + (1 - cosa) * axis.y * axis.y;
	m[1][2] = (1 - cosa) * axis.y * axis.z - sina * axis.x;
	m[2][0] = (1 - cosa) * axis.z * axis.x - sina * axis.y;
	m[2][1] = (1 - cosa) * axis.z * axis.y + sina * axis.x;
	m[2][2] = cosa + (1 - cosa) * axis.z * axis.z;
	new_v.x = m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z;
	new_v.y = m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z;
	new_v.z = m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z;
	return (new_v);
}

static t_vector	move_on_row(t_all_data *data, t_camera *cam, \
t_vector vector, int row)
{
	double		height_scaling;
	t_vector	normal_vector;

	height_scaling = length_of_vector(cam->ori);
	height_scaling *= (((double)cam->fov / data->width) * M_PI / 180);
	height_scaling *= (data->height / -2.0 + row);
	normal_vector = vector_multiply(cam->normal, height_scaling);
	vector = vector_plus(vector, 1, normal_vector);
	return (vector);
}

static void	render_view_for_cam(t_all_data *data, t_camera *cam)
{
	t_vector	or;
	int			column;
	int			row;
	double		x;

	cam->normal = calculating_normal_vector(cam->ori);
	row = 0;
	while (row < data->height)
	{
		column = 0;
		x = 0;
		while (x < cam->fov && cam->fov)
		{
			or = vector_rotate(cam->ori, cam->normal, cam->fov / -2 + x);
			or = move_on_row(data, cam, or, row);
			or = vector_plus(or, 1, cam->pov);
			put_pixel(cam->view, column, row, ray_trace(data, cam->pov, or));
			column++;
			x += (double)cam->fov / data->width;
		}
		row++;
	}
}

void	render_cameras_views(t_all_data *data)
{
	int			cam_num;
	int			count_cam;
	t_camera	*cam;

	count_cam = 0;
	cam = data->objects.cam;
	while (cam != NULL)
	{
		count_cam++;
		cam = cam->next;
	}
	cam_num = 1;
	cam = data->objects.cam;
	while (cam != NULL)
	{
		render_view_for_cam(data, cam);
		cam_num++;
		cam = cam->next;
	}
}

void	render(t_all_data *data, int fr)
{
	if (fr)
	{
		fill_image(data->imgs.frame, 0x000000);
		mlx_put_image_to_window(data->mlx, data->win, \
		data->imgs.frame.img_ptr, 0, 0);
		render_cameras_views(data);
		mlx_clear_window(data->mlx, data->win);
	}
	mlx_put_image_to_window(data->mlx, data->win, \
	data->cur_cam->view.img_ptr, 0, 0);
}
