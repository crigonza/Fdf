/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:56:46 by crigonza          #+#    #+#             */
/*   Updated: 2023/04/19 19:33:19 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_width(char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 1;
	if (line[i] == ' ')
		i++;
	while (line[i] != '\n')
	{
		if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != '\n')
			width++;
		i++;
	}
	return (width);
}

int	get_height(char *file)
{
	char	c;
	int		res;
	int		fd;
	int		height;

	height = -1;
	res = 1;
	fd = open(file, O_RDONLY);
	while (res > 0)
	{
		res = read(fd, &c, 1);
		if (c == '\n')
			height++;
	}
	close(fd);
	return (height);
}

int	**allocate_map(int height, int width)
{
	int	**tmp;
	int	i;

	i = 0;
	tmp = ft_calloc(height, sizeof(int *));
	if (!tmp)
		return (0);
	while (i < height)
	{
		tmp[i] = ft_calloc(width, sizeof(int));
		if (!tmp[i])
			return (0);
		i++;
	}
	return (tmp);
}

void	split_to_map(t_fdf *fdf, char **split_line, int i)
{
	int	j;

	j = 0;
	while (split_line[j])
	{
		fdf->map[i][j] = ft_atoi(split_line[j]);
		j++;
	}
	free_split(split_line);
}

void	parser(t_fdf *fdf, char *file, int fd)
{
	char	*map_line;
	char	**split_line;
	int		i;

	i = -1;
	fdf->width = 0;
	fdf->height = get_height(file);
	while (++i < fdf->height)
	{
		if(fdf->height == 100 && i == 99)
			break;
		map_line = get_next_line(fd);
		if (fdf->width == 0)
		{
			fdf->width = get_width(map_line);
			fdf->map = allocate_map(fdf->height, fdf->width);
		}
		split_line = ft_split(map_line, ' ');
		split_to_map(fdf, split_line, i);
		free(map_line);
	}
	close(fd);
}
