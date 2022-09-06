/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:25:36 by crigonza          #+#    #+#             */
/*   Updated: 2022/09/06 18:01:53 by crigonza         ###   ########.fr       */
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
    width = 0;
    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    while(line[i] != '\n')
    {
        if (line[i] != ' ')
            width++;
        i++;
    }
    free(line);
    close(fd);
    return(width);
}

int get_height(char *file)
{
    char    *line;
    int fd;
    int height;

    height = 0;
    fd = open(file, O_RDONLY);
    while(line = get_next_line(fd))
    {
        free(line);
        height++;
    }
    free(line);
    close(fd);
    return(height);
}
void    parse_map(int *map_line, char **split_line)
{
    int i;

    i = 0;
    while(split_line[i])
    {
        map_line[i] = ft_atoi(split_line[i]);
        i++;
    }
}

void    parser(t_fdf *fdf, char *file)
{
    char    *map_line;
    char    **split_line;
    //int     **map;
    int     i;
    int     j;
    int     fd;
    
    fdf->width = get_width(file);
    fdf->height = get_height(file);
    fdf->map = malloc(sizeof(int) * (fdf->height * fdf->width));
    fd = open(file, O_RDONLY);
    i = 0;
    //map = malloc(sizeof(int) * (fdf->height * fdf->width));
    while (i < fdf->height)
    {
        j = 0;
        map_line = get_next_line(fd);
        split_line = ft_split(map_line, ' ');
        while (j < fdf->width)
        {
            fdf->map[i][j] = ft_atoi(split_line[j]);
            //free(split_line[j]);
            //printf("-%d", ft_atoi(split_line[j]));
            j++;
        }
        //printf("\n");
        //parse_map(fdf->map[i], split_line);
        i++; 
        free(map_line);
        free(split_line);
    }
    //free(map_line);
    close (fd);
}

int main(int argc, char **argv)
{
    t_fdf *fdf;
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
    //fdf->map[0][0] = 1992;
   /*  while (i < 11)
    {
        j = 0;
        while (j < 19)
        {
            printf("%d ", fdf->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    } */
    return(0);
}