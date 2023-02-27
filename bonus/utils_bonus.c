/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:54:23 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 14:46:04 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf_bonus.h"

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

void	check_map(char *argv)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	str = ".fdf";
	tmp = ft_strnstr(argv, str, ft_strlen(argv));
	if (tmp == NULL)
	{
		ft_putendl_fd("Invalid Map Archive", 1);
		exit(0);
	}
}

void	free_split(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		free(split_line[i]);
		i++;
	}
	free(split_line);
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
