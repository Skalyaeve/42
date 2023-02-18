/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:33:18 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/04 16:12:45 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	check_row(int i, int j, int k, int count)
{
	int	x;

	while (i - ++k >= 0)
	{
		x = 0;
		while ((data())->map.map[i - k][x] != -1)
			x++;
		if (x < j || (data())->map.map[i - k][j] == 0)
			break ;
		if ((data())->map.map[i - k][j] == 2 && ++count)
			break ;
	}
	k = 0;
	while ((data())->map.map[i + ++k])
	{
		x = 0;
		while ((data())->map.map[i + k][x] != -1)
			x++;
		if (x < j || (data())->map.map[i + k][j] == 0)
			break ;
		if ((data())->map.map[i + k][j] == 2 && ++count)
			break ;
	}
	return ((count == 2));
}

int	check_line(int i, int j, int k, int count)
{
	while (j - ++k >= 0
		&& (data())->map.map[i][j - k] != 0)
		if ((data())->map.map[i][j - k] == 2 && ++count)
			break ;
	k = 0;
	while ((data())->map.map[i][j + ++k] != -1
		&& (data())->map.map[i][j + k] != 0)
		if ((data())->map.map[i][j + k] == 2 && ++count)
			break ;
	return ((count == 2));
}

int	check_map_walls(int i, int j)
{
	while ((data())->map.map[++i])
	{
		j = -1;
		while ((data())->map.map[i][++j] != -1)
		{
			if ((data())->map.map[i][j] == 1 || (data())->map.map[i][j] == 4
				|| (data())->map.map[i][j] == 5 || (data())->map.map[i][j] == 6
				|| (data())->map.map[i][j] == 8)
			{
				if (!check_row(i, j, 0, 0))
					return (0);
				if (!check_line(i, j, 0, 0))
					return (0);
			}
		}
	}
	return (1);
}

int	check_missing_value(int i, int j, int count)
{
	int	finded[3];

	finded[0] = 0;
	finded[1] = 0;
	finded[2] = 0;
	while ((data())->map.map[++i])
	{
		j = -1;
		while ((data())->map.map[i][++j] != -1)
		{
			if ((data())->map.map[i][j] == 1 && !finded[0] && ++count)
				finded[0] = 1;
			if ((data())->map.map[i][j] == 2 && !finded[1] && ++count)
				finded[1] = 1;
			if (((data())->map.map[i][j] == 8 || (data())->map.map[i][j] == 6
				|| (data())->map.map[i][j] == 4 || (data())->map.map[i][j] == 5)
				&& ++count)
				finded[2] = 1;
		}
	}
	if (!finded[1] || !finded[2])
		return (0);
	return (count);
}

int	check_map_infos(void)
{
	int	e_count;

	e_count = check_missing_value(-1, -1, 0);
	if (e_count != 2 && e_count != 3
		&& ft_putstr_fd("Error\nWrong map syntax\n", 2))
		return (0);
	if (!check_map_walls(-1, -1)
		&& ft_putstr_fd("Error\nWalls don't cover the map\n", 2))
		return (0);
	return (1);
}
