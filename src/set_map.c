/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:00:11 by crigonza          #+#    #+#             */
/*   Updated: 2022/10/05 18:37:49 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
		coords->y = - coords->z + 500;
		/* coords->x = (int)round((coords->x) * cos(M_PI / 4));
		coords->y = (int)round((coords->y) * sin(M_PI / 4) - coords->z); */
	}
}

void	rotation(t_coords *coord, t_fdf *fdf)
{
	float	x;
	float	y;
	float	z;

	x = (float)coord->x;
	y = (float)coord->y;
	z = (float)coord->z;
	coord->y = (int)round((y * cos(fdf->alpha)) + (z * sin(fdf->alpha)));
	coord->z = (int)round((-y * sin(fdf->alpha)) + (z * cos(fdf->alpha)));
	z = (float)coord->z;
	coord->x = (int)round((x * cos(fdf->beta)) + (z * sin(fdf->beta)));
	coord->z = (int)round((-x * sin(fdf->beta)) + (z * cos(fdf->beta)));
	x = (float)coord->x;
	y = (float)coord->y;
	coord->x = (int)round((x * cos(fdf->gamma)) - y * sin(fdf->gamma));
	coord->y = (int)round((x * sin(fdf->gamma)) + y * cos(fdf->gamma));
}

void	set_shift(t_fdf *fdf)
{
	if (fdf->projection == 1)
		{
			fdf->scale -= 1;
			fdf->scale -= 1;
		}
}

void	set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf)
{
	
	pt1->x = (pt1->x * fdf->scale);
	pt1->y = (pt1->y * fdf->scale);
	pt2->x = (pt2->x * fdf->scale);
	pt2->y = (pt2->y * fdf->scale);
	rotation(pt1, fdf);
	rotation(pt2, fdf);
	projection(pt1, fdf);
	projection(pt2, fdf);
	//if (fdf->projection != 0)
		//set_shift(fdf);
	pt1->x = (pt1->x + fdf->shiftx);
	pt1->y = (pt1->y + fdf->shifty);
	pt2->x = (pt2->x + fdf->shiftx);
	pt2->y = (pt2->y + fdf->shifty);
}