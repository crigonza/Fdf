/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 14:14:10 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

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
	fdf->projection = 0;
	fdf->ncolor = 0;
	fdf->shifty = WIN_H / 9;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
}

void	controls_text(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "PRESS SPACE FOR CHANGE PERSPECTIVE", 50, 30);
	mlx_put_string(fdf->mlx, "PRESS ARROW KEYS TO MOVE MAP", 50, 50);
	mlx_put_string(fdf->mlx, "PRESS O-P KEYS TO ZOOM IN-OUT", 50, 70);
	mlx_put_string(fdf->mlx, "ROTATION:", 50, 90);
	mlx_put_string(fdf->mlx, "PRESS Q-W FOR X AXIS", 50, 110);
	mlx_put_string(fdf->mlx, "PRESS A-S FOR Y AXIS", 50, 130);
	mlx_put_string(fdf->mlx, "PRESS Z-X FOR Z AXIS", 50, 150);
	mlx_put_string(fdf->mlx, "PRESS C TO CHANGE COLORS", 50, 170);
	mlx_put_string(fdf->mlx, "PRESS ESC TO EXIT", 50, 190);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	check_map(argv[1]);
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
	controls_text(fdf);
	mlx_key_hook(fdf->mlx, &control_keys1, fdf);
	mlx_loop_hook(fdf->mlx, &draw_lines, fdf);
	mlx_loop(fdf->mlx);
	free_exit(fdf);
	system("leaks -q fdf");
	return (EXIT_SUCCESS);
}
