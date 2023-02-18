/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:01:24 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/07 16:27:08 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_sprites(t_mlx *mlx, t_sprite *sprite)
{
	mlx_destroy_image(mlx->ptr, sprite->ptr);
	if (sprite)
	{
		free(sprite);
		sprite = NULL;
	}
	return (0);
}

void	get_res(t_mlx *mlx)
{
	mlx->width = mlx->map_infos->map_len * 100;
	mlx->height = mlx->map_infos->map_size * 100;
}

int	init_mlx(t_mlx *mlx, t_map *map_infos)
{
	mlx->map_infos = map_infos;
	get_res(mlx);
	mlx->started = 0;
	mlx->redraw = 0;
	mlx->frame = 7499;
	mlx->pts = 0;
	mlx->end = 0;
	mlx->moves = 0;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "SoLong");
	mlx->x_draw_offset = 100
		/ (mlx->width / (double)map_infos->map_len);
	mlx->y_draw_offset = 100
		/ (mlx->height / (double)map_infos->map_size);
	mlx->x_case_len = mlx->width / map_infos->map_len;
	mlx->y_case_len = mlx->height / map_infos->map_size;
	if (!upload_sprites(mlx))
		return (system_error("SPRITES : Upload failed", mlx));
	return (1);
}
