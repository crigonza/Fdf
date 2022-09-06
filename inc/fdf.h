/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:40:19 by crigonza          #+#    #+#             */
/*   Updated: 2022/08/12 18:06:41 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"
#include "../GNL/get_next_line.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define WIN_H 1080
#define WIN_W 1920

typedef struct s_coords
{
    int     x;
    int     Y;
}t_coords;

typedef struct s_fdf
{
    int        **map;
    int         height;
    int         width;
    int         color;
    void        *mlx;
    void        *window;
    void        *image;
}   t_fdf;




#endif