/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:40:19 by crigonza          #+#    #+#             */
/*   Updated: 2023/03/30 11:45:41 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../GNL/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_H 1080
# define WIN_W 1920

typedef struct s_coords
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_coords;

typedef struct s_fdf
{
	int			**map;
	int			height;
	int			width;
	int			ncolor;
	int			color;
	float		alpha;
	float		beta;
	float		gamma;
	int			scale;
	int			shiftx;
	int			shifty;
	int			projection;
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_fdf;

typedef struct s_algor
{
	t_coords	begin;
	int			dx;
	int			dy;
	int			check;
	double		ldist;
}				t_algor;

//parse_file.c
int				get_width(char *line);
int				get_height(char *file);
int				**allocate_map(int height, int width);
void			split_to_map(t_fdf *fdf, char **split_line, int i);
void			parser(t_fdf *fdf, char *file, int fd);
//set_map.c
void			isometric_view(t_coords *coords);
void			set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf);
//draw_map.c
void			put_pixel(t_fdf *fdf, t_coords *pt1, t_coords *pt2,
					double dist);
double			line_percent(int start, int current, int end);
void			draw_lines(t_fdf *fdf);
void			line_algorithm(t_fdf *fdf, t_coords pt1, t_coords pt2);
int				line_algorithm_2(t_coords *pt1, t_coords *pt2, t_algor *algo,
					int error);
//utils.c
int				abs_val(int num);
int				check_points(int x, int x2);
int				check_map(char *argv, int argc);
void			free_split(char **split_line);
t_coords		set_coords(int x, int y, t_fdf *fdf);
//controls.c
void			set_color(t_fdf *fdf);
void			control_keys1(mlx_key_data_t keydata, t_fdf *fdf);
//color.c
int				get_red(int rgba);
int				get_green(int rgba);
int				get_blue(int rgba);
int				gradient(int color1, int color2, double dist);
int				get_color(t_coords *pt, t_fdf *fdf);
//fdf.c
int				main(int argc, char **argv);
void			background(t_fdf *fdf);
void			free_exit(t_fdf *fdf);
void			initialize(t_fdf *fdf);

#endif