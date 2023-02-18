/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 02:01:15 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/04 11:11:16 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	putstr_fd(char *s, int fd)
{
	while (s && *s++)
		write(fd, (s - 1), 1);
}

int	close_it(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free_mlx(mlx);
	}
	exit(0);
	return (0);
}

int	system_error(char *step, t_mlx *mlx)
{
	putstr_fd("Error\n", 1);
	putstr_fd(step, 1);
	putstr_fd("\n", 1);
	if (mlx)
		free_mlx(mlx);
	return (0);
}

int	check_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	if (i < 5)
		return (0);
	if (input[i - 1] != 'r' || input[i - 2] != 'e'
		|| input[i - 3] != 'b' || input[i - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_mlx	mlx;
	t_map	map_infos;

	if (ac == 2 && check_input(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (system_error("OPEN", &mlx));
		if (!parsing(fd, &map_infos))
			return (-1);
		if (!init_mlx(&mlx, &map_infos))
			return (-1);
		mlx_hook(mlx.win, 33, 1L << 2, close_it, &mlx);
		mlx_hook(mlx.win, 3, 1L << 1, keyrelease_hook, &mlx);
		draw(-1, -1, &mlx);
		mlx_loop_hook(mlx.ptr, loop_hook, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		putstr_fd("Error\nINPUT : invalid argument, we want a .ber file\n", 1);
	return (0);
}
