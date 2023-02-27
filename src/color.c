/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:23:32 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 08:43:28 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_red(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int	get_green(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int	get_blue(int rgba)
{
	return ((rgba >> 8) & 0xFF);
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

int	get_color(t_coords *pt, t_fdf *fdf)
{
	if (fdf->ncolor == 0)
	{
		if (pt->z <= 0)
			return (0x004172FF);
		if (pt->z > 0 && pt->z < 5)
			return (0x215589FF);
		if (pt->z > 4 && pt->z < 15)
			return (0xCEC3A1FF);
		if (pt->z > 14 && pt->z < 40)
			return (0x9D695AFF);
		if (pt->z > 39 && pt->z < 70)
			return (0x68453CFF);
		if (pt->z > 69 && pt->z < 110)
			return (0x157F1FFF);
		if (pt->z > 109 && pt->z < 180)
			return (0x0B4611FF);
	}
	return (0xffffffFF);
}
