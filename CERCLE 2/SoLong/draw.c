/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:18:52 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/07 16:37:04 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_images(int i, int j, t_mlx *mlx, t_sprite *sprite)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, sprite->ptr,
		j * mlx->x_case_len, i * mlx->y_case_len);
}

void	draw(int i, int j, t_mlx *mlx)
{
	while (++i < mlx->map_infos->map_size)
	{
		while (++j < mlx->map_infos->map_len)
		{
			if (mlx->map_infos->map_tab[i][j] == 0
				|| mlx->map_infos->map_tab[i][j] == 2
				|| mlx->map_infos->map_tab[i][j] == 3)
				put_images(i, j, mlx, mlx->floor_sprite);
			if (mlx->map_infos->map_tab[i][j] == 1)
				put_images(i, j, mlx, mlx->wall_sprite);
			if (mlx->map_infos->map_tab[i][j] == 4)
				put_images(i, j, mlx, mlx->exit_sprite);
		}
		j = -1;
	}
}
