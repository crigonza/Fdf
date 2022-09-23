/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:05:05 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/22 21:28:37 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_coords    set_coords(int x, int y, t_fdf *fdf)
{
    t_coords    coords;

    coords.x = x;
    coords.y = y;
    coords.z = fdf->map[y][x];
    return (coords);
}

put_pixel (t_fdf *fdf, t_coords *pt1)
{
    if (pt1->x >= 0 && pt1->y >= 0 && pt1->x < 1920 && pt1->x < 1920)
        mlx_put_pixel(fdf->img, pt1->x, pt1->y, fdf->color);
}

void    line_algorithm(t_fdf *fdf, t_coords pt1, t_coords pt2)
{
    int dx;
    int dy;
    int error;
    int check;

    set_point(&pt1, &pt2, fdf);
    dx = abs_val(pt2.x - pt1.x);
    dy = abs_val(pt2.y - pt1.y);
    error = dx - dy;
    while (pt1.x != pt2.x || pt1.y != pt2.y)
    {
        put_pixel(fdf, &pt1);
        check = error * 2;
        if (check > -dy)
        {
            pt1.x += check_points(pt1.x, pt2.x);
            error -= dy;   
        }
        if (check < dx)
        {
            pt1.y += check_points(pt1.y, pt2.y);
            error += dx;
        }
    }
}

void    draw_lines(t_fdf *fdf)
{
    int x;
    int y;

    ft_memset(fdf->img->pixels, 0, WIN_W * WIN_H * sizeof(int));
    background(fdf);
    y = 0;
    while (y < fdf->height)
    {
        x = 0;
        while (x < fdf->width)
        {
            if (x < fdf->width - 1)
                line_algorithm(fdf, set_coords(x, y, fdf), set_coords(x + 1, y, fdf));
            if (y < fdf->height - 1)
                line_algorithm(fdf, set_coords(x, y, fdf), set_coords(x, y + 1, fdf));
            x++;
        }
        y++;
    }
}