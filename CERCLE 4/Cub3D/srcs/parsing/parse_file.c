/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:48:08 by anguinau          #+#    #+#             */
/*   Updated: 2022/09/04 16:21:20 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	free_parsing_struct(t_parsing *start)
{
	t_parsing	*old;

	while (start)
	{
		old = start;
		start = start->next;
		free(old);
	}
	return (0);
}

int	join_letters(t_parsing *start, int i)
{
	char		*str;
	t_parsing	*index;

	if (!start->c)
	{
		ft_putstr_fd("Error\nEmpty config file\n", 2);
		return (0);
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str && ft_putstr_fd("Error\nMalloc failed\n", 2))
		return (free_parsing_struct(start->next));
	i = -1;
	index = start;
	while (index)
	{
		str[++i] = index->c;
		index = index->next;
	}
	free_parsing_struct(start->next);
	(data())->ret = fill_map_struct(str, 0);
	free(str);
	return ((data())->ret);
}

int	parse_file(char *path, int i, int fd, t_parsing *index)
{
	t_parsing	start;
	char		buffer[1];

	index = &start;
	fd = open(path, O_RDONLY);
	if (fd == -1 && ft_putstr_fd("Error\nCan't open config file\n", 2))
		return (0);
	while (read(fd, &buffer, 1))
	{
		i++;
		index->c = buffer[0];
		index->next = malloc(sizeof(t_parsing));
		if (!index->next && ft_putstr_fd("Error\nMalloc failed\n", 2))
		{
			close(fd);
			return (free_parsing_struct(start.next));
		}
		index = index->next;
	}
	close(fd);
	index->c = '\0';
	index->next = NULL;
	return (join_letters(&start, i));
}
