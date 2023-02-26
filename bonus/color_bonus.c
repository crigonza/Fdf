/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:23:32 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/26 22:10:10 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

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

int	color2(t_coords *pt, t_fdf *fdf)
{
	if (pt->z <= 1)
		return (0xFFC05CFF);
	if (pt->z > 1 && pt->z < 3)
		return (0xFFB133FF);
	if (pt->z > 2 && pt->z < 6)
		return (0xFFA10AFF);
	if (pt->z > 5 && pt->z < 10)
		return (0xF2545BFF);
	if (pt->z > 9 && pt->z < 20)
		return (0xEE1B26FF);
	if (pt->z > 19 && pt->z < 50)
		return (0x6E4555FF);
	if (pt->z > 49 && pt->z < 100)
		return (0x084C61FF);
	if (pt->z > 99)
		return (0x177E89FF);
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
	else if (fdf->ncolor == 1)
		return (color2(pt, fdf));
	return (0xffffffFF);
}
