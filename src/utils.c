/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:54:23 by crigonza          #+#    #+#             */
/*   Updated: 2023/04/27 10:37:55 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_points(int x, int x2)
{
	if (x < x2)
		return (1);
	else if (x > x2)
		return (-1);
}

int	abs_val(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	check_map(char *argv, int argc)
{
	char	*tmp;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	str = ".fdf";
	if (argc != 2)
	{
		ft_putendl_fd("Invalid arguments number", 2);
		return (-1);
	}
	tmp = ft_strnstr(argv, str, ft_strlen(argv));
	if (tmp == NULL)
	{
		ft_putendl_fd("Invalid Map Archive", 1);
		return (-1);
	}
	return (0);
}

void	free_split(char **split_line)
{
	int	i;

	i = 0;
	if (split_line != NULL)
	{
		while (split_line[i])
		{
			free(split_line[i]);
			i++;
		}
		free(split_line);
	}
}

t_coords	set_coords(int x, int y, t_fdf *fdf)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	if (fdf->width < 80 && fdf->width > 4)
	{
		if (fdf->map[4][4] > 20 || fdf->map[1][0] > 20)
			coords.z = fdf->map[y][x];
		else
			coords.z = fdf->map[y][x] * 8;
	}
	else
		coords.z = fdf->map[y][x];
	coords.color = get_color(&coords, fdf);
	return (coords);
}
