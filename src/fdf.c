/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/23 18:58:11 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	control_keys(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		fdf->alpha += 0.05;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		fdf->alpha -= 0.05;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		fdf->beta += 0.05;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		fdf->beta -= 0.05;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		fdf->gamma += 0.05;
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		fdf->gamma -= 0.05;
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		fdf->scale += 1;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		fdf->scale -= 1;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fdf->shifty -= 10;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fdf->shifty += 10;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fdf->shiftx -= 10;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fdf->shiftx += 10;
}

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
    mlx_put_string(fdf->mlx, "PRESS ESC TO EXIT", 50, 170);
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
	mlx_key_hook(fdf->mlx, &control_keys, fdf);
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
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_terminate(fdf->mlx);
	/* while (i < fdf->height)
    {
        j = 0;
        while (j < fdf->width)
        {
            printf("%s ", fdf->color_inc[i][j]);
            j++;
        }
        printf("\n");
        i++;
    } */
	return (EXIT_SUCCESS);
}