/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:59:36 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/27 05:58:37 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_map_tab(int size, int **map_tab)
{
	if (map_tab)
	{
		while (--size >= 0)
		{
			if (map_tab[size])
			{
				free(map_tab[size]);
				map_tab[size] = NULL;
			}
		}
		free(map_tab);
		map_tab = NULL;
	}
	return (0);
}

int	return_it(int ***map_tab, t_map **map_infos)
{	
	(*map_infos)->map_tab = *map_tab;
	return (1);
}

int	fill_map_tab(int k, int **map_tab, char *str, t_map *map_infos)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			map_tab[j++][k] = -1;
		if (str[i] == '\n')
			k = 0;
		else if (str[i] == '1')
			map_tab[j][k++] = 1;
		else if (str[i] == '0')
			map_tab[j][k++] = 0;
		else if (str[i] == 'P')
			map_tab[j][k++] = 2;
		else if (str[i] == 'C')
			map_tab[j][k++] = 3;
		else if (str[i] == 'E')
			map_tab[j][k++] = 4;
	}
	if (str[i - 1] != '\n')
		map_tab[j][k] = -1;
	return (return_it(&map_tab, &map_infos));
}

int	create_map_tab_bis(int	***map_tab, int *size, char *str, t_map *map_infos)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] != '\0')
			(*size)++;
	*map_tab = malloc(sizeof(int *) * (*size + 1));
	if (!*map_tab && !free_map_infos(map_infos))
		return (system_error("MALLOC", NULL));
	return (0);
}

int	create_map_tab(int i, int size, char *str, t_map *map_infos)
{
	int	j;
	int	to_malloc;
	int	**map_tab;

	to_malloc = create_map_tab_bis(&map_tab, &size, str, map_infos);
	j = -1;
	while (str[++i] && j < size && ++to_malloc)
	{
		if (str[i] == '\n')
		{
			map_tab[++j] = malloc(sizeof(int) * to_malloc);
			if (!map_tab[j] && !free_map_infos(map_infos))
				return (system_error("MALLOC", NULL));
			to_malloc = 0;
		}
	}
	if (to_malloc != 0)
	{
		map_tab[++j] = malloc(sizeof(int) * (to_malloc + 1));
		if (!map_tab[j] && !free_map_infos(map_infos))
			return (system_error("MALLOC", NULL));
		to_malloc = 0;
	}
	map_infos->map_size = size + 1;
	return (fill_map_tab(0, map_tab, str, map_infos));
}
