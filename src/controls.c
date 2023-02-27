/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crigonza <crigonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:12:34 by crigonza          #+#    #+#             */
/*   Updated: 2023/02/27 08:53:19 by crigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_color(t_fdf *fdf)
{
	if (fdf->ncolor == 0)
		fdf->ncolor = 1;
	else if (fdf->ncolor == 1)
		fdf->ncolor = 0;
}

void	control_keys1(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
}
