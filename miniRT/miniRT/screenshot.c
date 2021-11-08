/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:45:09 by awhana            #+#    #+#             */
/*   Updated: 2021/05/17 10:54:39 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*invert_image(t_all_data *data, t_image_data img)
{
	ssize_t		x;
	ssize_t		y;
	ssize_t		size;
	char		*result;

	size = img.width * img.height * sizeof(char);
	result = malloc(size);
	if (result == NULL)
		write_error("Can't invert", data);
	y = 0;
	size--;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width / (img.bpp / 8))
		{
			*(int *)(result + (img.width * y + x * (img.bpp / 8))) = *(int *)(img.addr \
			+ (img.height - y) * img.width + x * img.bpp / 8);
			x++;
		}
		y++;
	}
	return (result);
}

static void	w_screen1(t_all_data *data, t_camera *cam, int file)
{
	short			short_tmp;
	unsigned int	unsign_tmp;

	if (cam == NULL)
		return ;
	write(file, "BM", 2);
	unsign_tmp = 54 + cam->view.bpp / 8 * cam->view.width * cam->view.height;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 0;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 54;
	write(file, &unsign_tmp, 4);
	unsign_tmp = 40;
	write(file, &unsign_tmp, 4);
	write(file, &data->width, 4);
	write(file, &data->height, 4);
	short_tmp = 1;
	write(file, &short_tmp, 2);
}

static void	w_screen2(t_all_data *data, t_camera *cam, int file)
{
	unsigned int	tmp;
	char			*img;

	write(file, &cam->view.bpp, 2);
	tmp = 0;
	write(file, &tmp, 4);
	write(file, &tmp, 4);
	tmp = data->width;
	write(file, &tmp, 4);
	tmp = data->height;
	write(file, &tmp, 4);
	tmp = 0;
	write(file, &tmp, 4);
	write(file, &tmp, 4);
	img = invert_image(data, cam->view);
	write(file, img, cam->view.width * cam->view.height);
	free(img);
}

static int	o_or_c(t_all_data *data, int number, char *file_name)
{
	int			file;
	char		*str_num;
	char		*full_file_name;

	str_num = ft_itoa(number);
	if (str_num == NULL)
		write_error("Can't save it", data);
	full_file_name = ft_strjoin(str_num, file_name);
	if (full_file_name == NULL)
	{
		free(str_num);
		write_error("Can't save it", data);
	}
	file = open(full_file_name, O_RDWR | O_CREAT, 0777);
	free(str_num);
	free(full_file_name);
	if (file < 0)
		write_error("Can't save it", data);
	return (file);
}

void	create_screenshot(t_all_data *data)
{
	int			file;
	int			count;
	t_camera	*iter;

	count = 1;
	iter = data->objects.cam;
	while (iter != NULL)
	{
		file = o_or_c(data, count, "Screenshot.bmp");
		w_screen1(data, iter, file);
		w_screen2(data, iter, file);
		close(file);
		iter = iter->next;
		count++;
	}
}
