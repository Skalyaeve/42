/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:00:54 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/04 20:35:23 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_mlx(t_mlx *mlx)
{
	free_map_infos(mlx->map_infos);
	free_sprites(mlx, mlx->wall_sprite);
	free_sprites(mlx, mlx->exit_sprite);
	free_sprites(mlx, mlx->col_sprite[0]);
	free_sprites(mlx, mlx->col_sprite[1]);
	free_sprites(mlx, mlx->col_sprite[2]);
	free_sprites(mlx, mlx->floor_sprite);
	free_sprites(mlx, mlx->char_static_sprite[0]);
	free_sprites(mlx, mlx->char_static_sprite[1]);
	free_sprites(mlx, mlx->char_static_sprite[2]);
	free_sprites(mlx, mlx->char_static_sprite[3]);
	free_sprites(mlx, mlx->char_static_sprite[4]);
	free_col(mlx->col, mlx->col_nbr);
}

int	keyrelease_hook_bis(int keycode, t_mlx *mlx)
{
	if (keycode == 115)
		if (mlx->x < mlx->map_infos->map_size
			&& mlx->map_infos->map_tab[mlx->x + 1][mlx->y] != 1
			&& ++mlx->moves && ++mlx->redraw)
			mlx->x += 1;
	if (keycode == 97)
		if (mlx->y > 0 && mlx->map_infos->map_tab[mlx->x][mlx->y - 1] != 1
			&& ++mlx->moves && ++mlx->redraw)
			mlx->y -= 1;
	if (keycode == 100)
		if (mlx->y < mlx->map_infos->map_len - 1
			&& mlx->map_infos->map_tab[mlx->x][mlx->y + 1] != 1
			&& ++mlx->moves && ++mlx->redraw)
			mlx->y += 1;
	if (mlx->y < mlx->old_y)
		mlx->dir = 1;
	else if (mlx->y > mlx->old_y)
		mlx->dir = 0;
	return (0);
}

int	keyrelease_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		if (mlx)
		{
			mlx_destroy_window(mlx->ptr, mlx->win);
			free_mlx(mlx);
			exit(0);
		}
	}
	if (keycode == 119)
		if (mlx->x > 0 && mlx->map_infos->map_tab[mlx->x - 1][mlx->y] != 1
			&& ++mlx->moves && ++mlx->redraw)
			mlx->x -= 1;
	return (keyrelease_hook_bis(keycode, mlx));
}
