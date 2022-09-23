/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:00:11 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/23 18:52:02 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parallel_view(t_coords *coords, int z)
{
	coords->x = (int)round((coords->x) * cos(M_PI / 4));
	coords->y = (int)round((coords->y) * sin(M_PI / 4) - z);
}

void	isometric_view(t_coords *coords)
{
	coords->x = (int)round((coords->x - coords->y) * (0.50));
	coords->y = (int)round((coords->x + coords->y) * (0.75) - coords->z);
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

int	get_color(t_coords *pt)
{
	/* if (z1 > z2)
		return (0xff0000);
	if (z1 < z2)
		return (0x0000ff);
	if (z1 > 0)
		return (0x6f00ff);
	if (z1 < 0)
		return (0x00e5ff); */
	if (pt->z == 0)
		return (0x0A497BFF);
	if (pt->z > 0 && pt->z < 5)
		return (0x00AAE4FF);
	if (pt->z > 4 && pt->z < 100)
		return (0x268E00FF);
	if (pt->z > 99 && pt->z < 180)
		return (0xB9935AFF);
	return (0xffffffFF);
}

void	set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf)
{
	fdf->color = get_color(pt1);
	pt1->x = (pt1->x * fdf->scale);
	pt1->y = (pt1->y * fdf->scale);
	pt2->x = (pt2->x * fdf->scale);
	pt2->y = (pt2->y * fdf->scale);
	rotation(pt1, fdf);
	rotation(pt2, fdf);
	isometric_view(pt1);
	isometric_view(pt2);
	//parallel_view(pt1, z1);
	//parallel_view(pt2, z2);
	pt1->x = (pt1->x + fdf->shiftx);
	pt1->y = (pt1->y + fdf->shifty);
	pt2->x = (pt2->x + fdf->shiftx);
	pt2->y = (pt2->y + fdf->shifty);
}