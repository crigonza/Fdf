/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:00:11 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/26 22:11:04 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

void	isometric_view(t_coords *coords)
{
	coords->x = (int)round((coords->x - coords->y) * (0.50));
	coords->y = (int)round((coords->x + coords->y) * (0.75) - coords->z);
}

void	projection(t_coords *coords, t_fdf *fdf)
{
	if (fdf->projection == 0)
		isometric_view(coords);
	else if (fdf->projection == 1)
	{
		coords->x = coords->x - 300;
		coords->y = coords->y - 100;
	}
	else if (fdf->projection == 2)
	{
		coords->x = coords->y - 300;
		coords->y = -coords->z + 500;
	}
}

int	gradient(int color1, int color2, double dist)
{
	int	color[4];

	color[0] = (int)round((1 - dist) * get_red(color1) + dist
			* get_red(color2));
	color[1] = (int)round((1 - dist) * get_green(color1) + dist
			* get_green(color2));
	color[2] = (int)round((1 - dist) * get_blue(color1) + dist
			* get_blue(color2));
	color[3] = color2 & 0xFF;
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}

void	rotation(t_coords *coord, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;

	x = (float)coord->x;
	y = (float)coord->y;
	z = (float)coord->z;
	x = (float)coord->x;
	coord->y = (int)round((y * cos(fdf->alpha)) - z * sin(fdf->alpha));
	coord->z = (int)round((y * sin(fdf->alpha)) + z * cos(fdf->alpha));
	z = (float)coord->z;
	coord->x = (int)round((x * cos(fdf->beta)) +(z * sin(fdf->beta)));
	y = (float)coord->y;
	coord->z = (int)round((-x * sin(fdf->beta)) + (z * cos(fdf->beta)));
	coord->x = (int)round((x * cos(fdf->gamma)) - (y * sin(fdf->gamma)));
	coord->y = (int)round((x * sin(fdf->gamma)) + (y * cos(fdf->gamma)));
}

void	set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf)
{
	pt1->x = (pt1->x * fdf->scale);
	pt1->y = (pt1->y * fdf->scale);
	pt1->z = (pt1->z * fdf->scale / 8);
	pt2->x = (pt2->x * fdf->scale);
	pt2->y = (pt2->y * fdf->scale);
	pt2->z = (pt2->z * fdf->scale / 8);
	rotation(pt1, fdf);
	rotation(pt2, fdf);
	projection(pt1, fdf);
	projection(pt2, fdf);
	pt1->x = (pt1->x + fdf->shiftx);
	pt1->y = (pt1->y + fdf->shifty);
	pt2->x = (pt2->x + fdf->shiftx);
	pt2->y = (pt2->y + fdf->shifty);
}
