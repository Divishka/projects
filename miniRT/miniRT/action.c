/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:47:01 by awhana            #+#    #+#             */
/*   Updated: 2021/05/11 12:27:38 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_image(t_image_data img_d, int color)
{
	int		x;
	int		y;
	void	*pixel;

	y = 0;
	while (y < img_d.height)
	{
		x = 0;
		while (x < img_d.width / (img_d.bpp / 8))
		{
			pixel = img_d.addr + (img_d.width * y + x * (img_d.bpp / 8));
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	setup_frame(t_all_data *data)
{
	t_image_data	img_d;

	img_d = data->imgs.frame;
	img_d.img_ptr = mlx_new_image(data->mlx, data->width, data->height);
	img_d.addr \
	= mlx_get_data_addr(img_d.img_ptr, &img_d.bpp, &img_d.width, &img_d.endian);
	img_d.height = data->height;
	data->imgs.frame = img_d;
}

void	setup_point(t_all_data *data)
{
	t_image_data	img_d;

	img_d = data->imgs.top;
	img_d.img_ptr = mlx_new_image(data->mlx, 80, 80);
	img_d.addr = \
	mlx_get_data_addr(img_d.img_ptr, &img_d.bpp, &img_d.width, &img_d.endian);
	img_d.height = 80;
	fill_image(img_d, 0xff000000);
	data->imgs.top = img_d;
}

void	setup_crt(t_all_data *data)
{
	t_image_data	img_d;

	img_d = data->imgs.crt;
	img_d.img_ptr = mlx_new_image(data->mlx, data->width, data->height);
	img_d.addr = \
	mlx_get_data_addr(img_d.img_ptr, &img_d.bpp, &img_d.width, &img_d.endian);
	data->imgs.crt = img_d;
}

void	setup_cameras(t_all_data *data)
{
	t_camera	*iter;

	iter = data->objects.cam;
	while (iter != NULL)
	{
		iter->view.img_ptr = mlx_new_image(data->mlx, data->width, \
		data->height);
		iter->view.addr = mlx_get_data_addr(iter->view.img_ptr, \
		&iter->view.bpp, &iter->view.width, &iter->view.endian);
		iter->view.height = data->height;
		iter = iter->next;
	}
}
