/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:12:34 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 12:37:21 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	set_projection(t_fdf *fdf)
{
	if (fdf->projection == 2)
		fdf->projection = 0;
	else if (fdf->projection == 1)
		fdf->projection = 2;
	else if (fdf->projection == 0)
		fdf->projection = 1;
}

void	set_color(t_fdf *fdf)
{
	if (fdf->ncolor == 0)
		fdf->ncolor = 1;
	else if (fdf->ncolor == 1)
		fdf->ncolor = 0;
}

int	scale_control(t_fdf *fdf)
{
	if (fdf->width > 250 && fdf->scale < 2)
		return (0);
	if (fdf->width > 80 && fdf->width < 250 && fdf->scale < 4)
		return (0);
	else
		return (1);
}

void	control_keys1(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(fdf->mlx);
	}
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
		fdf->scale -= scale_control(fdf);
	control_keys2(keydata, fdf);
}

void	control_keys2(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fdf->shifty -= 10;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fdf->shifty += 10;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fdf->shiftx -= 10;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fdf->shiftx += 10;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		set_projection(fdf);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		set_color(fdf);
}
