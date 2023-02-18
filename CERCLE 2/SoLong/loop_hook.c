/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:01:03 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/07 16:40:18 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		if (n == -2147483648)
		{
			c = '2';
			write(fd, &c, 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = 48 + (n % 10);
	write(fd, &c, 1);
}

int	game_end(t_mlx *mlx)
{
	put_images(mlx->x, mlx->y, mlx, mlx->exit_sprite);
	mlx->end = 1;
	if (mlx->pts == mlx->col_nbr)
	{
		putstr_fd("Bien joué, t'as tous chopé et atteind la sortie en ", 1);
		putnbr_fd(mlx->moves, 1);
		putstr_fd(" déplacements !\n", 1);
	}
	else
		putstr_fd("T'as pas tous chopé, recommence !\n", 1);
	return (0);
}

int	redraw(t_mlx *mlx, int i)
{
	put_images(mlx->x, mlx->y, mlx,
		mlx->char_static_sprite[mlx->phase + 5 * mlx->dir]);
	put_images(mlx->old_x, mlx->old_y, mlx,
		mlx->floor_sprite);
	mlx->old_x = mlx->x;
	mlx->old_y = mlx->y;
	mlx->redraw = 0;
	while (++i < mlx->col_nbr)
		if (mlx->col[i]->x == mlx->x && mlx->col[i]->y == mlx->y
			&& mlx->col[i]->alive && ++mlx->pts)
			mlx->col[i]->alive = 0;
	if (mlx->x == mlx->escape_x && mlx->y == mlx->escape_y)
		return (game_end(mlx));
	putnbr_fd(mlx->moves, 1);
	putstr_fd("\n", 1);
	return (1);
}

void	check_frame(t_mlx *mlx, int i)
{
	if (mlx->frame >= 7500)
	{
		put_images(mlx->x, mlx->y, mlx,
			mlx->char_static_sprite[mlx->phase + 5 * mlx->dir]);
		while (++i < mlx->col_nbr)
			if (mlx->col[i]->alive)
				put_images(mlx->col[i]->x, mlx->col[i]->y, mlx,
					mlx->col_sprite[mlx->phase]);
	}
	if (mlx->frame >= 7500 && ++mlx->phase)
		mlx->frame = 0;
	if (mlx->phase == 4)
		mlx->phase = 0;
}

int	loop_hook(t_mlx *mlx)
{
	int	i;

	i = -1;
	if (!mlx->end)
	{
		if (!mlx->started)
			if (!start(mlx, -1, -1))
				return (0);
		mlx->started = 1;
		mlx->frame++;
		if (mlx->redraw && !redraw(mlx, i))
			return (1);
		check_frame(mlx, i);
	}
	else
		exit (EXIT_SUCCESS);
	return (1);
}
