/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:57:47 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/27 06:57:47 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_col(t_col **col, int size)
{
	if (col)
	{
		while (--size >= 0)
		{
			free(col[size]);
			col[size] = NULL;
		}
		free(col);
		col = NULL;
	}
	return (0);
}

int	assign_col(t_mlx *mlx, int i, int j, int size)
{
	while (++i < mlx->map_infos->map_size)
	{	
		j = -1;
		while (++j < mlx->map_infos->map_len)
		{
			if (mlx->map_infos->map_tab[i][j] == 3)
			{
				mlx->col[--size] = malloc(sizeof(t_col));
				if (!mlx->col[size])
					return (system_error("MALLOC", mlx));
				mlx->col[size]->x = i;
				mlx->col[size]->y = j;
				mlx->col[size]->alive = 1;
			}
		}
	}
	return (1);
}

void	launch_hero(int i, int j, t_mlx *mlx)
{
	mlx->x = i;
	mlx->old_x = i;
	mlx->y = j;
	mlx->old_y = j;
	mlx->dir = 0;
	mlx->phase = 0;
	if (mlx->y > mlx->map_infos->map_len)
		mlx->dir = 1;
}

int	start(t_mlx *mlx, int i, int j)
{
	int	col_count;

	col_count = 0;
	while (++i < mlx->map_infos->map_size)
	{	
		j = -1;
		while (++j < mlx->map_infos->map_len)
		{
			if (mlx->map_infos->map_tab[i][j] == 2)
				launch_hero(i, j, mlx);
			if (mlx->map_infos->map_tab[i][j] == 3)
				col_count++;
			if (mlx->map_infos->map_tab[i][j] == 4)
			{
				mlx->escape_x = i;
				mlx->escape_y = j;
			}
		}
	}
	mlx->col = malloc(sizeof(t_col *) * col_count);
	mlx->col_nbr = col_count;
	if (!mlx->col)
		return (system_error("MALLOC", mlx));
	return (assign_col(mlx, -1, -1, col_count));
}
