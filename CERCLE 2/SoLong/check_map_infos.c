/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:59:25 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/05 22:44:25 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_last_wall(t_map *map_infos, int size, int len, int *i)
{
	int	j;

	j = 1;
	while (*i - j > 0 && map_infos->map_struct[*i - j] != '\n')
	{
		if (map_infos->map_struct[*i - j] != '1')
			return (0);
		j++;
	}
	map_infos->map_size = size;
	map_infos->map_len = len;
	*i -= 1;
	return (1);
}

int	check_map_walls(t_map *map_infos, int size, int len, int i)
{
	int	j;

	while (++i >= 0 && map_infos->map_struct[i]
		&& map_infos->map_struct[i] != '\n' && ++len)
		if (map_infos->map_struct[i] != '1')
			return (0);
	if (!map_infos->map_struct[i] || !map_infos->map_struct[i + 1])
		return (0);
	while (map_infos->map_struct[++i] && ++size)
	{
		if (map_infos->map_struct[i] != '1')
			return (0);
		j = 0;
		while (map_infos->map_struct[i + j]
			&& map_infos->map_struct[i + j] != '\n')
			j++;
		if (j != len)
			return (0);
		i += j;
		if (!map_infos->map_struct[i]
			&& !check_last_wall(map_infos, size, len, &i))
			return (0);
	}
	return (1);
}

int	check_map_infos(t_map *map_infos, int p, int e, int c)
{
	int	i;

	i = -1;
	while (map_infos->map_struct[++i])
	{
		if (map_infos->map_struct[i] != '0'
			&& map_infos->map_struct[i] != '1'
			&& map_infos->map_struct[i] != 'C'
			&& map_infos->map_struct[i] != 'E'
			&& map_infos->map_struct[i] != 'P'
			&& map_infos->map_struct[i] != '\n')
			return (map_error("MAP : Bad synthax", map_infos));
		if (map_infos->map_struct[i] == 'P')
			p++;
		if (map_infos->map_struct[i] == 'C')
			c++;
		if (map_infos->map_struct[i] == 'E')
			e++;
	}
	if (p != 1 || e < 1 || c < 1 || !check_map_walls(map_infos, 0, 0, -1))
		return (map_error("MAP : Bad synthax", map_infos));
	return (create_map_tab(-1, 0, map_infos->map_struct, map_infos));
}
