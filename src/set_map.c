/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:00:11 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 11:44:15 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric_view(t_coords *coords)
{
	coords->x = (int)round((coords->x - coords->y) * (0.50));
	coords->y = (int)round((coords->x + coords->y) * (0.75) - coords->z);
}

void	set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf)
{
	pt1->x = (pt1->x * fdf->scale);
	pt1->y = (pt1->y * fdf->scale);
	pt2->x = (pt2->x * fdf->scale);
	pt2->y = (pt2->y * fdf->scale);
	isometric_view(pt1);
	isometric_view(pt2);
	pt1->x = (pt1->x + fdf->shiftx);
	pt1->y = (pt1->y + fdf->shifty);
	pt2->x = (pt2->x + fdf->shiftx);
	pt2->y = (pt2->y + fdf->shifty);
}
