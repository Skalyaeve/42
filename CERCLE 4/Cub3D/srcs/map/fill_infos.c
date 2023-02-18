/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:59:52 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/04 18:23:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	get_colors(char *str, int *i, int l, char ref)
{
	int		colors[3];
	char	color[4];
	int		k;

	while (str[*i + 1] && str[*i + 1] == ' ')
		(*i)++;
	while (str[*i] && str[*i] != '\n' && str[++(*i)])
	{
		if (!ft_isdigit(str[*i]) && !ft_ischarset(" ,", str[*i])
			&& ft_putstr_fd("Error\nInvalid colors\n", 2))
			return (0);
		if (ft_isdigit(str[*i]))
		{
			k = 0;
			while (str[*i] && ft_isdigit(str[*i]) && k < 3)
				color[k++] = str[(*i)++];
			color[k] = '\0';
			if (str[*i] && (!ft_ischarset(" ,\n", str[*i]) || l >= 3)
				&& ft_putstr_fd("Error\nInvalid colors\n", 2))
				return (0);
			colors[++l] = ft_atoi(color);
		}
	}
	return (fill_colors(l, ref, colors));
}

int	get_map_infos(char *str, int *i, int j, int offset)
{
	if ((data())->map.map_infos
		&& ft_putstr_fd("Error\nWrong map syntax\n", 2))
		return (0);
	while (*i + j >= 0 && str[*i + j] != '\n')
		j--;
	if (*i + j == 0 && ft_putstr_fd("Error\nMap pattern should be last\n", 2))
		return (0);
	if (str[*i + j] == '\n')
		j++;
	offset = j;
	while (str[*i + j + offset])
		j++;
	(data())->map.map_infos = malloc(sizeof(char) * (j + 1));
	if (!(data())->map.map_infos && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	j = 0;
	while (str[*i + j + offset])
	{
		(data())->map.map_infos[j] = str[*i + j + offset];
		j++;
	}
	(data())->map.map_infos[j] = str[*i + j + offset];
	*i += j + offset;
	return (1);
}

int	texture_path_finded(char *str, int *i, char ref)
{
	char		*path;
	int			j;

	*i += 2;
	j = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	while (str[*i + j] && str[*i + j] != '\n')
		j++;
	path = malloc(sizeof(char *) * (j + 1));
	if (!path && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (0);
	j = -1;
	while (str[*i + ++j] && str[*i + j] != '\n')
		path[j] = str[*i + j];
	path[j] = '\0';
	(data())->ret = upload_textures(ref, path);
	free(path);
	*i += j;
	return ((data())->ret);
}

int	fill_map_struct_bis(char *str, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == 'F' && str[*i + 1] == ' '
		&& ++(*i) && !get_colors(str, i, -1, 'f'))
		return (0);
	if (str[*i] && str[*i + 1] && str[*i] == 'C' && str[*i + 1] == ' '
		&& ++(*i) && !get_colors(str, i, -1, 'c'))
		return (0);
	if (str[*i] && (str[*i] == '1' || str[*i] == '0' || str[*i] == 'N'
			|| str[*i] == 'S' || str[*i] == 'E' || str[*i] == 'W'))
		if (!get_map_infos(str, i, 0, 0))
			return (0);
	if (str[*i] && str[*i] != ' ' && str[*i] != '\n'
		&& ft_putstr_fd("Error\nUnknow key\n", 2))
		return (0);
	return (1);
}

int	fill_map_struct(char *str, int i)
{
	while (str[i])
	{
		if (str[i + 1] && str[i + 2]
			&& str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' '
			&& !texture_path_finded(str, &i, 'n'))
			return (0);
		if (str[i] && str[i + 1] && str[i + 2]
			&& str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' '
			&& !texture_path_finded(str, &i, 's'))
			return (0);
		if (str[i] && str[i + 1] && str[i + 2]
			&& str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' '
			&& !texture_path_finded(str, &i, 'e'))
			return (0);
		if (str[i] && str[i + 1] && str[i + 2]
			&& str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' '
			&& !texture_path_finded(str, &i, 'w'))
			return (0);
		if (!fill_map_struct_bis(str, &i))
			return (0);
		if (str[i])
			i++;
	}
	return (create_2d_map(-1, 0, 0, 0));
}
