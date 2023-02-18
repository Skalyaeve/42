/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:03:10 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/05 18:03:10 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_map_infos(t_map *map_infos)
{
	if (map_infos)
	{
		if (map_infos->map_struct)
			free(map_infos->map_struct);
		if (map_infos->map_tab)
			free_map_tab(map_infos->map_size, map_infos->map_tab);
		map_infos->map_struct = NULL;
	}
	return (0);
}

int	map_error(char *str, t_map *map_infos)
{
	putstr_fd("Error\n", 1);
	putstr_fd(str, 1);
	putstr_fd("\n", 1);
	if (map_infos)
	{
		if (map_infos->map_struct)
			free(map_infos->map_struct);
		if (map_infos->map_tab)
			free_map_tab(map_infos->map_size, map_infos->map_tab);
		map_infos->map_struct = NULL;
	}
	return (0);
}
