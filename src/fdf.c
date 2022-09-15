/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/15 08:10:51 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void    map_error(void)
{
    ft_putendl_fd("Invalid Map", 1);
    exit(0);
}

int **malloc_map(int width, int height)
{
    int i;
    int **array;

    i = 0;
    array = (int*)malloc(sizeof(int) * height);
    if (!array)
        return(0);
    while(i < height)
    {
        array[i] = (int*)malloc(sizeof(int) * width);
        if (!array[i])
            return (0);
        i++;
    }
    return (array);
}

int get_width(char *file)
{
    char    *line;
    int fd;
    int i;
    int width;

    i = 0;
    width = 1;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while(line[i] != '\n')
    {
        if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1] != '\n')
            width++;
        i++;
    }
    free(line);
    close(fd);
    return(width);
}

int get_height(char *file)
{
    char    c;
    int res;
    int fd;
    int height;

    height = -1;
    res = 1;
    fd = open(file, O_RDONLY);
    while(res > 0)
    {
        res = read(fd, &c, 1);
        if (c == '\n')
            height++;
    }
    close(fd);
    return(height);
}

int	**alloc_map(int height, int width)
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
		{
			return (0);
		}
		i++;
	}
	return (tmp);
}

void    parser(t_fdf *fdf, char *file)
{
    char    *map_line;
    char    **split_line;
    int     i;
    int     j;
    int     fd;
    
    fdf->width = get_width(file);
    fdf->height = get_height(file);
    fdf->map = alloc_map(fdf->height, fdf->width);
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < fdf->height)
    {
        j = 0;
        map_line = get_next_line(fd);
        //printf("%s", map_line);
        split_line = ft_split(map_line, ' ');
        /* while (split_line[j])
        {
            printf("%s", split_line[j]);
            j++;
        } */
        //printf("\n");
        j = 0;
        while (split_line[j])
        {
            fdf->map[i][j] = ft_atoi(split_line[j]);
            j++;
        }
        i++; 
        free(map_line);
        free(split_line);
    }
    close (fd);
}

t_coords    set_coords(int x, int y)
{
    t_coords    coords;

    coords.x = x;
    coords.y = y;
    return (coords);
}

void    parallel_view(t_coords *coords, int z)
{
    //printf ("x = %d || y = %d", coords->x, coords->y);
    if (z != 0)
    {
        coords->x = (int)round((coords->x) * cos(M_PI / 4));
        coords->y = (int)round((coords->y) * sin(M_PI / 4));
    }
}

void    isometric_view(t_coords *coords, int z)
{
    coords->x = (int)round((coords->x - coords->y) * cos(M_PI / 4));
    coords->y = (int)round((coords->x + coords->y) * sin(M_PI / 6) + z);
}

void    set_point(t_coords *pt1, t_coords *pt2, t_fdf *fdf)
{
    int scale_w;
    int shiftx;
    int shifty;
    int z1;
    int z2;

    z1 = fdf->map[pt1->y][pt1->x];
    z2 = fdf->map[pt2->y][pt2->x];
    scale_w = WIN_W / (fdf->height * 1.5);
    shiftx = WIN_H / 4;
    shifty = WIN_W / 4;
    pt1->x = (pt1->x * scale_w); //+ scale_w * 4;
    pt1->y = (pt1->y * scale_w); //+ scale_h * 2;
    pt2->x = (pt2->x * scale_w); //+ scale_w * 4;
    pt2->y = (pt2->y * scale_w); //+ scale_h * 2;
    isometric_view(pt1, z1);
    isometric_view(pt2, z2);
    /* parallel_view(pt1, z1);
    parallel_view(pt2, z2); */
    /* pt1->x = (pt1->x + shiftx);
    pt1->y = (pt1->y + shifty);
    pt2->x = (pt2->x + shiftx);
    pt1->y = (pt1->y + shifty); */

}

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
    //mlx_put_pixel(fdf->img, pt1.x, pt1.y, 0xFFFFFFFF);
    while (pt1.x != pt2.x || pt1.y != pt2.y)
    {
        mlx_put_pixel(fdf->img, pt1.x, pt1.y, 0xFFFFFFFF);
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

    y = 0;
    while (y < fdf->height)
    {
        x = 0;
        while (x < fdf->width)
        {
            if (x < fdf->width - 1)
                line_algorithm(fdf, set_coords(x, y), set_coords(x + 1, y));
            if (y < fdf->height - 1)
                line_algorithm(fdf, set_coords(x, y), set_coords(x, y + 1));
            x++;
        }
        y++;
    }
}

int main(int argc, char **argv)
{
    t_fdf *fdf;
    //mlx_image_t *fdf->img;
    int i = 0;
    int j = 0;

    fdf = (t_fdf*)malloc(sizeof(t_fdf));
    if (argc != 2)
    {
        ft_putendl_fd("Invalid arguments number", 2);
        exit(0);
    }
    parser(fdf, argv[1]);
    printf("%d\n", fdf->width);
    printf("%d\n", fdf->height);
    fdf->mlx = mlx_init(WIN_W, WIN_H, "Fdf", true);
    fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
    mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
    /* while (i < fdf->height)
    {
        j = 0;
        while(j < fdf->width)
        {
            mlx_put_pixel(fdf->img, (WIN_W /fdf->width) * j ,(WIN_H / fdf->height) * i, 0xFFFFFFFF);
            j++;
        }
        i++;
    } */
    
    draw_lines(fdf);
    //line_algorithm(fdf, set_coords(1, 1), set_coords(1, 2));
    mlx_loop(fdf->mlx);
    /* while (i < fdf->height)
    {
        j = 0;
        while (j < fdf->width)
        {
            printf("%d ", fdf->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    } */
    return(0);
}