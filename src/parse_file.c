/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:56:46 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/23 18:51:55 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_width(char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		width;

	i = 0;
	width = 1;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line[i] == ' ')
		i++;
	while (line[i] != '\n')
	{
		if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != '\n')
			width++;
		i++;
	}
	free(line);
	close(fd);
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

void	parser(t_fdf *fdf, char *file)
{
	char *map_line;
	char **split_line;
	int i;
	int j;
	int fd;

	fdf->width = get_width(file);
	fdf->height = get_height(file);
	fdf->map = allocate_map(fdf->height, fdf->width);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		map_line = get_next_line(fd);
		split_line = ft_split(map_line, ' ');
		j = 0;
		while (split_line[j])
		{
			fdf->map[i][j] = ft_atoi(split_line[j]);
			//printf("%d||", fdf->map[i][j]);
			j++;
		}
		//printf("\n");
		i++;
		free(map_line);
		free(split_line);
	}
	close(fd);
}