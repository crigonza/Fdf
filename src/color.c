/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:23:32 by crigonza          #+#    #+#             */
/*   Updated: 2022/10/05 19:01:22 by crigonza         ###   ########.fr       */
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
	int 	color[4];

	color[0] = (int)round((1 - dist) * get_red(color1) + dist * get_red(color2));
	color[1] = (int)round((1 - dist) * get_green(color1) + dist * get_green(color2));
	color[2] = (int)round((1 - dist) * get_blue(color1) + dist * get_blue(color2));
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
		if (pt->z > 4 && pt->z < 90)
			return (0x287233FF);
		if (pt->z > 89 && pt->z < 190)
			return (0x7a4736FF);
	}
	else if (fdf->ncolor == 1)
	{
        if (pt->z < 3)
            return(0xfeff33FF);
		if (pt->z > 2 && pt->z < 7)
			return (0xff5733FF);
		if (pt->z > 6 && pt->z < 20)
			return (0xba3f38FF);
        if (pt->z > 19)
            return (0xba3f38FF);
	}
	return (0xffffffFF);
}