/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 08:41:22 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	background(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_H)
	{
		y = 0;
		while (y < WIN_W)
		{
			mlx_put_pixel(fdf->img, y, x, 0x1f2124FF);
			y++;
		}
		x++;
	}
}

void	free_exit(t_fdf *fdf)
{
	int	i;

	i = 0;
	mlx_close_hook(fdf->mlx, &draw_lines, fdf);
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_close_window(fdf->mlx);
	while (i < fdf->height)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
	free(fdf);
}

void	initialize(t_fdf *fdf)
{
	if (fdf->width > fdf->height * 1.5)
	{
		fdf->scale = (int)round(WIN_W / (fdf->height * 2.5));
		fdf->shiftx = WIN_W / 2.4;
	}
	else
	{
		fdf->scale = (int)round(WIN_W / (fdf->height * 1.7));
		fdf->shiftx = WIN_W / 2.1;
	}
	fdf->ncolor = 0;
	fdf->shifty = WIN_H / 9;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (argc != 2)
	{
		ft_putendl_fd("Invalid arguments number", 2);
		exit(0);
	}
	parser(fdf, argv[1]);
	initialize(fdf);
	fdf->mlx = mlx_init(WIN_W, WIN_H, "Fdf", true);
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	draw_lines(fdf);
	mlx_key_hook(fdf->mlx, &control_keys1, fdf);
	mlx_loop_hook(fdf->mlx, &draw_lines, fdf);
	mlx_loop(fdf->mlx);
	free_exit(fdf);
	system("leaks -q fdf");
	return (EXIT_SUCCESS);
}
