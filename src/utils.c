/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:54:23 by crigonza          #+#    #+#             */
/*   Updated: 2022/10/05 17:44:24 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int check_points(int x, int x2)
{
    if (x < x2)
        return (1);
    else if (x > x2)
        return (-1);
}

int abs_val(int num)
{
    if (num < 0)
        num *= -1;
    return (num);
}

void    map_error(void)
{
    ft_putendl_fd("Invalid Map", 1);
    exit(0);
}

t_coords	set_coords(int x, int y, t_fdf *fdf)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	coords.z = fdf->map[y][x];
	coords.color = get_color(&coords, fdf);
	return (coords);
}

