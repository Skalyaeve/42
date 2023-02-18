/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:01:44 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/27 01:19:59 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	upload_char_bis(t_mlx *mlx)
{
	if (!assign_sprites(&mlx->char_static_sprite[3]
			, "sprites/char/static/static03.xpm", mlx)
		|| !reversed_char(mlx->char_static_sprite[3],
			&mlx->char_static_sprite[8], 0, mlx))
		return (0);
	if (!assign_sprites(&mlx->char_static_sprite[4]
			, "sprites/char/static/static04.xpm", mlx)
		|| !reversed_char(mlx->char_static_sprite[4],
			&mlx->char_static_sprite[9], 0, mlx))
		return (0);
	return (1);
}

int	upload_char(t_mlx *mlx)
{	
	if (!assign_sprites(&mlx->char_static_sprite[0]
			, "sprites/char/static/static00.xpm", mlx)
		|| !reversed_char(mlx->char_static_sprite[0],
			&mlx->char_static_sprite[5], 0, mlx))
		return (0);
	if (!assign_sprites(&mlx->char_static_sprite[1]
			, "sprites/char/static/static01.xpm", mlx)
		|| !reversed_char(mlx->char_static_sprite[1],
			&mlx->char_static_sprite[6], 0, mlx))
		return (0);
	if (!assign_sprites(&mlx->char_static_sprite[2]
			, "sprites/char/static/static02.xpm", mlx)
		|| !reversed_char(mlx->char_static_sprite[2],
			&mlx->char_static_sprite[7], 0, mlx))
		return (0);
	return (upload_char_bis(mlx));
}

int	upload_col(t_mlx *mlx)
{
	if (!assign_sprites(&mlx->col_sprite[0]
			, "sprites/collectible00.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->col_sprite[1]
			, "sprites/collectible01.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->col_sprite[2]
			, "sprites/collectible02.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->col_sprite[3]
			, "sprites/collectible03.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->col_sprite[4]
			, "sprites/collectible04.xpm", mlx))
		return (0);
	return (upload_char(mlx));
}

int	upload_sprites(t_mlx *mlx)
{
	mlx->char_static_sprite = malloc(sizeof(t_sprite *) * 10);
	if (!mlx->char_static_sprite)
		return (0);
	mlx->col_sprite = malloc(sizeof(t_sprite *) * 5);
	if (!mlx->col_sprite)
		return (0);
	if (!assign_sprites(&mlx->wall_sprite, "sprites/wall.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->exit_sprite, "sprites/exit.xpm", mlx))
		return (0);
	if (!assign_sprites(&mlx->floor_sprite, "sprites/floor.xpm", mlx))
		return (0);
	return (upload_col(mlx));
}
