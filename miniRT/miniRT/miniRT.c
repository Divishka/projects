/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:41:52 by awhana            #+#    #+#             */
/*   Updated: 2021/05/19 10:27:04 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_mini_rt(t_all_data *data)
{
	setup_frame(data);
	setup_point(data);
	setup_crt(data);
	setup_cameras(data);
	render(data, 1);
	if (data->save)
	{
		create_screenshot(data);
		exit(0);
	}
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 17, 0, end_program, data);
	mlx_loop(data->mlx);
}

static	t_all_data	init_struct(t_all_data data)
{
	data.width = 0;
	data.height = 0;
	data.ambient = 0;
	data.saver = 1;
	data.objects.plane = NULL;
	data.objects.light = NULL;
	data.objects.sphere = NULL;
	data.objects.plane = NULL;
	data.objects.triangle = NULL;
	data.objects.cylinder = NULL;
	data.objects.square = NULL;
	data.objects.cam = NULL;
	data.cur_cam = NULL;
	return (data);
}

int	main(int argc, char **av)
{
	t_all_data	data;
	int			width;
	int			height;
	int			len;

	if (argc > 3 || argc == 1 || (argc == 3 && !ft_strequ(av[2], "--save")))
		write_error("Wrong arguments", &data);
	len = ft_strlen(av[1]) - 1;
	if (av[1][len] != 't' || av[1][len - 1] != 'r' || av[1][len - 2] != '.')
		write_error("Not .rt file", &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		write_error("Failed initialize of MinilibX", &data);
	data = init_struct(data);
	parse_file(&data, av[1], 1);
	if (ft_strequ(av[2], "--save"))
		data.save = 1;
	mlx_get_screen_size(data.mlx, &width, &height);
	if (data.width > width)
		data.width = width;
	if (data.height > height)
		data.height = height;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	start_mini_rt(&data);
	return (1);
}
