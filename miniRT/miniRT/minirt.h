/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:42:13 by awhana            #+#    #+#             */
/*   Updated: 2021/05/17 11:01:31 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 50
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*----------------------------------------------------------*/
/*-------------------------KEY_BINDS------------------------*/
/*----------------------------------------------------------*/
# define TAB 48
# define ESC 53

/*----------------------------------------------------------*/
/*-------------------OBJECTS AND ELEMENTS-------------------*/
/*----------------------------------------------------------*/
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

typedef struct s_image_data
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}			t_image_data;

typedef struct s_image
{
	t_image_data	frame;
	t_image_data	crt;
	t_image_data	top;
}			t_image;

typedef struct s_camera
{
	t_vector		pov;
	t_vector		ori;
	int				fov;
	t_vector		normal;
	t_image_data	view;
	struct s_camera	*next;
}				t_camera;

typedef struct s_light
{
	t_vector		cords;
	float			ratio;
	int				color;
	struct s_light	*next;
}				t_light;

typedef struct s_plane
{
	t_vector			cords;
	t_vector			normal_vector;
	int					color;
	struct s_plane		*next;
}				t_plane;

typedef struct s_sphere
{
	t_vector			cords;
	int					color;
	double				diameter;
	struct s_sphere		*next;
}				t_sphere;

typedef struct s_square
{
	t_vector			cords;
	t_vector			normal_vector;
	int					color;
	double				side_size;
	struct s_square		*next;
}				t_square;

typedef struct s_cylinder
{
	t_vector			cords;
	t_vector			ori;
	int					color;
	double				diameter;
	double				height;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct s_triangle
{
	t_vector			a;
	t_vector			b;
	t_vector			c;
	t_vector			normal_vector;
	int					color;
	struct s_triangle	*next;
}				t_triangle;

typedef struct s_objects
{
	t_camera		*cam;
	t_light			*light;
	t_plane			*plane;
	t_sphere		*sphere;
	t_square		*square;
	t_triangle		*triangle;
	t_cylinder		*cylinder;
}			t_objects;

typedef struct s_intersection
{
	t_vector	point;
	int			color;
	t_objects	obj;
}				t_intersection;

// /*----------------------------------------------------------*/
// /*-------------------------ALL DATA-------------------------*/
// /*----------------------------------------------------------*/
typedef struct s_all_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			ambient;
	int			save;
	int			saver;
	t_image		imgs;
	t_objects	objects;
	t_camera	*cur_cam;
}			t_all_data;

/*----------------------------------------------------------*/
/*--------------------------EVENTS--------------------------*/
/*----------------------------------------------------------*/
void			write_error(char *str, t_all_data *data);
int				end_program(t_all_data *data);
int				key_pressed(int key, t_all_data *data);

/*----------------------------------------------------------*/
/*-------------------------PARSING--------------------------*/
/*----------------------------------------------------------*/
void			parse_file(t_all_data *data, char *argv, int gnl);
int				get_next_line(int fd, char **line);
void			get_ambient(t_all_data *data, char *str);
int				get_double_strict(char **str, double *num, int from, int to);
int				get_int_strict(char **str, long *num, int from, int to);
int				add_rgb(char **str, int *color);
int				get_cords(char **str, t_vector *cords);
void			get_camera(t_all_data *data, char *str);
void			get_light(t_all_data *data, char *str);
void			get_square(t_all_data *data, char *str);
void			get_sphere(t_all_data *data, char *str);
void			get_plane(t_all_data *data, char *str);
void			get_cylinder(t_all_data *data, char *str);
void			get_triangle(t_all_data *data, char *str);
int				ternar_operator3(int from, long *num, int to);
t_vector		ternar_operator_7(t_vector v1, t_vector v2);

/*----------------------------------------------------------*/
/*-------------------------CAMERAS--------------------------*/
/*----------------------------------------------------------*/
void			start_mini_rt(t_all_data *data);
void			fill_image(t_image_data dat, int color);
void			setup_point(t_all_data *data);
void			setup_frame(t_all_data *data);
void			setup_crt(t_all_data *data);
void			setup_cameras(t_all_data *data);

/*----------------------------------------------------------*/
/*------------------------RENDERING-------------------------*/
/*----------------------------------------------------------*/
void			put_pixel(t_image_data data, int x, int y, int color);
int				calc_shadows(t_all_data *data, t_intersection intersection, \
				t_vector start);
t_intersection	intersection_with_plane(t_all_data *data, \
				t_vector v1, t_vector v2);
int				closer(t_vector p_1, t_vector p_2, t_vector v_start);
t_vector		calculating_normal_vector(t_vector ori);
void			render(t_all_data *data, int fr);
void			start_mini_rt(t_all_data *data);
int				ray_trace(t_all_data *data, t_vector v1, t_vector v2);
t_intersection	inters_with_sphere(t_all_data *data, t_vector v1, t_vector v2);
void			render_cameras_views(t_all_data *data);
t_intersection	inters_with_square(t_all_data *data, t_vector v1, t_vector v2);
t_intersection	inters_with_cylinder(t_all_data *data, t_vector v1, \
				t_vector v2);
t_intersection	inters_with_triangle(t_all_data *data, t_vector v1, \
				t_vector v2);
void			create_screenshot(t_all_data *data);

/*----------------------------------------------------------*/
/*-------------------------FORMULS--------------------------*/
/*----------------------------------------------------------*/
t_vector		vector_normalize(t_vector vec);
double			length_of_vector(t_vector v);
t_vector		vector_cross(t_vector v1, t_vector v2);
t_vector		vector_plus(t_vector v1, double sign, t_vector v2);
t_vector		vector_minus(t_vector v1, t_vector v2);
t_vector		vector_multiply(t_vector v1, double k);
t_vector		vector_diverg(t_vector v1, double k);
t_vector		normal_for_plane(t_plane plane, t_vector start);
t_vector		normal_for_sphere(t_intersection inter, t_vector start);
t_vector		normal_for_square(t_square square, t_vector start);
t_vector		normal_for_cylinder(t_intersection inter, t_vector start);
t_vector		normal_for_triangle(t_triangle triangle, t_vector start);
int				rgba(int r, int g, int b, int a);
double			vector_dot(t_vector v1, t_vector v2);
t_vector		get_normal_vec(t_all_data *data, t_vector p);
double			vector_cos(t_vector v1, t_vector v2);

#endif
