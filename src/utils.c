/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:54:23 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/20 18:59:13 by crigonza         ###   ########.fr       */
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

