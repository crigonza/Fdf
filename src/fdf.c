/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/10/05 21:10:21 by crigonza         ###   ########.fr       */
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

void	free2(int *map, int w)
{
	int i;

	i = 0;
	while (i < w)
	{
		free(map[i]);
		i++;
	}
}

void	free_exit(int **map, int h, int w)
{
	int	i;
	
	i = 0;
	while (i < h)
	{
		free2(map[i], w);
		i++;
	}
	free (map);
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
	mlx_put_string(fdf->mlx, "PRESS A-W FOR Y AXIS", 50, 130);
	mlx_put_string(fdf->mlx, "PRESS Z-X FOR Z AXIS", 50, 150);
    mlx_put_string(fdf->mlx, "PRESS C TO CHANGE COLORS", 50, 170);
    mlx_put_string(fdf->mlx, "PRESS ESC TO EXIT", 50, 190);

}

int	main(int argc, char **argv)
{
	t_fdf *fdf;
	//mlx_image_t *fdf->img;
	int i = 0;
	int j = 0;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (argc != 2)
	{
		ft_putendl_fd("Invalid arguments number", 2);
		exit(0);
	}
	parser(fdf, argv[1]);
	printf("%d\n", fdf->width);
	printf("%d\n", fdf->height);
	initialize(fdf);
	fdf->mlx = mlx_init(WIN_W, WIN_H, "Fdf", true);
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	draw_lines(fdf);
	controls_text(fdf);
	//hook (fdf);
	mlx_key_hook(fdf->mlx, &control_keys1, fdf);
	/* while (i < fdf->height)
    {
        j = 0;
        while(j < fdf->width)
        {
            mlx_put_pixel(fdf->img, (WIN_W /fdf->width) * j ,(WIN_H
			/ fdf->height) * i, 0xFFFFFFFF);
            j++;
        }
        i++;
    } */
	//line_algorithm(fdf, set_coords(1, 1), set_coords(1, 2));
	mlx_loop_hook(fdf->mlx, &draw_lines, fdf);
	mlx_loop(fdf->mlx);
	//mlx_close_hook(fdf->mlx, &draw_lines, fdf);
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_close_window(fdf->mlx);
	mlx_terminate(fdf->mlx);
	//free_exit(fdf->map, fdf->height, fdf->width);
	//free(fdf->mlx);
	//free(fdf->img);
	ft_memset(fdf->img->pixels, 0, WIN_W * WIN_H * sizeof(int));
	free(fdf->map);
	free(fdf);
	/* while (i < fdf->height)
    {
        j = 0;
        while (j < fdf->width)
        {
            printf("%d ", fdf->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    } */
	//free_exit(fdf->map, fdf);
	return (EXIT_SUCCESS);
}